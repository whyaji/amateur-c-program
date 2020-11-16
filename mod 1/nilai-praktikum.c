#include <stdio.h>
#include <conio.h>

int main()
{
    float n1, n2, n3, b = 0.04, a = 3;

    printf(">>> NILAI PRAKTIKUM <<<\n\n");
    printf("masukkan nilai 1 : ");
    scanf("%f", &n1);
    printf("masukkan nilai 2 : ");
    scanf("%f", &n2);
    printf("masukkan nilai 3 : ");
    scanf("%f", &n3);
    printf("nilai akhir 4 persen dari rata rata nilai yang diperoleh\n\n");

    printf("rata rata nilai yang kamu peroleh adalah : %.2f\n", (n1 + n2 + n3) / a);
    printf("nilai akhir yang kamu peroleh adalah : %.2f\n", (n1 + n2 + n3) / a * b);
    getch();
}