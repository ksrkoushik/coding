#include <stdio.h>

int main() {
    char buffer[1024];
    char *name = "John";
    int age = 30;

    sprintf(buffer, "My name is %s and I am %d years old.", name, age);
    printf("%s\n", buffer);

    return 0;
}
