#include <stdio.h>

double hasilKonversi(double rupiah, double konv);

int main()
{
    int yesno = 0;
    double uangente;
    double usd, eur, rm;
    double konvUSD = 14678;
    double konvEUR = 17353;
    double konvRM = 3511;

    printf(">>>> Konversi Rupiah (2020) <<<<\n");

    do
    {
        printf("\nmasukan nilai uang anda dalam rupiah : ");
        scanf("%lf", &uangente);

        usd = hasilKonversi(uangente, konvUSD);
        eur = hasilKonversi(uangente, konvEUR);
        rm = hasilKonversi(uangente, konvRM);

        printf("konversi uang anda adalah %.0lf rupiah sama dengan :\n %.2f dolar\n %.2f euro\n %.2f ringgit\n\n", uangente, usd, eur, rm);
        printf("coba lagi ( 1=yes / 0=no ) : ");
        scanf("%d", &yesno);
    } while (yesno == 1);

    return 0;
}

double hasilKonversi(double rupiah, double konv)
{
    double hasil;
    hasil = rupiah / konv;
    return hasil;
}