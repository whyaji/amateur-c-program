#include <stdio.h>
#define a 2.5

int main()
{
    int nim, bil1, bil2, bil3,
        jumlah;
    float hasil;

    printf("masukkan 3 digit terakhir nim anda : ");
    scanf("%d", &nim);
    printf("masukkan bilangan pertama : ");
    scanf("%d", &bil1);
    printf("masukkan bilangan kedua : ");
    scanf("%d", &bil2);
    jumlah = nim - (bil1 + bil2);

    printf("jumlah yang diperoleh : %d \n", jumlah);
    printf("\nmasukkan bilangan ketiga : ");
    scanf("%d", &bil3);
    hasil = jumlah * bil3 / a;
    printf("\nnim anda adalah : %d \n", nim);
    printf("hasil yang anda peroleh dari data diatas adalah : %f \n", hasil);

    return 0;
}