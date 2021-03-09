#include <stdio.h>
#include <assert.h>

void desenha();

int main() {

    int arvore[10][10];
    for (int i = 0; i<10; i++) {
        for (int j = 0; j<10; j++) {
            arvore[i][j]=0;
        }
    }

    int r;
    do {
        assert(scanf("%d", &r) == 1);
        if (r <0 || r> 99)
            continue;
        int i = r/10, j = r%10;
        arvore[i][j]++;
    } while (r!=-1);
    desenha(arvore);
    return 0;
}

void desenha(int arvore[10][10]) {
    for (int i = 0; i<10; i++) {
        printf("%d|", i);
        for (int j = 0; j<10; j++) {
            for (int k = arvore[i][j]; k>0; k--) {
                printf("%d", j);
            }
        }
        putchar('\n');
    }
}
