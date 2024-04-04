#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <amqpcpp.h>
#include <amqpcpp/linux_tcp.h>
#include <chrono>
#include <thread>


int main() {
    try {
        // Establish connection to RabbitMQ server on localhost
        AMQP::TcpConnection connection(
            AMQP::Address("amqp://guest:guest@localhost:5672/")
        );

        // Create a channel
        AMQP::TcpChannel channel(&connection);

        // Declare a queue for receiving messages (if not already declared)
        channel.declareQueue("test_queue");

        // Publish a simple message to the queue
        std::string message = "Hello, RabbitMQ!";
        channel.publish("", "test_queue", message);

        std::cout << "Message published to test_queue in RabbitMQ" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}