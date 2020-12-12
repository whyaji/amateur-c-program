#include <stdio.h>
#include <string.h>

char inputUsername(int j, char username[20], char unP[j][2][20]);
char inputPassword(int j, char password[20], char pwP[j][2][20]);
char kodeUser(int j, char unP[j][2][20], char kode[j][20]);
char login(int j, char unP[j][2][20], char pwP[j][2][20], char kode[j][20]);

int main()
{
    int menu;
    int j;
    char user[20], pass[20];
    char userP[20][2][20], passP[20][2][20];
    char kode[j][20];
    int jList;

    while (menu != 4)
    {
        printf("MENU\n 1. Registrasi\n 2. Login\n 3. Tampilkan semua data\n 4. EXIT\n");
        printf("PILIH MENU : ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            j++;
            printf("==REGISTRASI==\n");

            inputUsername(j, user, userP);
            inputPassword(j, pass, passP);
            kodeUser(j, userP, kode);

            printf("Username berhasil didaftarkan\n");
            printf(" Username : %s\n", userP[j][0]);
            printf(" Password : %s\n", passP[j][1]);
            printf(" Kode User : %s\n", kode[j]);

            break;

        case 2:
            printf("==LOGIN==\n");

            login(j, userP, passP, kode);

            break;

        case 3:
            printf("== LIST DATA ==\n");
            if (j == 0)
            {
                printf("Belum ada data teregister\n");
                break;
            }
            jList = j;
            j = 0;
            for (int i = 1; i <= jList; i++)
            {
                j++;
                printf("== %d ==\n", i);
                printf(" Username : %s\n", userP[j][0]);
                printf(" Kode User : %s\n", kode[j]);
            }
            break;

        default:
            break;
        }
    }
}

char inputUsername(int j, char username[20], char unP[j][2][20])
{
    int reg = 0;
    while (reg == 0)
    {
        printf("Input Username : ");
        scanf(" %[^\n]", username);

        int symbolH = 0;
        int c;
        int nSym = 1;

        for (int i = 0; i < strlen(username); ++i)
        {
            c = username[i];
            if (c >= 0 && c <= 45 || c == 47 ||
                c >= 58 && c <= 64 ||
                c >= 91 && c <= 96 ||
                c >= 123 && c <= 127)
            {
                symbolH = 1;
            }
            if (symbolH != 0)
            {
                nSym = 0;
                break;
            }
        }

        if (strlen(username) < 7)
        {
            printf("\nPanjang Username harus lebih dari 6 karakter\n");
            reg = 0;
            continue;
        }
        if (nSym == 0)
        {
            printf("\nUsername Tidak Boleh ada Special Karakter\n");
            reg = 0;
            continue;
        }
        else
        {
            strcpy(unP[j][0], username);
            break;
        }
    }
}

char inputPassword(int j, char password[20], char pwP[j][2][20])
{
    int pas = 0;
    while (pas == 0)
    {
        printf("Input Password : ");
        scanf(" %[^\n]", password);

        int symbolHp = 0, kapitalHp = 0, kecilHp = 0, angkaHp = 0;
        int symbol = 0, kapital = 0, kecil = 0, angka = 0;
        int jmlSyarat = 0;
        int cP;

        for (int i = 0; i < strlen(password); ++i)
        {
            cP = password[i];
            if (cP >= 0 && cP <= 31 ||
                cP >= 33 && cP <= 47 ||
                cP >= 58 && cP <= 64 ||
                cP >= 91 && cP <= 96 ||
                cP >= 123 && cP <= 127)
            {
                symbolHp = 1;
                if (symbolHp == 1)
                {
                    symbol = symbolHp;
                }
            }

            if (cP >= 65 && cP <= 90)
            {
                kapitalHp = 1;
                if (kapitalHp == 1)
                {
                    kapital = kapitalHp;
                }
            }

            if (cP >= 97 && cP <= 122)
            {
                kecilHp = 1;
                if (kecilHp == 1)
                {
                    kecil = kecilHp;
                }
            }

            if (cP >= 49 && cP <= 57)
            {
                angkaHp = 1;
                if (angkaHp == 1)
                {
                    angka = angkaHp;
                }
            }
        }

        int iP, kP, hP;
        int palindrome = 0;

        hP = strlen(password);
        iP = hP - 1;
        kP = 0;

        while (iP > kP)
        {
            if (password[iP] == password[kP])
            {
                palindrome++;
            }
            iP--;
            kP++;
        }

        jmlSyarat = symbol + kapital + kecil + angka;

        if (strlen(password) < 9)
        {
            printf("\nPanjang Password harus lebih dari 8 karakter\n");
            pas = 0;
            continue;
        }
        if (jmlSyarat != 4)
        {
            printf("\nPassword Harus menyertakan minium 1 huruf kecil (a-z), 1 huruf kapital(A-Z), 1 angka(1-9), dan 1 special karakter (!@#$^&*().,)\n");
            pas = 0;
            continue;
        }
        if (palindrome == hP / 2)
        {
            printf("\nPassword Tidak boleh berbentuk Palindrome\n");
            pas = 0;
            continue;
        }
        else
        {
            strcpy(pwP[j][1], password);
            break;
        }
    }
}

char kodeUser(int j, char unP[j][2][20], char kode[j][20])
{
    char tigaH[3];
    int urutan[20];
    for (int i = 1; i <= 20; i++)
    {
        urutan[i] = i;
    }
    memset(tigaH, '\0', sizeof(tigaH));
    strncpy(tigaH, unP[j][0], sizeof(tigaH));
    snprintf(kode[j], sizeof(kode[20]), "%.3s-%.4d", strupr(tigaH), urutan[j]);
}

char login(int j, char unP[j][2][20], char pwP[j][2][20], char kode[j][20])
{
    char iUsername[20], iPassword[20];
    int x, y;
    int sukses;
    int jLog, jIn;

    sukses = 0;
    while (sukses == 0)
    {
        if (j == 0)
        {
            printf("Belum ada data teregister\n");
            sukses = 1;
            break;
        }
        printf("Input Username : ");
        scanf(" %[^\n]", iUsername);
        printf("Input Password : ");
        scanf(" %[^\n]", iPassword);

        jLog = j;
        jIn = 0;
        for (int i = 1; i <= jLog; i++)
        {
            jIn++;
            x = strcmp(iUsername, kode[jIn]);
            if (x == 0)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        y = strcmp(iPassword, pwP[jIn][1]);
        if (x == 0 && y == 0)
        {
            printf("SELAMAT DATANG %s\n", unP[jIn][0]);
            printf("== LIST DATA ==\n");
            printf(" Username : %s\n", unP[jIn][0]);
            printf(" Kode User : %s\n", kode[jIn]);
            sukses = 1;
        }
        else
        {
            printf("Username dan password salah\n");
            sukses = 0;
        }
    }
}
