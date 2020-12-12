#include <stdio.h>
#include <conio.h>

float determinan(int size, float n, float a[size][size]); //fungsi mencari determinan

int main()
{
    char userinput[64]; //input pilihan
    int size;           //ukuran array
    int i, j;           //dimensi array
    float n;            //batas array
    float d;            //determinan

    while (size == 0)
    {
        printf("masukkan ordo matrix yang diinginkan: ");
        fgets(userinput, 63, stdin);

        if (sscanf(userinput, "%d", &size) != 1)    //mencegah inputan selain angka
        {
            size = 0;
            printf("hanya menginput angka, ketik 2 untuk memilih ordo 2x2 atau 3 untuk memilih ordo 3x3 dst\n\n");
            continue;
        }
        if (size < 2)                               //mencegah inputan angka di bawah 2
        {
            size = 0;
            printf("hanya menginput angka di atas 1, ketik 2 untuk memilih ordo 2x2 atau 3 untuk memilih ordo 3x3 dst\n\n");
            continue;
        }
        else
        {
            sscanf(userinput, "%f", &n);            //convert char to float
            break;
        }
    }

    char c[64];                     //input index
    int s;                          //batas keputusan masukan index
    float a[size][size];            //array index

    printf("\nmasukkan angka angka matrix :\n");

    for (i = 0; i < n; i++)         //pengulangan input index
    {
        for (j = 0; j < n; j++)
        {
            s = 0;
            while (s == 0)
            {
                printf("masukan index [%d] [%d] : ", i, j);
                fgets(c, 63, stdin);

                if (sscanf(c, "%d", &s) != 1) //mencegah inputan selain angka
                {
                    s = 0;
                    printf("hanya menginput angka\n");
                    continue;
                }
                else
                {
                    sscanf(c, "%f", &a[i][j]);
                    break;
                }
            }
        }
    }
     
    printf("\nhasil inputan :\n");

    for (i = 0; i < n; i++)         //pengulangan output index
    {
        for (j = 0; j < n; j++)
        {
            printf("%.2f\t\t", a[i][j]);
        }
        printf("\n");
    }

    d = determinan(size, n, a);     //memasukan fungsi determinan

    printf("\nnilai determinan yang dihasilkan adalah : %.2f\n", d);  //output hasil determinan
    getch();
    return 0;
}

float determinan(int size, float n, float a[size][size])
{
    float det = 0;          //determinan
    float b[size][size];    //array index kedua untuk perulangan total determinan
    float s = 1;            //pembuat positif dan negatif
    int i, j;               //dimensi array
    int k, l;               //dimensi array b (index array kedua)
    int c;                  //pengulangan penotalan determinan

    if (n == 2)             //determinan matrix ordo 2x2
    {
        det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }
    else                    //determinan matrix ordo nxn
    {
        for (c = 0; c < n; c++)
        {
            k = l = 0;
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (i != 0 && j != c)
                    {
                        b[k][l] = a[i][j];
                        l++;
                        if (l > n - 2)
                        {
                            k++;
                            l = 0;
                        }
                    }
                }
            }
            det = det + s * (a[0][c] * determinan(size, n - 1, b));
            s = -1 * s;
        }
    }
    return det;
}
