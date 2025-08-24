#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num1> <num2> ...\n", argv[0]);
        return 1;
    }
    long max = LONG_MIN;
    for (int i = 1; i < argc; ++i) {
        char *end;
        long val = strtol(argv[i], &end, 10);
        if (*end != '\0') {
            fprintf(stderr, "Non-integer argument: %s\n", argv[i]);
            return 2;
        }
        if (val > max) max = val;
    }
    printf("Max = %ld\n", max);
    return 0;
}