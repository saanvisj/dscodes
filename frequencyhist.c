#include <stdio.h>

int main(void) {
    int a[100], n, i, j;
    int frequency[10] = {0};

    printf("Enter how many numbers\n");
    scanf("%d", &n);

    printf("Enter %d elements between the range 0-9\n", n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Array Elements are\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    for (i = 0; i < 10; i++)
        for (j = 0; j < n; j++)
            if (a[j] == i)
                frequency[i]++;

    printf("\nFrequency histogram is:\n");

    for (i = 0; i < 10; i++) {
        printf("\n[%d] ", i);
        for (j = 0; j < frequency[i]; j++)
            printf("* ");
    }

    printf("\n");

    return 0;
}
