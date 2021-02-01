#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nonDuplikat;
char user[5][30], pass[5][30], email[10][30];
int profitAdmin[3], moneyHold[3], walletB[5];
char titleGig[5][99], kategoriGig[5][20], kodeGig[5][11];
char vTitle[6][99], vKategori[6][20], vKode[6][11];
int hargaGig[5], vHarga[6], vNum[6];
char kodeOrder[5][15], pesanOrder[5][200], materialOrder[5][200], finalOrder[5][200], demoFinal[5][200];
int konfFinal[5];
char vKodeOrder[6][15];
char kosong[] = "--";
int delGig;
int ediOrder;
int ediAkun;

void addAdmin();
void editCode();
void menuRegLog();
void registrasi();
int inputUsername();
int inputPassword();
int inputEmail();
void login();
void mainAdmin();
void akunAdmin();
void createCode();
void randomCode(int nominalKode, int jumlahKode);
void mainUser();
void topupPage();
void akunAnda();
void editAkun();
void deleteAkun();
void delEdiAkun();
void sellerPage();
void sellerOrder();
void openSellerOrder();
void createGig();
void sellerGig();
void openSellerGig();
void openGigEdi();
void deleteGig();
void buyerPage();
void buyerOrder();
void openBuyerOrder();
void openOrderEdi();
void editOrder();
void buyerKatGig();
void buyerGig();
void openBuyerGig();
void orderGig();

FILE *fp1;
FILE *fp2;

void main()
{
    fp1 = fopen("listuser.txt", "r");
    if (!fp1)
    {
        fclose(fp1);
        addAdmin();
    }
    else
    {
        fclose(fp1);
    }

    printf("\t== PLATFORM LAYANAN FREELANCE ==\n\n");
    printf("Temukan Jasa Desain, Social Media Marketing, Penulisan,\nFotografi, Video dan Website. Cepat dan Berkualitas\n\n");
    menuRegLog();
}

void addAdmin()
{
    fp1 = fopen("listuser.txt", "a+");
    fprintf(fp1, "admin admin 0 0\n");
    fclose(fp1);
}

