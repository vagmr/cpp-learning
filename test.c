#include <stdio.h>
#include <conio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    double c = (double)(a + b) / 2.0;
    printf("%d and %d average is %.2f", a, b, c);
    getch();
    return 0;
}