#include <stdio.h>

int main()
{
    double harga, total, dis, diskon, bayar;

    printf(">>> INFOTECH STORE <<<\n");
    for (int i = 1; i <= 3; i++)
    {
        printf("masukan harga barang %d = ", i);
        scanf("%lf", &harga);
        total += harga;
    }

    if (total >= 100000 && total < 300000)
    {
        dis = 10;
    }
    else if (total >= 300000 && total < 500000)
    {
        dis = 20;
    }
    else if (total >= 500000)
    {
        dis = 25;
    }
    else
    {
        dis = 0;
    }

    if (dis != 0)
    {
        printf("anda mendapatkan potongan %.0lf persen\n\n", dis);
        printf("total harga : %.0lf\n", total);
        diskon = dis / 100 * total;
        printf("diskon : %.0lf\n", diskon);
    }
    else
    {
        printf("tidak ada potongan, terimakasih\n\n");
    }

    bayar = total - diskon;
    printf("total bayar anda sebesar : %.0lf\n\n", bayar);
    printf("selamat berbelanja kembali :v");

    return 0;
}