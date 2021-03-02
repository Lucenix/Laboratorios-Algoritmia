#include <stdio.h>
#include <assert.h>

int main() {
    int input;
    assert(scanf("%d", &input) == 1);
    for (int i = 1; i < input; i++) {
        for (int j = 0; j < i; j++)
            putchar('*');
        for (int j = 0; j < 2*input - 2*i; j++)
            putchar('.');
        for (int j = 0; j < i; j++)
            putchar('*');

        putchar('\n');
    }

    for (int i = 0; i < input*2; i++)
        putchar('*');

    putchar('\n');

    for (int i = input-1; i > 0; i--) {
        for (int j = 0; j < i; j++)
            putchar('*');
        for (int j = 0; j < 2*input - 2*i; j++)
            putchar('.');
        for (int j = 0; j < i; j++)
            putchar('*');

        putchar('\n');
    }

    return 0;
}
