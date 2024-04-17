#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <amqpcpp.h>
#include <amqpcpp/linux_tcp.h>
using namespace std;

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

int main() {
    try {
        // Connect to RabbitMQ server
        AMQP::Address address("amqp://guest:guest@localhost:5672");
        MyTcpHandler handler;
        AMQP::TcpConnection connection(&handler, address);
        AMQP::TcpChannel channel(&connection);

        // Declare a queue for receiving messages
        channel.declareQueue("fcud.input");

        // Publish a message to the queue
        string message = "<Message>\n"
                              "   <Command>Create</Command>\n"
                              "   <FileName>Xyz.txt</FileName>\n"
                              "   <Content>Lorem Ipsum</Content>\n"
                              "</Message>";
        channel.publish("", "fcud.input", message);

        cout << "Message published to fcud.input queue" << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
