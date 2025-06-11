
// 1. Secure Command Execution
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void secure_command_execution_example() {
    char filename[100];
    printf("Enter filename to list: ");
    scanf("%99s", filename);

    // Allow only alphanumeric filenames
    for (int i = 0; filename[i]; i++) {
        if (!isalnum(filename[i])) {
            printf("Invalid filename.\n");
            return;
        }
    }

    char *args[] = {"ls", filename, NULL};
    execvp("ls", args);  // Safe: avoids shell interpretation
}

// 2. Secure File Deserialization with Validation
typedef struct {
    int id;
    char name[50];
} User;

void secure_deserialization_example() {
    FILE *file = fopen("data.bin", "rb");
    if (!file) {
        printf("Failed to open file.\n");
        return;
    }

    User u;
    if (fread(&u, sizeof(User), 1, file) != 1) {
        printf("Failed to read data.\n");
        fclose(file);
        return;
    }

    u.name[sizeof(u.name) - 1] = '\0';  // Ensure null-termination
    printf("User ID: %d, Name: %s\n", u.id, u.name);
    fclose(file);
}

// 3. Secure SQL Execution with Parameter Binding
#include <sqlite3.h>

void secure_sql_example() {
    sqlite3 *db;
    sqlite3_open("users.db", &db);

    char username[50], password[50];
    printf("Username: ");
    scanf("%49s", username);
    printf("Password: ");
    scanf("%49s", password);

    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM users WHERE username = ? AND password = ?";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("Login successful.\n");
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

// 4. Secure Path Handling
#include <limits.h>

void secure_path_example() {
    char filename[100];
    printf("Enter filename to read: ");
    scanf("%99s", filename);

    char base_path[] = "./uploads/";
    char full_path[PATH_MAX];
    snprintf(full_path, sizeof(full_path), "%s%s", base_path, filename);

    char resolved_path[PATH_MAX];
    realpath(full_path, resolved_path);

    if (strncmp(resolved_path, base_path, strlen(base_path)) != 0) {
        printf("Invalid path access attempt.\n");
        return;
    }

    FILE *file = fopen(resolved_path, "r");
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

// 5. Secure Secret Handling
#include <stdlib.h>

void secure_secret_example() {
    const char *api_key = getenv("API_KEY");  // Load secret from environment
    if (!api_key) {
        printf("API key not set.\n");
        return;
    }

    printf("Using secure API key.\n");  // Do not print actual key
}

// Main function to call each example
int main() {
    // Uncomment one at a time to test
    // secure_command_execution_example();
    // secure_deserialization_example();
    // secure_sql_example();
    // secure_path_example();
    // secure_secret_example();

    return 0;
}
