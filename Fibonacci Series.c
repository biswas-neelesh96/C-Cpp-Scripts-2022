#include <stdio.h>
int main() {
    int i, n, a = 0, b = 1, sequence;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        printf("%d, ", a);
        sequence = a + b;
        a=b;
        b=sequence;
    }

    return 0;
}
