// simple_strncpy_check.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void print_error_exit(const char *msg) {
    // 교육용: 종료 대신 메시지만 출력
    fprintf(stderr, "%s", msg);
}

void run_case_safe(const char *label, const char *src, size_t dest_size) {
    char *dest = malloc(dest_size);
    if (!dest) return;

    // --- 요청한 조각 그대로 ---
    dest[dest_size - 1] = 0;                 // 센티널
    strncpy(dest, src, dest_size-1);           // 복사
    if (dest[dest_size - 1] != 0) {          // NUL 미종단 감지
        print_error_exit("Problem found ....\n");
    }
    else{
        print_error_exit("Problem Not found ....\n");
        
    }
    // ----------------------------

    // 보기용 출력
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

    // --- 요청한 조각 그대로 ---
    dest[dest_size - 1] = 0;                 // 센티널
    strncpy(dest, src, dest_size);           // 복사
    if (dest[dest_size - 1] != 0) {          // NUL 미종단 감지
        print_error_exit("Problem found ....\n");
    }
    else{
        print_error_exit("Problem Not found ....\n");
        
    }
    // ----------------------------

    // 보기용 출력
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
    // 케이스 1: 짧은 입력 → 안전(마지막 바이트 0 그대로 유지)
    run_case_safe("short", "hi", 8);

    // 케이스 2: 긴 입력 → 잘림 가능성, 마지막 바이트가 0이 아닐 수 있음(문제 신호)
    run_case_safe("long", "abcdefghijklmnop", 8);

    // 케이스 1: 짧은 입력 → 안전(마지막 바이트 0 그대로 유지)
    run_case_not_safe("short", "hi", 8);

    // 케이스 2: 긴 입력 → 잘림 가능성, 마지막 바이트가 0이 아닐 수 있음(문제 신호)
    run_case_not_safe("long", "abcdefghijklmnop", 8);
    return 0;
}

