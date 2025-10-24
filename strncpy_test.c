// simple_strncpy_check.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void print_error_exit(const char *msg) {
    // testing: print message instead of termination 
    fprintf(stderr, "%s", msg);
}

void run_case_safe(const char *label, const char *src, size_t dest_size) {
    char *dest = malloc(dest_size);
    if (!dest) return;

    // --- case study 4 for more safe---
    dest[dest_size - 1] = 0;                 // senti
    strncpy(dest, src, dest_size-1);           // copy
    if (dest[dest_size - 1] != 0) {          // NUL detection
        print_error_exit("Problem found ....\n");
    }
    else{
        print_error_exit("Problem Not found ....\n");
        
    }
    // ----------------------------

    // print
    printf("[%s] dest_size=%zu, src=\"%s\"\n", label, dest_size, src);
    printf(" last byte = %d (0이면 NUL), dest preview = \"", (unsigned char)dest[dest_size-1]);
    for (size_t i = 0; i < dest_size; ++i) {
        unsigned char c = (unsigned char)dest[i];
        if (c == '\0') { printf("\\0"); break; }
        putchar((c >= 32 && c <= 126) ? c : '.');
    }
    printf("\"\n\n");

    free(dest);
}

void run_case_safe2(const char *label, const char *src, size_t dest_size) {
    char *dest = malloc(dest_size);
    if (!dest) return;

    // --- case study 4 for more safe---
    strncpy(dest, src, dest_size-1);           // copy
    dest[dest_size - 1] = '\0';                 // senti
    if (dest[dest_size - 1] != 0) {          // NUL detection
        print_error_exit("Problem found ....\n");
    }
    else{
        print_error_exit("Problem Not found ....\n");
        
    }
    // ----------------------------

    // print
    printf("[%s] dest_size=%zu, src=\"%s\"\n", label, dest_size, src);
    printf(" last byte = %d (0이면 NUL), dest preview = \"", (unsigned char)dest[dest_size-1]);
    for (size_t i = 0; i < dest_size; ++i) {
        unsigned char c = (unsigned char)dest[i];
        if (c == '\0') { printf("\\0"); break; }
        putchar((c >= 32 && c <= 126) ? c : '.');
    }
    printf("\"\n\n");

    free(dest);
}

void run_case_not_safe(const char *label, const char *src, size_t dest_size) {
    char *dest = malloc(dest_size);
    if (!dest) return;

    // --- case study 4 ---
    dest[dest_size - 1] = 0;                 // sentinel
    strncpy(dest, src, dest_size);           // copy
    if (dest[dest_size - 1] != 0) {          // NUL detection
        print_error_exit("Problem found ....\n");
    }
    else{
        print_error_exit("Problem Not found ....\n");
        
    }
    // ----------------------------

    // print
    printf("[%s] dest_size=%zu, src=\"%s\"\n", label, dest_size, src);
    printf(" last byte = %d (0이면 NUL), dest preview = \"", (unsigned char)dest[dest_size-1]);
    for (size_t i = 0; i < dest_size; ++i) {
        unsigned char c = (unsigned char)dest[i];
        if (c == '\0') { printf("\\0"); break; }
        putchar((c >= 32 && c <= 126) ? c : '.');
    }
    printf("\"\n\n");

    free(dest);
}

int main(void) {
    // Case 1: short input → safe(last byte 0)
    run_case_safe("short", "hi", 8);
    // Case 2: long input → possible truncation, last byte may not be 0 
    run_case_safe("long", "abcdefghijklmnop", 8);

      // Case 1: short input → safe(last byte 0)
    run_case_safe2("short", "hi", 8);
    // Case 2: long input → possible truncation, last byte may not be 0 
    run_case_safe2("long", "abcdefghijklmnop", 8);

    // Case 1: short input → safe(last byte 0)
    run_case_not_safe("short", "hi", 8);
    // Case 2: long input → possible truncation, last byte may not be 0 
    run_case_not_safe("long", "abcdefghijklmnop", 8);
    return 0;
}

