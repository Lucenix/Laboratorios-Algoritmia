#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool checkRet(int a, int b, int c);

int main() {
    int a, b, c;
    assert(scanf("%d %d %d", &a, &b, &c) == 3);
    if ((a<(b+c)) && (b<(a+c)) && (c<(a+b))) {
        char tipo[11];
        char ret[10] = "";
        int per = a + b + c;
        double p = (double)per / 2;
        double area = sqrt((double) (p*(p-a)*(p-b)*(p-c)));
        bool x = (a==b);
        bool y = (b==c);
        bool z = (a==c);
        if (x || y || z) {
            if (x && y && z) {
                strcpy(tipo, "EQUILATERO");
            } else {
                strcpy(tipo, "ISOSCELES");
                if (x && c>a) {
                    if (checkRet(c, a, b))
                        strcpy(ret, "RETANGULO");
                } else if (y && a > b) {
                    if (checkRet(a, b, c))
                        strcpy(ret, "RETANGULO");
                } else if (b > a) {
                    if (checkRet(b, a, c))
                        strcpy(ret, "RETANGULO");
                }
            }
        } else {
            if (a>b && a>c) {
                if (checkRet(a, b, c))
                    strcpy(tipo, "RETANGULO");
                else
                    strcpy(tipo, "ESCALENO");
            } else if (b>c) {
                if (checkRet(b, a, c))
                    strcpy(tipo, "RETANGULO");
                else
                    strcpy(tipo, "ESCALENO");
            } else {
                if (checkRet(c, a, b))
                    strcpy(tipo, "RETANGULO");
                else
                    strcpy(tipo, "ESCALENO");
            }
        }
        printf("%s %d %.2f\n", tipo, per, area);
    } else {
        printf("INVALIDO\n");
    }
    return 0;
}

bool checkRet(int a, int b, int c) {
    return ((a*a) == (b*b) + (c*c));
}
