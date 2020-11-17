#include <stdio.h>

int konversi(int rupiah, char bagian);
float hasilKonversi(int rupiah, float konv);

int main()
{
    int RpA = 9576;
    int RpB = 7856;
    int RpC = 8612021;

    printf("NIM : 202010370311197\n\n");
    konversi(RpA, 'A');
    konversi(RpB, 'B');
    konversi(RpC, 'C');

    return 0;
}

int konversi(int rupiah, char bagian)
{
    float usd, eur, rm;
    float konvUSD = 14678;
    float konvEUR = 17353;
    float konvRM = 3511;

    usd = hasilKonversi(rupiah, konvUSD);
    eur = hasilKonversi(rupiah, konvEUR);
    rm = hasilKonversi(rupiah, konvRM);

    printf("konversi rupiah %c adalah %d rupiah sama dengan :\n %.2f dolar\n %.2f euro\n %.2f ringgit\n\n", bagian, rupiah, usd, eur, rm);

    return 0;
}

float hasilKonversi(int rupiah, float konv)
{
    float hasil;
    hasil = rupiah / konv;
    return hasil;
}