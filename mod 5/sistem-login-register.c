#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char fUser[20], fPass[20], fKode[20];

char registrasi();
int inputUsername(char username[20]);
int inputPassword(char password[20]);
void kodeUser(int j, char username[20], char kode[20]);
char listData();
char login();

FILE *fDList;

int main()
{
    int menu;
    char cM[64];

    printf("MENU\n 1. Registrasi\n 2. Login\n 3. Tampilkan semua data\n 4. EXIT\nPILIH MENU : ");
    fgets(cM, sizeof(cM), stdin);
    if (*cM < '1' || *cM > '4')
    {
        printf("Menu tidak ada\n\n");
        main();
    }
    if (strlen(cM) > 2)
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

char registrasi()
{
    int j = 1;
    char username[20], password[20];
    char kode[20];

    printf("==REGISTRASI==\n");
    printf("Input Username : ");
    gets(username);
    printf("Input Password : ");
    gets(password);

    if (inputUsername(username) + inputPassword(password) == 2)
    {
        fDList = fopen("listdata.txt", "a+");
        while (fscanf(fDList, "%s %s %s", fUser, fPass, fKode) != EOF)
        {
            j++;
        }
        kodeUser(j, username, kode);
        printf("Username berhasil didaftarkan\n");
        printf(" Username : %s\n Password : %s\n Kode User : %s\n\n", username, password, kode);
        fprintf(fDList, "%s %s %s\n", username, password, kode);
        fclose(fDList);
    }
    else
    {
        printf("\n");
    }   
}

int inputUsername(char username[20])
{
    int x = 0;
    for(;;)
    {
        if (strlen(username) < 7)
        {
            printf("Panjang Username harus lebih dari 6 karakter\n");
            break;
        }

        int symbolH = 0;
        for (int i = 0; i < strlen(username); ++i)
        {
            if (username[i] >= 0 && username[i] <= 45 || username[i] == 47 ||
                username[i] >= 58 && username[i] <= 64 ||
                username[i] >= 91 && username[i] <= 96 ||
                username[i] >= 123 && username[i] <= 127)
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
        fDList = fopen("listdata.txt", "r");
        while (fscanf(fDList, "%s %s %s", fUser, fPass, fKode) != EOF)
        {
            if (strcmp(fUser, username) == 0)
            {
                duplikat++;
                break;
            }
        }
        fclose(fDList);
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

int inputPassword(char password[20])
{
    int y = 0;
    for(;;)
    {
        if (strlen(password) < 9)
        {
            printf("Panjang Password harus lebih dari 8 karakter\n");
            break;
        }

        int symbolHp = 0, kapitalHp = 0, kecilHp = 0, angkaHp = 0;
        for (int i = 0; i < strlen(password); ++i)
        {
            if (password[i] >= 'A' && password[i] <= 'Z')
            {
                kapitalHp = 1;
            }
            if (password[i] >= 'a' && password[i] <= 'z')
            {
                kecilHp = 1;
            }
            if (password[i] >= '0' && password[i] <= '9')
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
        strcpy(passRev, password);
        if (strcmp(strrev(passRev), password) == 0)
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

void kodeUser(int j, char username[20], char kode[20])
{
    char tigaH[3];
    int urutan[100];
    urutan[j] = j;

    strcpy(tigaH, username);
    sprintf(kode, "%.3s-%.4d", strupr(tigaH), urutan[j]);
}

char listData()
{
	int j = 1;
	fDList = fopen("listdata.txt", "r");
	printf("== LIST DATA ==\n");

    if (!fDList)
    {
        printf("Belum ada data teregister\n\n");
        main();
    }

	while (fscanf(fDList, "%s %s %s", fUser, fPass, fKode) != EOF)
	{
		printf("== %d ==\nUsername : %s\nKode User : %s\n", j, fUser, fKode);
		j++;
	}
	printf("\n");
	fclose(fDList);
}

char login()
{
    char iUsername[20], iPassword[20];
    int sukses = 0;

    printf("==LOGIN==\n");

    fDList = fopen("listdata.txt", "r");

    if (!fDList)
    {
        printf("Belum ada data teregister\n\n");
        main();
    }
    
    printf("Input Username : ");
    gets(iUsername);
    printf("Input Password : ");
    gets(iPassword);

	while (fscanf(fDList, "%s %s %s", fUser, fPass, fKode) != EOF)
	{
		if ((strcmp(fKode, iUsername) == 0 || strcmp(fUser, iUsername) == 0) && strcmp(fPass, iPassword) == 0)
		{
			sukses = 1;
			break;
		}
	}

	if (sukses == 1)
	{
		printf("Selamat datang %s\n", fUser);
		printf("== Data anda ==\n");
		printf("Username : %s\n", fUser);
		printf("Kode User : %s\n\n", fKode);
	}
	else
	{
		printf("User atau Password anda salah!\n\n");
	}
    fclose(fDList);
}