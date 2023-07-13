#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main() {
    // Define the path to the FIFO file
    const char* fifo_path = "./tmp/my_fifo";
    // Create the FIFO file
    mkfifo(fifo_path, 0666);
    // Open the FIFO file for writing (O_WRONLY)
    int write_fd = open(fifo_path, O_WRONLY);
    // Open the FIFO file for reading (O_RDONLY)
    int read_fd = open(fifo_path, O_RDONLY);
    // Write data to the FIFO file
    const char* data = "Hello, FIFO!";
    write(write_fd, data, strlen(data));
    // Read data from the FIFO file
    char read_data[1024];
    read(read_fd, read_data, sizeof(read_data));
    printf("Received data: %s\n", read_data);
    // Close the file descriptors
    close(write_fd);
    close(read_fd);
    // Remove the FIFO file
    //unlink(fifo_path);
    return 0;
}
