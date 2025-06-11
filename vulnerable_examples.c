
// 1. Command Injection
#include <stdlib.h>
#include <stdio.h>

void command_injection_example() {
    char filename[100];
    printf("Enter filename to list: ");
    scanf("%99s", filename);
    char command[150];
    sprintf(command, "ls %s", filename);  // Vulnerable: unsanitized input in system call
    system(command);  // Dangerous: allows command injection
}

// 2. Insecure Deserialization (unsafe binary read)
#include <string.h>

typedef struct {
    int id;
    char name[50];
} User;

void insecure_deserialization_example() {
    FILE *file = fopen("data.bin", "rb");
    if (!file) {
        printf("Failed to open file.\n");
        return;
    }
    User u;
    fread(&u, sizeof(User), 1, file);  // Vulnerable: no validation of input data
    printf("User ID: %d, Name: %s\n", u.id, u.name);
    fclose(file);
}

// 3. SQL Injection (unsafe query formatting)
#include <sqlite3.h>

void sql_injection_example() {
    sqlite3 *db;
    sqlite3_open("users.db", &db);

    char username[50], password[50];
    printf("Username: ");
    scanf("%49s", username);
    printf("Password: ");
    scanf("%49s", password);

    char query[200];
    sprintf(query, "SELECT * FROM users WHERE username = '%s' AND password = '%s'", username, password);  // Vulnerable

    sqlite3_exec(db, query, 0, 0, 0);  // Dangerous: allows SQL injection
    sqlite3_close(db);
}

// 4. Path Traversal
void path_traversal_example() {
    char filename[100];
    printf("Enter filename to read: ");
    scanf("%99s", filename);  // No filtering of ".." or absolute paths

    char path[150];
    sprintf(path, "./uploads/%s", filename);  // Vulnerable: path traversal possible
    FILE *file = fopen(path, "r");

    if (file) {
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    } else {
        printf("File not found.\n");
    }
}

// 5. Hardcoded Secret
#define API_KEY "sk_test_ABC123XYZ"  // Vulnerable: hardcoded secret

void hardcoded_secret_example() {
    printf("Using API Key: %s\n", API_KEY);  // Dangerous: secret should not be in source code
}

// Main function to call each example
int main() {
    // Uncomment one at a time to test
    // command_injection_example();
    // insecure_deserialization_example();
    // sql_injection_example();
    // path_traversal_example();
    // hardcoded_secret_example();

    return 0;
}
