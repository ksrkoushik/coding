
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <amqpcpp.h>
#include <amqpcpp/linux_tcp.h>
using namespace std;

int main() {
    try {
        // Connect to RabbitMQ server on port 5672
        //AMQP::Address address("localhost", 5672);
        //AMQP::TcpConnection connection(&address, AMQP::Login("guest", "guest"), "/");
        //AMQP::TcpConnection connection("localhost", 5672, AMQP::Login("guest", "guest"), "/");
        AMQP::Address address("amqp://guest:guest@localhost:5672");
        AMQP::TcpConnection connection(nullptr, address);
        AMQP::TcpChannel channel(&connection);

        // Declare a queue for receiving file operation requests
        channel.declareQueue("fcud.input");
        //channel.declareQueue("letterbox");
        // Publish a message to the fcud.input queue
        string message = "<Message>\n"
                         "   <Command>Create</Command>\n"
                         "   <FileName>Xyz.txt</FileName>\n"
                         "   <Content>Lorem Ipsum</Content>\n"
                         "</Message>";
        channel.publish("", "fcud.input", message);

        cout << "Message published to fcud.input queue" << endl;
    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

