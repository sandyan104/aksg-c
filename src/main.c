#include <stdio.h>
#include <stdlib.h>
#include "auth/auth.h"
#include "app/app.h"
#include "structs/structs.h"

char username[20], password[10], targetTanggal[20];
int isUser, pilihan, jumlahData = 0;

struct Pemesanan pesanan[10];

int main()
{
  do
  {
    printf("\n");
    printf("   _____ _____ _____ _____ \n");
    printf("  |  _  |  |  |   __|   __|\n");
    printf("  |     |    -|__   |  |  |\n");
    printf("  |__|__|__|__|_____|_____|\n");
    printf("\n Aplikasi Kelola Sewa Gedung\n");
    printf("______________________________\n\n");
    printf("Username: ");
    scanf("%s", &username);
    printf("Password: ");
    scanf("%s", &password);

    isUser = login(username, password);
    if (isUser == 1)
    {
      do
      {
        system("cls");
        printf("\n");
        printf("   _____ _____ _____ _____ \n");
        printf("  |  _  |  |  |   __|   __|\n");
        printf("  |     |    -|__   |  |  |\n");
        printf("  |__|__|__|__|_____|_____|\n");
        printf("\n Aplikasi Kelola Sewa Gedung\n");
        printf("______________________________\n\n");
        printf("[1] Sewa Gedung\n");
        printf("[2] Data Penyewaan\n");
        printf("[3] Data Penyewaan (Berurut)\n");
        printf("[4] Cari Pemesanan\n");
        printf("[5] Ubah Pemesanan\n");
        printf("[6] Pembatalan Sewa\n");
        printf("[7] Export Data Penyewaan\n");
        printf("[8] Cek Aplikasi Versi Web\n");
        printf("[9] Keluar\n");

        printf("\nMasukkan Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {

        // Input
        case 1:
          inputData(pesanan, &jumlahData);
          system("pause");
          system("cls");
          break;

        // Data
        case 2:
          tampilData(pesanan, jumlahData);
          system("pause");
          system("cls");
          break;

        // Sorting
        case 3:
          bubbleSort(pesanan, jumlahData);
          system("pause");
          system("cls");
          break;

        // Searching
        case 4:
          printf("\nMasukkan tanggal penyewaan yang dicari (format: YYYY/MM/DD): ");
          scanf("%s", targetTanggal);

          // Mencari data berdasarkan tanggal penyewaan dengan Sequential Search
          int hasilPencarian = sequentialSearch(pesanan, jumlahData, targetTanggal);

          if (hasilPencarian != -1)
          {
            printf("Data ditemukan pada indeks %d\n", hasilPencarian);
          }
          else
          {
            printf("Data tidak ditemukan.\n");
          }
          system("pause");
          system("cls");
          break;

        // Ubah
        case 5:
          editData(pesanan, jumlahData);
          system("pause");
          system("cls");
          break;

        // Delete
        case 6:
          hapusData(pesanan, jumlahData);
          system("pause");
          system("cls");
          break;

        // Export
        case 7:
          simpanKeFile(pesanan, jumlahData, "../export/data_pemesanan.txt");
          system("pause");
          system("cls");
          break;

        // Web
        case 8:
          printf("\nGunakan akun berikut untuk masuk ke versi web\n\nEmail : c-ver@aksg.app\nPassword : cintaalpro\n\n");
          system("start https://aksg.netlify.app");
          system("pause");
          break;

        // Exit
        case 9:
          system("cls");
          exit(0);
          break;

        default:
          printf("Pilihan tidak tersedia!");
          break;
        }
      } while (pilihan != 9);
    }
    else
    {
      system("cls");
      printf("Username atau password salah!\n");
    }
  } while (isUser != 1);
}
