#include <stdio.h>
#include <assert.h>

int main () {
    int x, y;
    assert(scanf("%d %d", &x, &y) == 2);
    x = x*x; y = y*y;
    printf("%d\n", x + y);
    return 0;
}