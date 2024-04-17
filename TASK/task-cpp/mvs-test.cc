#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <amqpcpp.h>
#include <amqpcpp/linux_tcp.h>

using namespace std;

const string FCUD_PATH = "/usr/applications/fcud/files/";

class MyTcpHandler : public AMQP::TcpHandler {
public:
    virtual void onAttached(AMQP::TcpConnection *connection) override {
        cout << "TCP connection attached" << endl;
    }

    virtual void onError(AMQP::TcpConnection *connection, const char *message) override {
        cerr << "Error occurred: " << message << endl;
    }

    virtual void onReady(AMQP::TcpConnection *connection) override {
        cout << "TCP connection is ready" << endl;
    }

    virtual void monitor(AMQP::TcpConnection *connection, int fd, int flags) override {
        // Not used in this example, can be left empty
    }
};

void handleMessage(const AMQP::Message &message, uint64_t deliveryTag, AMQP::TcpChannel &channel) {
    try {
        // Parse XML message
        string msgBody(message.body(), message.bodySize());
        regex commandRegex("<Command>(Create|Delete|Update)</Command>");
        regex fileNameRegex("<FileName>([A-Za-z0-9]{1,32})</FileName>");
        regex contentRegex("<Content>([A-Za-z0-9]{0,64})</Content>");

        smatch match;
        string command, fileName, content;

        if (regex_search(msgBody, match, commandRegex)) {
            command = match.str(1);
        } else {
            cerr << "Error: Command not found in message" << endl;
            channel.reject(deliveryTag);
            return;
        }

        if (regex_search(msgBody, match, fileNameRegex)) {
            fileName = match.str(1);
        } else {
            cerr << "Error: FileName not found in message" << endl;
            channel.reject(deliveryTag);
            return;
        }

        if (regex_search(msgBody, match, contentRegex)) {
            content = match.str(1);
        }

        // Perform file operation based on the received command
        string filePath = FCUD_PATH + fileName;
        if (command == "Create" || command == "Update") {
            ofstream outputFile(filePath);
            if (outputFile.is_open()) {
                outputFile << content;
                outputFile.close();
                cout << "File '" << fileName << "' created/updated successfully" << endl;
            } else {
                cerr << "Error: Unable to open file '" << fileName << "' for writing" << endl;
            }
        } else if (command == "Delete") {
            if (filesystem::remove(filePath)) {
                cout << "File '" << fileName << "' deleted successfully" << endl;
            } else {
                cerr << "Error: Unable to delete file '" << fileName << "'" << endl;
            }
        } else {
            cerr << "Error: Invalid command '" << command << "'" << endl;
        }

        // Acknowledge message delivery
        channel.ack(deliveryTag);
    } catch (const exception &e) {
        cerr << "Error processing message: " << e.what() << endl;
    }
}

int main() {
    try {
        // Establish connection to RabbitMQ server on port 5672
        AMQP::Address address("amqp://guest:guest@localhost:5672");
        MyTcpHandler myHandler;
        AMQP::TcpConnection connection(&myHandler, address);
        AMQP::TcpChannel channel(&connection);

        // Declare a queue for receiving messages
        channel.declareQueue("fcud.input");
        channel.consume("fcud.input").onReceived([&](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered) {
            handleMessage(message, deliveryTag, channel);
        });

        // Run the event loop
        cout << "Waiting for messages..." << endl;
        channel.consume("fcud.input");
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
