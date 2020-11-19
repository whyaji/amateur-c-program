#include <stdio.h>
/**Program berulang sebanyak 5 kali
 program ini menampilkan bil.genap positif jika bil>0 dan habis dibagi 2
 program ini menampilkan bil.genap negatif jika bil<0 dan habis dibagi 2
 program ini menampilkan bil.ganjil positif jika bil>0 dan tidak habis dibagi 2
 program ini menampilkan bil.ganjil negatif jika bil<0 dan tidak habis dibagi 2
 */
int main(int argc, char **argv)
{
    int bil;

    for (int i = 1; i <= 5; i++)
    {
        printf("masukan sebuah bilangan : ");
        scanf("%d", &bil);

        if (bil > 0)
        {
            if (bil % 2 == 0)
            {
                printf("%d adalah bilangan genap positif\n", bil);
            }
            else
            {
                printf("%d adalah bilangan ganjil positif\n", bil);
            }
        }
        else if (bil < 0)
        {
            if (bil % 2 == 0)
            {
                printf("%d adalah bilangan genap negatif\n", bil);
            }
            else
            {
                printf("%d adalah bilangan ganjil negatif\n", bil);
            }
        }
        else
        {
            printf("bilangan yang anda input adalah angka 0 \n");
        }
    }
    return 0;
}