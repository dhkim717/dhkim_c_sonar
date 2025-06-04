#include <stdio.h>
#include <string.h>

void safeFunction() {
    char buffer[10];
    printf("Enter some text: ");
    fgets(buffer, sizeof(buffer), stdin);  // Limit input to buffer size
    printf("You entered: %s\n", buffer);
}

int main() {
    printf("Demonstrating a potential buffer overflow:\n");
    safeFunction();
    return 0;
}

