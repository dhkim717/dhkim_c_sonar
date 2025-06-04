#include <stdio.h>
#include <string.h>

void vulnerableFunction() {
    char buffer[10];  // Fixed-size buffer of 10 bytes

    printf("Enter some text: ");
    gets(buffer);  // Unsafe function prone to buffer overflow
    printf("You entered: %s\n", buffer);
}

int main() {
    printf("Demonstrating a potential buffer overflow:\n");
    vulnerableFunction();
    return 0;
}
