#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fUrutan, aUrutan, nonDuplikat;
char fUser[20], fPass[20], fKode[20], aUser[20], aPass[20], aKode[20];
char kosong[] = "--";

void registrasi();
int inputUsername(char iUser[20]);
int inputPassword(char iPass[20]);
void listData();
void login();
void mainUser();
void akunAnda();
void editAkun();
void deleteAkun();
void delEdiAkun(char bUser[20], char bPass[20], char bKode[20]);
void deleteData();

FILE *fDList;
FILE *fDTemp;

int main()
{
    int menu;
    char cM[64];

    printf("MENU\n 1. Registrasi\n 2. Login\n 3. Tampilkan semua data\n 4. EXIT\n");
    printf("PILIH MENU : ");
    gets(cM);
    if (*cM < '1' || *cM > '4' || strlen(cM) > 1)
    {
        printf("Menu tidak ada\n\n");
        main();
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    switch (menu)
    {
    case 1:
        registrasi();
        main();

    case 2:
        login();
        main();

    case 3:
        listData();
        main();

    case 4:
        exit(0);
    }
    return 0;
}

void registrasi()
{
    int j = 1, pengurangan = 1;
    char rUser[20], rPass[20], rKode[20], tigaH[3];

    printf("\n==REGISTRASI==\n");
    printf("Input Username : ");
    gets(rUser);
    printf("Input Password : ");
    gets(rPass);

    if (inputUsername(rUser) + inputPassword(rPass) == 2)
    {
        fDList = fopen("listdata.txt", "a+");
        while (fscanf(fDList, "%d %s %s %s\n", &fUrutan, fUser, fPass, fKode) != EOF)
        {
            j++;
            if (strcmp(kosong, fUser) == 0)
            {
                j--;
            }
        }
        strcpy(tigaH, rUser);
        sprintf(rKode, "%.3s-%.4d", strupr(tigaH), j);

        printf("Username berhasil didaftarkan\n");
        printf(" Username : %s\n Password : %s\n Kode User : %s\n\n", rUser, rPass, rKode);
        fprintf(fDList, "%d %s %s %s\n", j, rUser, rPass, rKode);
        fclose(fDList);
    }
    else
    {
        printf("\n");
    }
}

int inputUsername(char iUser[20])
{
    int x = 0;
    for (;;)
    {
        if (strlen(iUser) < 7)
        {
            printf("Panjang Username harus lebih dari 6 karakter\n");
            break;
        }

        int i = 0, symbolH = 0;
        for (int i = 0; i < strlen(iUser); ++i)
        {
            if (!(iUser[i] >= 'A' && iUser[i] <= 'Z' ||
                  iUser[i] >= 'a' && iUser[i] <= 'z' ||
                  iUser[i] >= '0' && iUser[i] <= '9' ||
                  iUser[i] == '.'))
            {
                symbolH++;
            }
        }
        if (symbolH != 0)
        {
            printf("Username Tidak Boleh ada Special Karakter\n");
            break;
        }

        int duplikat = 0;
        if (nonDuplikat == 0)
        {
            fDList = fopen("listdata.txt", "r");
            while (fscanf(fDList, "%d %s %s %s\n", &fUrutan, fUser, fPass, fKode) != EOF)
            {
                if (strcmp(fUser, iUser) == 0)
                {
                    duplikat++;
                    break;
                }
            }
            fclose(fDList);
        }

        if (duplikat != 0)
        {
            printf("Username sudah terpakai, Tidak boleh ada duplikasi username\n");
            break;
        }
        else
        {
            x++;
            break;
        }
    }
    return x;
}

int inputPassword(char iPass[20])
{
    int y = 0;
    for (;;)
    {
        if (strlen(iPass) < 9)
        {
            printf("Panjang Password harus lebih dari 8 karakter\n");
            break;
        }

        int i = 0, symbolHp = 0, kapitalHp = 0, kecilHp = 0, angkaHp = 0;
        for (int i = 0; i < strlen(iPass); ++i)
        {
            if (iPass[i] >= 'A' && iPass[i] <= 'Z')
            {
                kapitalHp = 1;
            }
            else if (iPass[i] >= 'a' && iPass[i] <= 'z')
            {
                kecilHp = 1;
            }
            else if (iPass[i] >= '0' && iPass[i] <= '9')
            {
                angkaHp = 1;
            }
            else
            {
                symbolHp = 1;
            }
        }
        if (symbolHp + kapitalHp + kecilHp + angkaHp != 4)
        {
            printf("Password Harus menyertakan minium 1 huruf kecil, 1 huruf kapital, 1 angka, dan 1 special karakter\n");
            break;
        }

        char passRev[20];
        strcpy(passRev, iPass);
        if (strcmp(strrev(passRev), iPass) == 0)
        {
            printf("Password Tidak boleh berbentuk Palindrome\n");
            break;
        }
        else
        {
            y++;
            break;
        }
    }
    return y;
}

void listData()
{
    int j = 1;

    printf("\n== LIST DATA ==\n");
    fDList = fopen("listdata.txt", "r");
    if (!fDList)
    {
        printf("Belum ada data teregister\n\n");
        main();
    }

    while (fscanf(fDList, "%d %s %s %s\n", &fUrutan, fUser, fPass, fKode) != EOF)
    {
        if (strcmp(kosong, fUser) != 0)
        {
            printf("== %d ==\nUsername : %s\nKode User : %s\n", j, fUser, fKode);
            j++;
        }
    }
    printf("\n");
    fclose(fDList);
}

void login()
{
    char lUser[20], lPass[20];
    int sukses = 0;

    printf("\n==LOGIN==\n");

    fDList = fopen("listdata.txt", "r");

    if (!fDList)
    {
        printf("Belum ada data teregister\n\n");
        main();
    }

    printf("Input Username : ");
    gets(lUser);
    printf("Input Password : ");
    gets(lPass);

    if ((strcmp(kosong, lUser) == 0 || strcmp(kosong, lUser) == 0) && strcmp(kosong, lPass) == 0)
    {
        printf("User atau Password anda salah!\n\n");
        main();
    }

    while (fscanf(fDList, "%d %s %s %s\n", &fUrutan, fUser, fPass, fKode) != EOF)
    {
        if ((strcmp(fKode, lUser) == 0 || strcmp(fUser, lUser) == 0) && strcmp(fPass, lPass) == 0)
        {
            sukses = 1;
            break;
        }
    }
    fclose(fDList);

    if (sukses == 1)
    {
        printf("Selamat datang %s\n", fUser);
        printf("== Data anda ==\n");
        printf("Username : %s\n", fUser);
        printf("Kode User : %s\n\n", fKode);

        strcpy(aUser, fUser);
        strcpy(aPass, fPass);
        strcpy(aKode, fKode);
        aUrutan = fUrutan;

        mainUser();
    }
    else
    {
        printf("User atau Password anda salah!\n\n");
    }
}

void mainUser()
{
    int menu, j = 1;
    char cM[64];
    int fAUrutan;
    char fAUser[20], fAPass[20], fAKode[20];

    fDList = fopen("listdata.txt", "r");
    while (fscanf(fDList, "%d %s %s %s\n", &fUrutan, fUser, fPass, fKode) != EOF)
    {
        j++;
    }
    fclose(fDList);

    fDList = fopen("listdata.txt", "r");
    for (int i = 1; i <= j; i++)
    {
        fscanf(fDList, "%d %s %s %s\n", &fAUrutan, fAUser, fAPass, fAKode);
        if (strcmp(kosong, fAUser) != 0)
        {
            break;
        }
    }
    fclose(fDList);

    if ((strcmp(fAKode, aUser) == 0 || strcmp(fAUser, aUser) == 0) && strcmp(fAPass, aPass) == 0)
    {
        printf("== Halo %s (admin) ==\n 1. Akun anda\n 2. Logut\n 3. Tampilkan semua data\n 4. Hapus semua data\n", aUser);
        printf("PILIH MENU : ");
        gets(cM);
        if (*cM < '1' || *cM > '4' || strlen(cM) > 1)
        {
            printf("Menu tidak ada\n\n");
            mainUser();
        }
        else
        {
            sscanf(cM, "%d", &menu);
        }
    }
    else
    {
        printf("== Halo %s ==\n 1. Akun anda\n 2. Logut\n 3. Tampilkan semua data\n", aUser);
        printf("PILIH MENU : ");
        gets(cM);
        if (*cM < '1' || *cM > '3' || strlen(cM) > 1)
        {
            printf("Menu tidak ada\n\n");
            mainUser();
        }
        else
        {
            sscanf(cM, "%d", &menu);
        }
    }

    switch (menu)
    {
    case 1:
        akunAnda();
        mainUser();

    case 2:
        printf("Anda telah logout\n\n");
        main();

    case 3:
        listData();
        mainUser();

    case 4:
        deleteData();
        main();
    }
}

void akunAnda()
{
    printf("\n== Akun Anda ==\n");
    printf("Username : %s\n", aUser);
    printf("Kode User : %s\n", aKode);
    printf("Password : ");

    for (int i = 1; i <= strlen(aPass); i++)
    {
        printf("*");
    }
    printf("\n");

    int menu;
    char cM[64];

    printf("Pilih\n 1. Edit akun anda\n 2. Hapus akun anda\n 3. Kembali\n");
    printf("PILIH MENU : ");
    gets(cM);
    if (*cM < '1' || *cM > '3' || strlen(cM) > 1)
    {
        printf("Pilihan tidak ada\n\n");
        akunAnda();
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    switch (menu)
    {
    case 1:
        editAkun();
        akunAnda();

    case 2:
        deleteAkun();
        akunAnda();

    case 3:
        printf("Kembali\n\n");
        mainUser();
    }
}

void editAkun()
{
    char bUser[20], bPass[20], bKode[20], tigaH[3], kPass[20];
    char ksng[20] = "";

    printf("Masukan password anda\n");
    gets(kPass);
    if (strcmp(kPass, aPass) == 0)
    {
        printf("Masukan username dan password baru\n");
        printf("Kosongkan bagian yang tidak diganti\n");
        printf("Input username : ");
        gets(bUser);
        printf("Input password : ");
        gets(bPass);
        nonDuplikat = 0;

        if (strcmp(bUser, ksng) == 0)
        {
            strcpy(bUser, aUser);
            nonDuplikat++;
        }
        if (strcmp(bPass, ksng) == 0)
        {
            strcpy(bPass, aPass);
        }

        if (inputUsername(bUser) + inputPassword(bPass) == 2)
        {
            strcpy(tigaH, bUser);
            sprintf(bKode, "%.3s-%.4d", strupr(tigaH), aUrutan);
            delEdiAkun(bUser, bPass, bKode);
            printf("\nAkun anda telah diperbarui\n");
        }
        else
        {
            printf("\nAkun anda gagal diperbarui\n");
        }
    }
    else
    {
        printf("\nPassword anda salah\n");
    }
}

void deleteAkun()
{
    char bUser[20], bPass[20], bKode[20], kPass[20];
    int j = 0;

    printf("\nApakah anda yakin ingin menghapus akun ini? jika anda yakin\n");
    printf("Masukan password anda\n");
    gets(kPass);
    if (strcmp(kPass, aPass) == 0)
    {
        strcpy(bUser, kosong);
        strcpy(bPass, kosong);
        strcpy(bKode, kosong);
        delEdiAkun(bUser, bPass, bKode);
        printf("\nAkun anda telah dihapus\n\n");

        fDList = fopen("listdata.txt", "r");
        while (fscanf(fDList, "%d %s %s %s\n", &fUrutan, fUser, fPass, fKode) != EOF)
        {
            if (strcmp(kosong, fUser) != 0)
            {
                j++;
            }
        }
        fclose(fDList);
        if (j == 0)
        {
            remove("listdata.txt");
            printf("\nDan semua data telah dihapus\n\n");
        }

        main();
    }
    else
    {
        printf("\nPassword anda salah\n");
    }
}

void delEdiAkun(char bUser[20], char bPass[20], char bKode[20])
{
    fDList = fopen("listdata.txt", "r");
    fDTemp = fopen("lotemp.txt", "a+");
    while (!feof(fDList))
    {
        fscanf(fDList, "%d %s %s %s\n", &fUrutan, fUser, fPass, fKode);
        if (fUrutan == fUrutan - 1)
        {
            break;
        }
        
        if (fUrutan == aUrutan)
        {
            if (strcmp(kosong, fUser) != 0)
            {
                fprintf(fDTemp, "%d %s %s %s\n", aUrutan, bUser, bPass, bKode);
            }
        }
        else
        {
            fprintf(fDTemp, "%d %s %s %s\n", fUrutan, fUser, fPass, fKode);
        }
    }
    fclose(fDList);
    fclose(fDTemp);

    remove("listdata.txt");
    rename("lotemp.txt", "listdata.txt");

    strcpy(aUser, bUser);
    strcpy(aPass, bPass);
    strcpy(aKode, bKode);
}

void deleteData()
{
    char kPass[20];
    printf("\nApakah anda yakin ingin menghapus semua data user? jika anda yakin\n");
    printf("Masukan password anda\n");
    gets(kPass);
    if (strcmp(kPass, aPass) == 0)
    {
        remove("listdata.txt");
        printf("\nSemua data telah dihapus\n\n");
        main();
    }
    else
    {
        printf("\nPassword anda salah\n\n");
        mainUser();
    }
}