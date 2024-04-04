#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <amqpcpp.h>
#include <amqpcpp/linux_tcp.h>

class MyTcpHandler : public AMQP::TcpHandler {
public:
    virtual void onAttached(AMQP::TcpConnection *connection) override {
        std::cout << "TCP connection attached" << std::endl;
    }

    virtual void onError(AMQP::TcpConnection *connection, const char *message) override {
        std::cerr << "Error occurred: " << message << std::endl;
    }

    virtual void onReady(AMQP::TcpConnection *connection) override {
        std::cout << "TCP connection is ready" << std::endl;
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
        std::string message = "<Message>\n"
                              "   <Command>Create</Command>\n"
                              "   <FileName>Xyz.txt</FileName>\n"
                              "   <Content>Lorem Ipsum</Content>\n"
                              "</Message>";
        channel.publish("", "fcud.input", message);

        std::cout << "Message published to fcud.input queue" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