void menuRegLog()
{
    printf("Sudah mempunyai akun? silahkan login\njika belum ayo daftarkan anda sekarang\n");
    printf(" 1. Daftar\n 2. Login\n 3. Keluar\n");
    printf("Pilih : ");

    int menu;
    char cM[64];

    gets(cM);
    if (*cM < '1' || *cM > '3' || strlen(cM) > 1)
    {
        printf("Menu tidak ada\n\n");
        menuRegLog();
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    switch (menu)
    {
    case 1:
        registrasi();
        menuRegLog();

    case 2:
        login();
        menuRegLog();

    case 3:
        exit(0);
    }
}

void registrasi()
{
    int nol = 0;

    printf("\n== Daftar ==\n");
    printf("Email       : ");
    gets(email[1]);
    printf("Username    : ");
    gets(user[1]);
    printf("Password    : ");
    gets(pass[1]);

    if (inputUsername() + inputPassword() + inputEmail() == 3)
    {
        fp1 = fopen("listuser.txt", "a+");
        fprintf(fp1, "%s %s %s %d\n", user[1], pass[1], email[1], nol);
        fclose(fp1);

        printf("\nUser berhasil didaftarkan\n\n");
    }
    else
    {
        printf("\n");
    }
}

int inputUsername()
{
    int x = 0;
    for (;;)
    {
        if (strlen(user[1]) < 7)
        {
            printf("Panjang Username harus lebih dari 6 karakter\n");
            break;
        }

        int i = 0, symbolH = 0;
        for (int i = 0; i < strlen(user[1]); ++i)
        {
            if (!(user[1][i] >= 'A' && user[1][i] <= 'Z' ||
                  user[1][i] >= 'a' && user[1][i] <= 'z' ||
                  user[1][i] >= '0' && user[1][i] <= '9' ||
                  user[1][i] == '.'))
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
            fp1 = fopen("listuser.txt", "r");
            while (fscanf(fp1, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]) != EOF)
            {
                if (strcmp(user[0], user[1]) == 0)
                {
                    duplikat++;
                    break;
                }
            }
            fclose(fp1);
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

int inputPassword()
{
    int y = 0;
    for (;;)
    {
        if (strlen(pass[1]) < 9)
        {
            printf("Panjang Password harus lebih dari 8 karakter\n");
            break;
        }

        int i = 0, symbolHp = 0, kapitalHp = 0, kecilHp = 0, angkaHp = 0;
        for (int i = 0; i < strlen(pass[1]); ++i)
        {
            if (pass[1][i] >= 'A' && pass[1][i] <= 'Z')
            {
                kapitalHp = 1;
            }
            else if (pass[1][i] >= 'a' && pass[1][i] <= 'z')
            {
                kecilHp = 1;
            }
            else if (pass[1][i] >= '0' && pass[1][i] <= '9')
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
        strcpy(passRev, pass[1]);
        if (strcmp(strrev(passRev), pass[1]) == 0)
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

int inputEmail()
{
    int z = 0;
    for (;;)
    {
        int duplikat = 0;
        fp1 = fopen("listuser.txt", "r");
        while (fscanf(fp1, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]) != EOF)
        {
            if (strcmp(email[0], email[1]) == 0)
            {
                duplikat++;
                break;
            }
        }
        fclose(fp1);
        if (duplikat != 0)
        {
            printf("Email sudah terpakai\n");
            break;
        }

        int at = 0;
        for (int i = 0; i < strlen(email[1]); ++i)
        {
            if (email[1][i] == '@')
            {
                at++;
            }
        }
        if (at == 0)
        {
            printf("Email harus ada symbol @\n");
            break;
        }

        int spasi = 0;
        for (int i = 0; i < strlen(email[1]); ++i)
        {
            if (email[1][i] == ' ')
            {
                spasi++;
            }
        }
        if (spasi != 0)
        {
            printf("Email tidak boleh ada spasi\n");
            break;
        }
        else
        {
            z++;
            break;
        }
    }
    return z;
}

void login()
{
    int sukses = 0;

    printf("\n== LOGIN ==\n");

    printf("Username/Email  : ");
    gets(user[2]);
    printf("Password        : ");
    gets(pass[2]);

    if (strcmp(kosong, user[2]) == 0 && strcmp(kosong, pass[2]) == 0)
    {
        printf("User atau Password anda salah!\n\n");
        menuRegLog();
    }

    fp1 = fopen("listuser.txt", "r");
    fscanf(fp1, "%s %s %d %d\n", user[0], pass[0], &profitAdmin[0], &moneyHold[0]);
    if (strcmp(user[0], user[2]) == 0 && strcmp(pass[0], pass[2]) == 0)
    {
        strcpy(user[3], user[0]);
        strcpy(pass[3], pass[0]);
        fclose(fp1);
        mainAdmin();
    }
    fclose(fp1);

    fp1 = fopen("listuser.txt", "r");
    while (fscanf(fp1, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]) != EOF)
    {
        if ((strcmp(email[0], user[2]) == 0 || strcmp(user[0], user[2]) == 0) && strcmp(pass[0], pass[2]) == 0)
        {
            sukses = 1;
            break;
        }
    }
    fclose(fp1);

    if (sukses == 1)
    {
        strcpy(user[3], user[0]);
        strcpy(pass[3], pass[0]);
        strcpy(email[3], email[0]);
        walletB[3] = walletB[0];
        printf("\n");
        mainUser();
    }
    else
    {
        printf("User atau Password anda salah!\n\n");
    }
}

void mainAdmin()
{
    printf("\n== Admin Page ==\n\n");
    printf("Profit yang diperoleh     : Rp %d\n", profitAdmin[0]);
    printf("Pembayaran sedang ditahan : Rp %d\n", moneyHold[0]);

    int menu;
    char cM[64];

    printf(" 1. Akun admin\n 2. Buat Topup Kode\n 3. Logout\n");
    printf("Pilih : ");
    gets(cM);
    if (*cM < '1' || *cM > '3' || strlen(cM) > 1)
    {
        printf("Menu tidak ada\n\n");
        mainAdmin();
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    switch (menu)
    {
    case 1:
        akunAdmin();

    case 2:
        createCode();
        mainAdmin();

    case 3:
        printf("Anda telah logout\n\n");
        menuRegLog();
    }
}

void akunAdmin()
{
    printf("\n== Akun Admin ==\n");
    printf("Username : %s\n", user[3]);
    printf("Password : ");

    for (int i = 1; i <= strlen(pass[3]); i++)
    {
        printf("*");
    }
    printf("\n");

    int menu;
    char cM[64];

    printf("Pilih\n 1. Edit akun\n 2. Kembali\n");
    printf("Pilih : ");
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
        ediAkun = 4;
        editAkun();
        ediAkun = 0;
        akunAdmin();

    case 2:
        printf("Kembali\n\n");
        mainAdmin();
    }
}

void createCode()
{
    printf("\n== Membuat Kode Top Up ==\n");

    int nominalTU;
    int jumlahTU;

    printf("Masukan nominal : Rp ");
    scanf("%d", &nominalTU);
    fflush(stdin);
    printf("Jumlah Kode     : ");
    scanf("%d", &jumlahTU);
    fflush(stdin);
    randomCode(nominalTU, jumlahTU);
}

void randomCode(int nominalKode, int jumlahKode)
{
    static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char kodeTU[2][11];
    int kar[11];
    int kodeLength = 10;
    int nom;

    for (int i = 0; i < jumlahKode; i++)
    {
        strcpy(kodeTU[1], "");
        for (int i = 0; i < kodeLength; i++)
        {
            kar[i] = alphanum[rand() % sizeof(alphanum - 1)];
            sprintf(kodeTU[1], "%s%c", kodeTU[1], kar[i]);
        }
        fp1 = fopen("listcode.txt", "r");
        while (fscanf(fp1, "%s %d\n", kodeTU[0], &nom) != EOF)
        {
            if (strcmp(kodeTU[0], kodeTU[1]) == 0)
            {
                break;
            }
        }
        fclose(fp1);
        if (strcmp(kodeTU[0], kodeTU[1]) == 0)
        {
            i--;
            continue;
        }
        else
        {
            fp1 = fopen("listcode.txt", "a+");
            fprintf(fp1, "%s %d\n", kodeTU[1], nominalKode);
            fclose(fp1);
            printf("%s %d\n", kodeTU[1], nominalKode);
        }
    }
}

void mainUser()
{
    int menu;
    char cM[64];

    printf("== Halo %s ==\n", user[3]);
    printf("Wallet Ballance : Rp %d\n", walletB[3]);
    printf(" 1. Akun anda\n 2. Beralih ke pembelian\n 3. Beralih ke penjualan\n 4. Top up\n 5. logout\n");
    printf("Pilih : ");
    gets(cM);
    if (*cM < '1' || *cM > '5' || strlen(cM) > 1)
    {
        printf("Menu tidak ada\n\n");
        mainUser();
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    switch (menu)
    {
    case 1:
        akunAnda();
        mainUser();

    case 2:
        buyerPage();
        mainUser();

    case 3:
        sellerPage();
        mainUser();

    case 4:
        topupPage();
        mainUser();

    case 5:
        printf("Anda telah logout\n\n");
        menuRegLog();
    }
}

void topupPage()
{
    char kode[2][11];
    int nominal, nol = 0;

    printf("\n== Topup Wallet ==\n\n");
    printf("Masukan kode : ");
    gets(kode[1]);

    fp1 = fopen("listcode.txt", "r");
    if (!fp1)
    {
        printf("Belum ada daftar kode wallet\n");
        fclose(fp1);
        mainUser();
    }
    while (fscanf(fp1, "%s %d\n", kode[0], &nominal) != EOF)
    {
        if (strcmp(kode[0], kode[1]) == 0 && nominal != 0)
        {
            fclose(fp1);
            ediAkun = 2;
            walletB[1] = walletB[3] + nominal;
            delEdiAkun();
            printf("Top up %d berhasil\n", nominal);
            printf("Jumlah wallet akun anda sekarang %d\n\n", walletB[1]);
            fp1 = fopen("listcode.txt", "r");
            fp2 = fopen("codetemp.txt", "w");
            while (!feof(fp1))
            {
                fscanf(fp1, "%s %d\n", kode[0], &nominal);
                if (strcmp(kode[0], kode[1]) == 0)
                {
                    fprintf(fp2, "%s %d\n", kode[0], nol);
                }
                else
                {
                    fprintf(fp2, "%s %d\n", kode[0], nominal);
                }
            }
            fclose(fp1);
            fclose(fp2);

            remove("listcode.txt");
            rename("codetemp.txt", "listcode.txt");
            mainUser();
        }
    }
    fclose(fp1);
    printf("Kode anda salah\n\n");
    mainUser();
}

void akunAnda()
{
    printf("\n== Akun Anda ==\n");
    printf("Username : %s\n", user[3]);
    printf("Email : %s\n", email[3]);
    printf("Password : ");

    for (int i = 1; i <= strlen(pass[3]); i++)
    {
        printf("*");
    }
    printf("\n");

    int menu;
    char cM[64];

    printf("Pilih\n 1. Edit akun anda\n 2. Hapus akun anda\n 3. Kembali\n");
    printf("Pilih : ");
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
    char kPass[20];
    char ksng[20] = "";

    printf("Masukan password anda\n");
    gets(kPass);
    if (strcmp(kPass, pass[3]) == 0)
    {
        printf("Masukan username dan password baru\n");
        printf("Kosongkan bagian yang tidak diganti\n");
        printf("Input username : ");
        gets(user[1]);
        printf("Input password : ");
        gets(pass[1]);
        nonDuplikat = 0;

        if (strcmp(user[1], ksng) == 0)
        {
            strcpy(user[1], user[3]);
            nonDuplikat++;
        }
        if (strcmp(pass[1], ksng) == 0)
        {
            strcpy(pass[1], pass[3]);
        }

        if (inputUsername() + inputPassword() == 2)
        {
            if (ediAkun != 4)
            {
                strcpy(email[1], email[3]);
                ediAkun = 1;
            }
            delEdiAkun();
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
    char kPass[20];
    int j = 0;

    printf("\nApakah anda yakin ingin menghapus akun ini? jika anda yakin\n");
    printf("Masukan password anda\n");
    gets(kPass);
    if (strcmp(kPass, pass[3]) == 0)
    {
        strcpy(user[1], kosong);
        strcpy(pass[1], kosong);
        strcpy(email[1], kosong);
        ediAkun = 1;
        delEdiAkun();
        printf("\nAkun anda telah dihapus\n\n");

        fp1 = fopen("listuser.txt", "r");
        while (fscanf(fp1, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]) != EOF)
        {
            if (strcmp(kosong, user[0]) != 0)
            {
                j++;
            }
        }
        fclose(fp1);
        if (j == 0)
        {
            remove("listuser.txt");
            printf("Dan semua data telah dihapus\n\n");
        }
        delGig = 2;
        deleteGig();
        menuRegLog();
    }
    else
    {
        printf("\nPassword anda salah\n");
    }
}

void delEdiAkun()
{
    fp1 = fopen("listuser.txt", "r");
    fp2 = fopen("lotemp.txt", "a+");

    switch (ediAkun)
    {
    case 1:
        while (!feof(fp1))
        {
            fscanf(fp1, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]);
            if (strcmp(email[3], email[0]) == 0)
            {
                fprintf(fp2, "%s %s %s %d\n", user[1], pass[1], email[1], walletB[0]);
                strcpy(user[3], user[1]);
                strcpy(pass[3], pass[1]);
            }
            else
            {
                fprintf(fp2, "%s %s %s %d\n", user[0], pass[0], email[0], walletB[0]);
            }
        }
        break;

    case 2:
        while (!feof(fp1))
        {
            fscanf(fp1, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]);
            if (strcmp(email[3], email[0]) == 0)
            {
                fprintf(fp2, "%s %s %s %d\n", user[0], pass[0], email[0], walletB[1]);
                walletB[3] = walletB[1];
            }
            else
            {
                fprintf(fp2, "%s %s %s %d\n", user[0], pass[0], email[0], walletB[0]);
            }
        }

    case 3:
        while (!feof(fp1))
        {
            fscanf(fp1, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]);
            if (strcmp(email[6], email[0]) == 0)
            {
                fprintf(fp2, "%s %s %s %d\n", user[0], pass[0], email[0], walletB[1]);
            }
            else
            {
                fprintf(fp2, "%s %s %s %d\n", user[0], pass[0], email[0], walletB[0]);
            }
        }
        break;

    case 4:
        fscanf(fp1, "%s %s %d %d\n", user[0], pass[0], &profitAdmin[0], &moneyHold[0]);
        fprintf(fp2, "%s %s %d %d\n", user[1], pass[1], profitAdmin[0], moneyHold[0]);
        while (!feof(fp1))
        {
            fscanf(fp1, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]);
            fprintf(fp2, "%s %s %s %d\n", user[0], pass[0], email[0], walletB[0]);
        }
        strcpy(user[3], user[1]);
        strcpy(pass[3], pass[1]);
        break;

    case 5:
        fscanf(fp1, "%s %s %d %d\n", user[0], pass[0], &profitAdmin[0], &moneyHold[0]);
        fprintf(fp2, "%s %s %d %d\n", user[0], pass[0], profitAdmin[1], moneyHold[1]);
        while (!feof(fp1))
        {
            fscanf(fp1, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]);
            fprintf(fp2, "%s %s %s %d\n", user[0], pass[0], email[0], walletB[0]);
        }
        break;
    }

    fclose(fp1);
    fclose(fp2);

    remove("listuser.txt");
    rename("lotemp.txt", "listuser.txt");
}

void sellerPage()
{
    int menu;
    char cM[64];
    int j = 0;

    printf("\n== Dashboard %s (sebagai penjual) ==\n", user[3]);
    fp1 = fopen("listorder.txt", "r");
    while (fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", kodeOrder[0], email[5], email[6], pesanOrder[0], materialOrder[0], demoFinal[0], finalOrder[0], &konfFinal[0]) != EOF)
    {
        if (strcmp(email[3], email[6]) == 0 && strcmp(kodeOrder[0], kosong) != 0 && strcmp(demoFinal[0], kosong) == 0 && konfFinal[0] != 1)
        {
            j++;
        }
    }
    fclose(fp1);
    if (j != 0)
    {
        printf("Anda memiliki %d orderan yang belum memasukan hasil demo dan final\n", j);
    }
    printf(" 1. Orders\n 2. Gigs\n 3. Buat Gig\n 4. Kembali\n");
    printf("Pilih : ");
    gets(cM);
    if (*cM < '1' || *cM > '4' || strlen(cM) > 1)
    {
        printf("Menu tidak ada\n\n");
        sellerPage();
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    switch (menu)
    {
    case 1:
        sellerOrder();
        sellerPage();

    case 2:
        sellerGig();
        sellerPage();

    case 3:
        createGig();
        sellerPage();

    case 4:
        printf("Kembali\n\n");
        mainUser();
    }
}

void sellerOrder()
{
    int j, punya = 0;
    int halaman = 1;
next:
    printf("\n== Pesanan (%d) ==\n", halaman);
    fp1 = fopen("listorder.txt", "r");
    for (int i = 1; i <= halaman; i++)
    {
        for (int i = 1; i < 6; i++)
        {
            strcpy(vTitle[i], kosong);
        }
        j = 0;
        while (fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", kodeOrder[0], email[5], email[6], pesanOrder[0], materialOrder[0], demoFinal[0], finalOrder[0], &konfFinal[0]) != EOF)
        {
            if (strcmp(email[3], email[6]) == 0 && strcmp(kodeOrder[0], kosong) != 0)
            {
                j++;
                punya++;
                if (i == halaman)
                {
                    fp2 = fopen("listuser.txt", "r");
                    while (fscanf(fp2, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]) != 0)
                    {
                        if (strcmp(email[5], email[0]) == 0)
                        {
                            break;
                        }
                    }
                    fclose(fp2);
                    printf("%d. %s - %s - %s", j, kodeOrder[0], email[0], user[0]);
                    if (konfFinal[0] == 0)
                    {
                        if (strcmp(demoFinal[0], kosong) != 0)
                        {
                            printf(" (menunggu konfirmasi)\n");
                        }
                        else
                        {
                            printf(" (proses)\n");
                        }
                    }
                    else
                    {
                        printf(" (selesai)\n");
                    }
                    strcpy(vKodeOrder[j], kodeOrder[0]);
                }
                if (j % 5 == 0)
                {
                    break;
                }
            }
        }
    }
    fclose(fp1);

    if (punya == 0)
    {
        printf("Belum ada pesanan untuk gig anda\n");
        sellerPage();
    }

    if (j == 0)
    {
        printf("Pesanan tidak ada\nKembali\n");
        halaman--;
        goto next;
    }

    int menu;
    char cM[64];
balik:
    printf("\nMenu:\n 1 - 5 Buka pesanan\n 6. Pesanan sebelumnya\n 7. Pesanan selanjutnya\n 8. Kembali\n");
    printf("Pilih : ");
    gets(cM);
    if (*cM < '1' || *cM > '8' || strlen(cM) > 1)
    {
        printf("Pilihan tidak ada\n\n");
        goto balik;
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    if (menu == 6)
    {
        if (halaman == 1)
        {
            printf("\nAnda sudah berada di halaman pertama\n");
            sellerOrder();
        }
        else
        {
            halaman--;
            goto next;
        }
    }

    if (menu == 7)
    {
        halaman++;
        goto next;
    }

    if (menu > 0 && menu < 6)
    {
        if (strcmp(vKodeOrder[menu], kosong) != 0)
        {
            strcpy(kodeOrder[2], vKodeOrder[menu]);
            openSellerOrder();
        }
        else
        {
            printf("Gig tidak ada\n");
            goto balik;
        }
    }
    if (menu == 8)
    {
        printf("Kembali\n");
        sellerPage();
    }
}

void openSellerOrder()
{
    char ksng[] = "";
    openOrderEdi();
    int menu;
    char cM[64];

    if (konfFinal[0] == 1)
    {
        printf("Pilihan\n 1. Kembali\nPilih : ");

        gets(cM);
        if (*cM < '1' || *cM > '1' || strlen(cM) > 1)
        {
            printf("Pilihan tidak ada\n\n");
            openSellerOrder();
        }
        else
        {
            sscanf(cM, "%d", &menu);
        }

        if (menu == 1)
        {
            sellerOrder();
        }
    }

    if (strcmp(finalOrder[0], kosong) != 0)
    {
        printf("Pilihan\n 1. Revisi link demo dan final\n 2. Kembali\nPilih : ");
    }
    else
    {
        printf("Pilihan\n 1. Masukan link demo dan final\n 2. Kembali\nPilih : ");
    }

    gets(cM);
    if (*cM < '1' || *cM > '2' || strlen(cM) > 1)
    {
        printf("Pilihan tidak ada\n\n");
        openSellerOrder();
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    int pilih;
    char cP[64];
    switch (menu)
    {
    case 1:
        printf("Hasil demo  : ");
        gets(demoFinal[2]);
        printf("Hasil final : ");
        gets(finalOrder[2]);
        if (strcmp(demoFinal[2], ksng) == 0 || strcmp(finalOrder[2], ksng) == 0)
        {
            printf("Link demo atau final tidak boleh kosong\n");
            openSellerOrder();
        }
    balik:
        printf("Apakah anda yakin megirim hasilnya?\n 1. Ya\n 2. Tidak\nPilih : ");
        gets(cP);
        if (*cP < '1' || *cP > '2' || strlen(cP) > 1)
        {
            printf("Pilihan tidak ada\n\n");
            goto balik;
        }
        else
        {
            sscanf(cP, "%d", &pilih);
        }

        switch (pilih)
        {
        case 1:
            ediOrder = 1;
            strcpy(kodeOrder[3], kodeOrder[0]);
            editOrder();
            break;

        default:
            printf("Batal mengirim\n");
            break;
        }
        openSellerOrder();

    case 2:
        sellerOrder();
        break;
    }
}

void createGig()
{
    char title[99];
    printf("\n== Membuat Gig Baru ==\n");

    printf("Judul gig   : Saya akan ");
    gets(title);
    strcpy(titleGig[1], "Saya akan ");
    strcat(titleGig[1], title);
kategori:
    printf("Kategori\n 1. Desain Grafis\n 2. Video dan Animasi\n 3. Music dan Suara\n 4. Programing dan Website\n");
    printf("Pilih : ");
    char *kat[] = {"Desain Grafis", "Video dan Animasi", "Music dan Suara", "Programing dan Website"};
    int menu, j = 1, k = 1;
    char cM[64], tigaH[3];
    gets(cM);
    if (*cM < '1' || *cM > '4' || strlen(cM) > 1)
    {
        printf("Kategori tidak ada\n\n");
        goto kategori;
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    strcpy(kategoriGig[1], kat[menu - 1]);
    printf("Kategori    : %s\n", kategoriGig[1]);
    printf("Harga       : Rp ");
    scanf("%d", &hargaGig[1]);
    fflush(stdin);
    fp1 = fopen("listgig.txt", "a+");
    while (fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%d\n", email[4], kodeGig[0], titleGig[0], kategoriGig[0], &hargaGig[0]) != EOF)
    {
        k++;
        if (strcmp(email[4], email[3]) == 0)
        {
            j++;
        }
    }
    strcpy(tigaH, email[3]);
    sprintf(kodeGig[1], "%.3s%.3d%.4d", strupr(tigaH), j, k);
gigbaru:
    printf("\nGig baru anda :\n");
    printf("Judul gig   : %s\n", titleGig[1]);
    printf("Kategori    : %s\n", kategoriGig[1]);
    printf("Harga       : Rp %d\n", hargaGig[1]);
    printf("Kode gig    : %s\n", kodeGig[1]);
    printf("Publikasikan?\n 1. Ya\n 2. Tidak\nPilih : ");
    int pilih;
    char cP[64];
    gets(cP);
    if (*cP < '1' || *cP > '2' || strlen(cP) > 1)
    {
        printf("Pilihan tidak ada\n\n");
        goto gigbaru;
    }
    else
    {
        sscanf(cP, "%d", &pilih);
    }

    switch (pilih)
    {
    case 1:
        fprintf(fp1, "%s#%s#%s#%s#%d\n", email[3], kodeGig[1], titleGig[1], kategoriGig[1], hargaGig[1]);
        printf("Gig telah dipublikasikan\n");
        break;

    default:
        printf("Tidak dipublikasikan\n");
        break;
    }
    fclose(fp1);
}

void sellerGig()
{
    int j, punya = 0;
    int halaman = 1;
next:
    printf("\n== Gigs (%d) ==\n", halaman);
    fp1 = fopen("listgig.txt", "r");
    for (int i = 1; i <= halaman; i++)
    {
        for (int i = 1; i < 6; i++)
        {
            strcpy(vTitle[i], kosong);
        }
        j = 0;
        while (fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%d\n", email[4], kodeGig[0], titleGig[0], kategoriGig[0], &hargaGig[0]) != EOF)
        {
            if (strcmp(email[4], email[3]) == 0 && strcmp(titleGig[0], kosong) != 0)
            {
                j++;
                punya++;
                if (i == halaman)
                {
                    printf("%d. %s - %s - Rp %d\n", j, kodeGig[0], titleGig[0], hargaGig[0]);
                    strcpy(vKode[j], kodeGig[0]);
                    strcpy(vTitle[j], titleGig[0]);
                    vHarga[j] = hargaGig[0];
                }
                if (j % 5 == 0)
                {
                    break;
                }
            }
        }
    }
    fclose(fp1);

    if (punya == 0)
    {
        printf("Anda belum mempunyai gig\n");
        sellerPage();
    }

    if (j == 0)
    {
        printf("Gig tidak ada\nKembali\n");
        halaman--;
        goto next;
    }

    int menu;
    char cM[64];
balik:
    printf("\nMenu:\n 1 - 5 Buka gig\n 6. Gigs sebelumnya\n 7. Gigs selanjutnya\n 8. Kembali\n");
    printf("Pilih : ");
    gets(cM);
    if (*cM < '1' || *cM > '8' || strlen(cM) > 1)
    {
        printf("Pilihan tidak ada\n\n");
        goto balik;
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    if (menu == 6)
    {
        if (halaman == 1)
        {
            printf("\nAnda sudah berada di halaman pertama\n");
            sellerGig();
        }
        else
        {
            halaman--;
            goto next;
        }
    }

    if (menu == 7)
    {
        halaman++;
        goto next;
    }

    if (menu > 0 && menu < 6)
    {
        if (strcmp(vTitle[menu], kosong) != 0)
        {
            strcpy(titleGig[2], vTitle[menu]);
            strcpy(kodeGig[2], vKode[menu]);
            hargaGig[2] = vHarga[menu];
            openSellerGig();
        }
        else
        {
            printf("Gig tidak ada\n");
            goto balik;
        }
    }
    if (menu == 8)
    {
        printf("Kembali\n");
        sellerPage();
    }
}

void openSellerGig()
{
rewind:
    openGigEdi();
    int menu;
    char cM[64];

    printf("Pilihan\n 1. Hapus Gig\n 2. Kembali\nPilih : ");

    gets(cM);
    if (*cM < '1' || *cM > '2' || strlen(cM) > 1)
    {
        printf("Pilihan tidak ada\n\n");
        goto rewind;
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    int pilih;
    char cP[64];
    switch (menu)
    {
    case 1:
    hapus:
        printf("Apakah anda yakin menghapus gig ini?\n 1. Ya\n 2. Tidak\nPilih : ");
        gets(cP);
        if (*cP < '1' || *cP > '2' || strlen(cP) > 1)
        {
            printf("Pilihan tidak ada\n\n");
            goto hapus;
        }
        else
        {
            sscanf(cP, "%d", &pilih);
        }

        switch (pilih)
        {
        case 1:
            printf("Gig %s telah dihapus\n", kodeGig[0]);
            delGig = 1;
            deleteGig();
            sellerGig();
            break;

        default:
            printf("Gig tidak dihapus\n");
            goto rewind;
        }

    case 2:
        printf("Kembali\n");
        sellerGig();
    }
}

void openGigEdi()
{
    fp1 = fopen("listgig.txt", "r");
    while (!feof(fp1))
    {
        fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%d\n", email[4], kodeGig[0], titleGig[0], kategoriGig[0], &hargaGig[0]);
        if (strcmp(titleGig[0], titleGig[2]) == 0 && strcmp(kodeGig[0], kodeGig[2]) == 0 && hargaGig[0] == hargaGig[2])
        {
            fclose(fp1);
            break;
        }
    }
    fp1 = fopen("listuser.txt", "r");
    while (!feof(fp1))
    {
        fscanf(fp1, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]);
        if (strcmp(email[4], email[0]) == 0)
        {
            fclose(fp1);
            break;
        }
    }

    printf("\n== Gig %s ==\n", kodeGig[0]);
    printf("\n%s\n", titleGig[0]);
    printf("%s\n", user[0]);
    printf("Email : %s\n", email[0]);
    printf("Harga : %d\n", hargaGig[0]);
}

void deleteGig()
{
    fp1 = fopen("listgig.txt", "r");
    fp2 = fopen("gigtemp.txt", "a+");
    while (!feof(fp1))
    {
        fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%d\n", email[4], kodeGig[0], titleGig[0], kategoriGig[0], &hargaGig[0]);
        switch (delGig)
        {
        case 1:
            if (strcmp(titleGig[0], titleGig[2]) == 0 && strcmp(kodeGig[0], kodeGig[2]) == 0 && hargaGig[0] == hargaGig[2])
            {
                fprintf(fp2, "%s#%s#%s#%s#%d\n", email[4], kosong, kosong, kosong, hargaGig[0]);
            }
            else
            {
                fprintf(fp2, "%s#%s#%s#%s#%d\n", email[4], kodeGig[0], titleGig[0], kategoriGig[0], hargaGig[0]);
            }
            break;

        case 2:
            if (strcmp(email[3], email[4]) == 0)
            {
                fprintf(fp2, "%s#%s#%s#%s#%d\n", kosong, kosong, kosong, kosong, hargaGig[0]);
            }
            else
            {
                fprintf(fp2, "%s#%s#%s#%s#%d\n", email[4], kodeGig[0], titleGig[0], kategoriGig[0], hargaGig[0]);
            }
            break;

        default:
            break;
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("listgig.txt");
    rename("gigtemp.txt", "listgig.txt");
}

void buyerPage()
{
    int menu;
    char cM[64];
    int j = 0;

    printf("\n== Dashboard %s (sebagai Pembeli) ==\n", user[3]);
    fp1 = fopen("listorder.txt", "r");
    while (!feof(fp1))
    {
        fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", kodeOrder[0], email[5], email[6], pesanOrder[0], materialOrder[0], demoFinal[0], finalOrder[0], &konfFinal[0]);
        if (strcmp(email[3], email[5]) == 0 && strcmp(kodeOrder[0], kosong) != 0 && strcmp(demoFinal[0], kosong) != 0 && konfFinal[0] == 0)
        {
            j++;
        }
    }
    fclose(fp1);
    if (j != 0)
    {
        printf("Anda memiliki %d orderan yang hasil demonya belum dikonfirmasi\n", j);
    }
    printf(" 1. Orders\n 2. Jelajahi marketplace\n 3. kembali\n");
    printf("Pilih : ");
    gets(cM);
    if (*cM < '1' || *cM > '3' || strlen(cM) > 1)
    {
        printf("Menu tidak ada\n\n");
        buyerPage();
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    switch (menu)
    {
    case 1:
        buyerOrder();
        buyerPage();

    case 2:
        buyerKatGig();
        buyerPage();

    case 3:
        printf("Kembali\n\n");
        mainUser();
    }
}

void buyerOrder()
{
    int j, punya = 0;
    int halaman = 1;
next:
    printf("\n== Pesanan anda (%d) ==\n", halaman);
    fp1 = fopen("listorder.txt", "r");
    for (int i = 1; i <= halaman; i++)
    {
        for (int i = 1; i < 6; i++)
        {
            strcpy(vTitle[i], kosong);
        }
        j = 0;
        while (fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", kodeOrder[0], email[5], email[6], pesanOrder[0], materialOrder[0], demoFinal[0], finalOrder[0], &konfFinal[0]) != EOF)
        {
            if (strcmp(email[3], email[5]) == 0 && strcmp(kodeOrder[0], kosong) != 0)
            {
                j++;
                punya++;
                if (i == halaman)
                {
                    fp2 = fopen("listuser.txt", "r");
                    while (fscanf(fp2, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]) != 0)
                    {
                        if (strcmp(email[6], email[0]) == 0)
                        {
                            break;
                        }
                    }
                    fclose(fp2);
                    printf("%d. %s - %s - %s", j, kodeOrder[0], email[0], user[0]);
                    if (konfFinal[0] == 0)
                    {
                        if (strcmp(demoFinal[0], kosong) != 0)
                        {
                            printf(" (menunggu konfirmasi)\n");
                        }
                        else
                        {
                            printf(" (proses)\n");
                        }
                    }
                    else
                    {
                        printf(" (selesai)\n");
                    }
                    strcpy(vKodeOrder[j], kodeOrder[0]);
                }
                if (j % 5 == 0)
                {
                    break;
                }
            }
        }
    }
    fclose(fp1);

    if (punya == 0)
    {
        printf("Belum ada pesanan yang anda buat\n");
        buyerPage();
    }

    if (j == 0)
    {
        printf("Pesanan tidak ada\nKembali\n");
        halaman--;
        goto next;
    }

    int menu;
    char cM[64];
balik:
    printf("\nMenu:\n 1 - 5 Buka pesanan\n 6. Pesanan sebelumnya\n 7. Pesanan selanjutnya\n 8. Kembali\n");
    printf("Pilih : ");
    gets(cM);
    if (*cM < '1' || *cM > '8' || strlen(cM) > 1)
    {
        printf("Pilihan tidak ada\n\n");
        goto balik;
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    if (menu == 6)
    {
        if (halaman == 1)
        {
            printf("\nAnda sudah berada di halaman pertama\n");
            buyerOrder();
        }
        else
        {
            halaman--;
            goto next;
        }
    }

    if (menu == 7)
    {
        halaman++;
        goto next;
    }

    if (menu > 0 && menu < 6)
    {
        if (strcmp(vKodeOrder[menu], kosong) != 0)
        {
            strcpy(kodeOrder[2], vKodeOrder[menu]);
            openBuyerOrder();
        }
        else
        {
            printf("Gig tidak ada\n");
            goto balik;
        }
    }
    if (menu == 8)
    {
        printf("Kembali\n");
        buyerPage();
    }
}

void openBuyerOrder()
{
    openOrderEdi();
    int menu;
    char cM[64];

    if ((strcmp(demoFinal[0], kosong) == 0 && strcmp(finalOrder[0], kosong) == 0) || konfFinal[0] == 1)
    {
        printf("Pilihan\n 1. Kembali\nPilih : ");

        gets(cM);
        if (*cM < '1' || *cM > '1' || strlen(cM) > 1)
        {
            printf("Pilihan tidak ada\n\n");
            openBuyerOrder();
        }
        else
        {
            sscanf(cM, "%d", &menu);
        }

        if (menu == 1)
        {
            buyerOrder();
        }
    }
    else
    {
        printf("Jika demo tidak sesuai, silahkan email %s untuk meminta revisi\n", email[6]);
        printf("Pilihan\n 1. Konfirmasi Hasil Demo\n 2. Kembali\nPilih : ");

        gets(cM);
        if (*cM < '1' || *cM > '2' || strlen(cM) > 1)
        {
            printf("Pilihan tidak ada\n\n");
            openBuyerOrder();
        }
        else
        {
            sscanf(cM, "%d", &menu);
        }

        int pilih;
        char cP[64];
        switch (menu)
        {
        case 1:
        balik:
            printf("Apakah anda yakin dengan hasil demonya?\n 1. Ya\n 2. Tidak\nPilih : ");
            gets(cP);
            if (*cP < '1' || *cP > '2' || strlen(cP) > 1)
            {
                printf("Pilihan tidak ada\n\n");
                goto balik;
            }
            else
            {
                sscanf(cP, "%d", &pilih);
            }

            switch (pilih)
            {
            case 1:
                fp1 = fopen("listuser.txt", "r");
                while (!feof(fp1))
                {
                    fscanf(fp1, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]);
                    if (strcmp(email[6], email[0]) == 0)
                    {
                        break;
                    }
                }
                fclose(fp1);
                walletB[1] = walletB[0] + hargaGig[0] - (hargaGig[0] * 10 / 100);
                ediAkun = 3;
                delEdiAkun();

                fp1 = fopen("listuser.txt", "r");
                fscanf(fp1, "%s %s %d %d\n", user[0], pass[0], &profitAdmin[0], &moneyHold[0]);
                fclose(fp1);
                moneyHold[1] = moneyHold[0] - hargaGig[0];
                profitAdmin[1] = profitAdmin[0] + (hargaGig[0] * 10 / 100);
                ediAkun = 5;
                delEdiAkun();

                ediOrder = 2;
                strcpy(kodeOrder[3], kodeOrder[0]);
                editOrder();
                break;

            default:
                printf("Tidak dikonfirmasi\n");
                break;
            }
            openBuyerOrder();

        case 2:
            buyerOrder();
            break;
        }
    }
}

void openOrderEdi()
{
    fp1 = fopen("listorder.txt", "r");
    while (!feof(fp1))
    {
        fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", kodeOrder[0], email[5], email[6], pesanOrder[0], materialOrder[0], demoFinal[0], finalOrder[0], &konfFinal[0]);
        if (strcmp(kodeOrder[0], kodeOrder[2]) == 0)
        {
            fclose(fp1);
            break;
        }
    }
    fp1 = fopen("listgig.txt", "r");

    strncpy(kodeGig[3], kodeOrder[0], 10);

    while (!feof(fp1))
    {
        fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%d\n", email[4], kodeGig[0], titleGig[0], kategoriGig[0], &hargaGig[0]);
        if (strcmp(kodeGig[3], kodeGig[0]) == 0)
        {
            fclose(fp1);
            break;
        }
    }

    printf("\n== Pesanan %s ==\n", kodeOrder[0]);
    printf("Pesan       : %s\n", pesanOrder[0]);
    printf("Material    : %s\n", materialOrder[0]);
    printf("Hasil Demo  : %s\n", demoFinal[0]);
    if (strcmp(email[3], email[6]) == 0 || konfFinal[0] == 1)
    {
        printf("Hasil Final : %s\n", finalOrder[0]);
    }
    else
    {
        printf("Hasil Final : %s", kosong);
        if (strcmp(demoFinal[0], kosong) != 0)
        {
            printf(" (konfirmasi hasil demo)\n");
        }
        else
        {
            printf("\n");
        }
    }
}

void editOrder()
{
    int satu = 1;
    fp1 = fopen("listorder.txt", "r");
    fp2 = fopen("ordertemp.txt", "a+");
    while (!feof(fp1))
    {
        fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", kodeOrder[0], email[5], email[6], pesanOrder[0], materialOrder[0], demoFinal[0], finalOrder[0], &konfFinal[0]);
        switch (ediOrder)
        {
        case 1:
            if (strcmp(email[3], email[6]) == 0 && strcmp(kodeOrder[0], kodeOrder[3]) == 0)
            {
                fprintf(fp2, "%s#%s#%s#%s#%s#%s#%s#%d\n", kodeOrder[0], email[5], email[6], pesanOrder[0], materialOrder[0], demoFinal[2], finalOrder[2], konfFinal[0]);
            }
            else
            {
                fprintf(fp2, "%s#%s#%s#%s#%s#%s#%s#%d\n", kodeOrder[0], email[5], email[6], pesanOrder[0], materialOrder[0], demoFinal[0], finalOrder[0], konfFinal[0]);
            }
            break;

        case 2:
            if (strcmp(email[3], email[5]) == 0 && strcmp(kodeOrder[0], kodeOrder[3]) == 0)
            {
                fprintf(fp2, "%s#%s#%s#%s#%s#%s#%s#%d\n", kodeOrder[0], email[5], email[6], pesanOrder[0], materialOrder[0], demoFinal[0], finalOrder[0], satu);
            }
            else
            {
                fprintf(fp2, "%s#%s#%s#%s#%s#%s#%s#%d\n", kodeOrder[0], email[5], email[6], pesanOrder[0], materialOrder[0], demoFinal[0], finalOrder[0], konfFinal[0]);
            }
            break;

        default:
            break;
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("listorder.txt");
    rename("ordertemp.txt", "listorder.txt");
}

void buyerKatGig()
{
    int menu;
    char cM[64];
    char *kat[] = {"Desain Grafis", "Video dan Animasi", "Music dan Suara", "Programing dan Website"};

    printf("\n== Jelajahi Marketplace ==\n");
    printf("Kategori Gig\n 1. Desain Grafis\n 2. Video dan Animasi\n 3. Music dan Suara\n 4. Programing dan Website\n 5. Kembali\n");
    printf("Pilih : ");
    gets(cM);
    if (*cM < '1' || *cM > '5' || strlen(cM) > 1)
    {
        printf("Menu tidak ada\n\n");
        buyerKatGig();
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    switch (menu)
    {
    case 5:
        printf("Kembali\n\n");
        break;
    default:
        strcpy(kategoriGig[3], kat[menu - 1]);
        buyerGig();
        break;
    }
}

void buyerGig()
{
    int j, punya = 0;
    int halaman = 1;
next:
    printf("\n== Gigs %s (%d) ==\n", kategoriGig[3], halaman);
    fp1 = fopen("listgig.txt", "r");
    for (int i = 1; i <= halaman; i++)
    {
        for (int i = 1; i < 6; i++)
        {
            strcpy(vTitle[i], kosong);
        }
        j = 0;
        while (fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%d\n", email[4], kodeGig[0], titleGig[0], kategoriGig[0], &hargaGig[0]) != EOF)
        {
            if (strcmp(kategoriGig[0], kategoriGig[3]) == 0 && strcmp(titleGig[0], kosong) != 0 && strcmp(email[3], email[4]) != 0)
            {
                j++;
                punya++;
                if (i == halaman)
                {
                    fp2 = fopen("listuser.txt", "r");
                    while (fscanf(fp2, "%s %s %s %d\n", user[0], pass[0], email[0], &walletB[0]) != 0)
                    {
                        if (strcmp(email[4], email[0]) == 0)
                        {
                            break;
                        }
                    }
                    fclose(fp2);
                    printf("%d. %s - %s - Rp %d\n", j, user[0], titleGig[0], hargaGig[0]);
                    strcpy(vKode[j], kodeGig[0]);
                    strcpy(vTitle[j], titleGig[0]);
                    vHarga[j] = hargaGig[0];
                }
                if (j % 5 == 0)
                {
                    break;
                }
            }
        }
    }
    fclose(fp1);

    if (punya == 0)
    {
        printf("Belum ada gig pada kategori %s\n", kategoriGig[3]);
        buyerPage();
    }

    if (j == 0)
    {
        printf("Gig tidak ada\nKembali\n");
        halaman--;
        goto next;
    }

    int menu;
    char cM[64];
balik:
    printf("\nMenu:\n 1 - 5 Buka gig\n 6. Gigs sebelumnya\n 7. Gigs selanjutnya\n 8. Kembali\n");
    printf("Pilih : ");
    gets(cM);
    if (*cM < '1' || *cM > '8' || strlen(cM) > 1)
    {
        printf("Pilihan tidak ada\n\n");
        sellerGig();
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    if (menu == 6)
    {
        if (halaman == 1)
        {
            printf("\nAnda sudah berada di halaman pertama\n");
            sellerGig();
        }
        else
        {
            halaman--;
            goto next;
        }
    }

    if (menu == 7)
    {
        halaman++;
        goto next;
    }

    if (menu == 8)
    {
        buyerPage();
    }

    if (menu > 0 && menu < 6)
    {
        if (strcmp(vTitle[menu], kosong) != 0)
        {
            strcpy(titleGig[2], vTitle[menu]);
            strcpy(kodeGig[2], vKode[menu]);
            hargaGig[2] = vHarga[menu];
            openBuyerGig();
        }
        else
        {
            printf("Gig tidak ada\n");
            goto balik;
        }
    }
}

void openBuyerGig()
{
rewind:
    openGigEdi();
    int menu;
    char cM[64];

    printf("Pilihan\n 1. Order\n 2. Kembali\nPilih : ");

    gets(cM);
    if (*cM < '1' || *cM > '2' || strlen(cM) > 1)
    {
        printf("Pilihan tidak ada\n\n");
        goto rewind;
    }
    else
    {
        sscanf(cM, "%d", &menu);
    }

    switch (menu)
    {
    case 1:
        orderGig();
        break;

    case 2:
        buyerGig();
        break;
    }
}

void orderGig()
{
    int j = 1;
    int konfirmasi = 0;
    char ksng[] = "";

    printf("\n== Order %s ==\n\n", kodeGig[0]);
    printf("Silahkan tinggalkan pesan dan link material (kondisional)\n");
    printf("Pesan       : ");
    gets(pesanOrder[1]);
    if (strcmp(pesanOrder[1], ksng) == 0)
    {
        printf("Pesan/catatan harus di isi\n");
        openBuyerGig();
    }
    printf("Material    : ");
    gets(materialOrder[1]);
    if (strcmp(materialOrder[1], ksng) == 0)
    {
        strcpy(materialOrder[1], kosong);
    }

    fp1 = fopen("listorder.txt", "r");
    while (fscanf(fp1, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", kodeOrder[0], email[5], email[6], pesanOrder[0], materialOrder[0], demoFinal[0], finalOrder[0], &konfFinal[0]) != EOF)
    {
        j++;
    }
    fclose(fp1);
    sprintf(kodeOrder[1], "%s%.3d", kodeGig[0], j);
orderbaru:
    printf("\nPesanan anda :\n");
    printf("Kode pesanan : %s\n", kodeOrder[1]);
    printf("Pesan        : %s\n", pesanOrder[1]);
    printf("Material     : %s\n", materialOrder[1]);
    printf("Bayar pesanan Rp %d?\n 1. Ya\n 2. Tidak\nPilih : ", hargaGig[0]);
    int pilih;
    char cP[64];
    gets(cP);
    if (*cP < '1' || *cP > '2' || strlen(cP) > 1)
    {
        printf("Pilihan tidak ada\n\n");
        goto orderbaru;
    }
    else
    {
        sscanf(cP, "%d", &pilih);
    }

    switch (pilih)
    {
    case 1:
        walletB[1] = walletB[3] - hargaGig[0];
        if (walletB[1] < 0)
        {
            printf("Saldo wallet anda tidak mecukupi, anda mempunyai Rp %d\n", walletB[3]);
        }
        else
        {
            fp1 = fopen("listorder.txt", "a");
            fprintf(fp1, "%s#%s#%s#%s#%s#%s#%s#%d\n", kodeOrder[1], email[3], email[0], pesanOrder[1], materialOrder[1], kosong, kosong, konfirmasi);
            fclose(fp1);
            ediAkun = 2;
            delEdiAkun();

            fp1 = fopen("listuser.txt", "r");
            fscanf(fp1, "%s %s %d %d\n", user[0], pass[0], &profitAdmin[0], &moneyHold[0]);
            fclose(fp1);
            moneyHold[1] = moneyHold[0] + hargaGig[0];
            profitAdmin[1] = profitAdmin[0];
            ediAkun = 5;
            delEdiAkun();

            printf("Pesanan telah dikirim\n");
        }
        break;

    default:
        printf("Pesanan dibatalkan\n");
        break;
    }
}