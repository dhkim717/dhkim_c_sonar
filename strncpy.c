#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, GitHub!";
    char destination[50];  // Make sure the destination has enough space

    // Copy the string from source to destination using strncpy
    strncpy(destination, source, sizeof(destination) - 1);
    destination[sizeof(destination) - 1] = '\0';  // Ensure null-termination

    // Get the length of the copied string
    int length = strlen(destination);

    // Print the results
    printf("Source string: %s\n", source);
    printf("Copied string: %s\n", destination);
    printf("Length of copied string: %d\n", length);

    return 0;
}

