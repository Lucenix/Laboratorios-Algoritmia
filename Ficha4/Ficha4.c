#include <stdio.h>
#include <assert.h>

#define FORN(i, max) for(int i = 0; i<max; i++)
void desenha();
void regista();

int main() {

    int arvore[10][10] = {0};
    regista(10, arvore);
    desenha(10, arvore);
    return 0;
}

void regista(int N, int arvore[N][N]) {
    int r;
    do {
        assert(scanf("%d", &r) == 1);
        if (r <0 || r> 99)
            continue;
        int i = r/10, j = r%10;
        arvore[i][j]++;
    } while (r!=-1);
}

void desenha(int N, int arvore[N][N]) {
    //int *a = arvore[0];

    FORN(i, 10) {
        //printf("%x ", a);
        //printf("%d\n", *a);
        //a += 10;
        //int *b = arvore[i];
        //printf("%x ", b);
        //printf("%d\n", *b);

        printf("%d|", i);
        FORN(j,10) {
            int k = arvore[i][j];
            while (k!=0) {
                printf("%d", j);
                k--;
            }
        }
        putchar('\n');
    }
}
