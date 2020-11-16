#include <stdio.h>
#include <conio.h>
#include <string.h>

int funcNilai(int nilai);

int main()
{
    char user[20];
    char pass[20];
    int nilai;
    int ulang = 0;

    printf("username : ");
    gets(user);
    printf("password : ");
    gets(pass);

    if (strcmp(user, "informatika") == 0)
    {
        if (strcmp(pass, "infotech123") == 0)
        {
            funcNilai(nilai);
        }
        else
        {
            printf("\n\nuser dan password anda salah\n\n");
            main();
        }
    }
    else
    {
        printf("\n\nuser dan password anda salah\n\n");
        main();
    }
    getch();

    return 0;
}

int funcNilai(int nilai)
{
    printf("\nmasukkan nilai anda : ");
    scanf("%d", &nilai);

    if (nilai >= 80 && nilai <= 100)
    {
        printf("\nSelamat anda lolos di informatika\n");
    }
    else if (nilai < 0 || nilai > 100)
    {
        printf("\nNilai yang anda masukan salah\n");
    }
    else
    {
        printf("\nSilahkan coba tahun depan, semangat!\n");
    }

    return 0;
}