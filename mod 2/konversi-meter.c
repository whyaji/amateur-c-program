#include <stdio.h>

int konversi(int hektare);
double hasilKonversi(int hektare, double konv);

int main()
{
    int hektare;

    printf("masukkan satuan luas dalam satuan hektare: ");
    scanf("%d", &hektare);
    printf("konversi satuan luas adalah %d hektare sama dengan : ", hektare);
    konversi(hektare);

    return 0;
}

int konversi(int hektare)
{
    double are, m_persegi, cm_persegi;
    double konvARE = 100;
    double konvM = 10000;
    double konvCM = 100000000;

    are = hasilKonversi(hektare, konvARE);
    m_persegi = hasilKonversi(hektare, konvM);
    cm_persegi = hasilKonversi(hektare, konvCM);

    printf("\n %.0f are \n %.0f meter persegi \n %.0f centimeter persegi\n", are, m_persegi, cm_persegi);

    return 0;
}

double hasilKonversi(int hektare, double konv)
{
    double hasil;
    hasil = hektare * konv;
    return hasil;
}