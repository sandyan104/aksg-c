#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

// int price = 0;
char pil[1];

// void hargaSewa()
// {
//   printf("Harga sewa saat Ini : %d", price);
//   printf("\nUbah harga? y/t : ");
//   scanf("%s", &pil);

//   if ((strcmp(pil, "y") == 0) || (strcmp(pil, "Y") == 0))
//   {
//     printf("\nHarga baru : ");
//     scanf("%d", &price);
//     printf("\nHarga berhasil diubah menjadi : %d\n", price);
//   }
// }

int isValidDate(const char *date)
{
  int year, month, day;
  if (sscanf(date, "%d/%d/%d", &year, &month, &day) != 3)
  {
    // Jika tidak dapat membaca tiga angka, input tidak valid
    return 0;
  }

  // Validasi tahun, bulan, dan hari
  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
  {
    return 0; // Tanggal tidak valid
  }

  // Tambahan: Validasi bulan dengan jumlah hari yang benar
  if (month == 2 && (day > 29 || (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))))
  {
    return 0; // Februari tidak boleh lebih dari 29 hari (khususnya jika bukan tahun kabisat)
  }
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
  {
    return 0; // Bulan yang memiliki 30 hari tidak boleh lebih dari 30 hari
  }

  return 1; // Tanggal valid
}

// Fungsi untuk menginput data pemesanan
void inputData(struct Pemesanan pesanan[], int *jumlahData)
{
  int jmlData;
  printf("Masukkan jumlah data pemesanan: ");
  scanf("%d", &jmlData);

  *jumlahData = jmlData;

  for (int i = 0; i < *jumlahData; ++i)
  {
    back :
    printf("\nData Pemesanan ke-%d\n", i + 1);
    printf("Tanggal Pemesanan (format: YYYY/MM/DD): ");
    scanf("%s", pesanan[i].tanggalPemesanan);

    printf("Nama: ");
    scanf("%s", pesanan[i].nama);

    printf("Tujuan: ");
    scanf("%s", pesanan[i].tujuan);

    printf("Tanggal Pemakaian (format: YYYY/MM/DD): ");
    scanf("%s", pesanan[i].tanggalPemakaian);

    if(!isValidDate(pesanan[i].tanggalPemesanan) || !isValidDate(pesanan[i].tanggalPemakaian)){
      printf("\nTerdapat input tanggal yang tidak sesuai, silahkan ulangi\n");
      goto back;
    }
  }
}

// Fungsi untuk menampilkan data pemesanan
void tampilData(struct Pemesanan pesanan[], int jumlahData)
{
  printf("\nData Pemesanan:\n");
  for (int i = 0; i < jumlahData; ++i)
  {
    printf("\nData Pemesanan ke-%d\n", i + 1);
    printf("Tanggal Pemesanan: %s\n", pesanan[i].tanggalPemesanan);
    printf("Nama: %s\n", pesanan[i].nama);
    printf("Tujuan: %s\n", pesanan[i].tujuan);
    printf("Tanggal Pemakaian: %s\n", pesanan[i].tanggalPemakaian);
  }
}

// Fungsi untuk mengedit data pemesanan
void editData(struct Pemesanan pesanan[], int jumlahData)
{
  int nomorData;

  printf("\nData Pemesanan:\n");
  for (int i = 0; i < jumlahData; ++i)
  {
    printf("\nData Pemesanan ke-%d\n", i + 1);
    printf("Tanggal Pemesanan: %s\n", pesanan[i].tanggalPemesanan);
    printf("Nama: %s\n", pesanan[i].nama);
    printf("Tujuan: %s\n", pesanan[i].tujuan);
    printf("Tanggal Pemakaian: %s\n", pesanan[i].tanggalPemakaian);
  }
  printf("\n\n");

  printf("Masukkan nomor data yang ingin diubah (1-%d): ", jumlahData);
  scanf("%d", &nomorData);

  if (nomorData < 1 || nomorData > jumlahData)
  {
    printf("Nomor data tidak valid.\n");
    return;
  }

  printf("\nEdit Data Pemesanan ke-%d\n", nomorData);
  printf("Tanggal Pemesanan: ");
  scanf("%s", pesanan[nomorData - 1].tanggalPemesanan);

  printf("Nama: ");
  scanf("%s", pesanan[nomorData - 1].nama);

  printf("Tujuan: ");
  scanf("%s", pesanan[nomorData - 1].tujuan);

  printf("Tanggal Pemakaian: ");
  scanf("%s", pesanan[nomorData - 1].tanggalPemakaian);
}

// Fungsi untuk menghapus data pemesanan
void hapusData(struct Pemesanan pesanan[], int *jumlahData)
{
  int nomorData;

  printf("Masukkan nomor data yang ingin dihapus (1-%d): ", *jumlahData);
  scanf("%d", &nomorData);

  if (nomorData < 1 || nomorData > *jumlahData)
  {
    printf("Nomor data tidak valid.\n");
    return;
  }
  else
  {

    // Memindahkan data pada indeks yang dihapus
    for (int i = nomorData - 1; i < *jumlahData - 1; ++i)
    {
      pesanan[i] = pesanan[i + 1];
    }

    // Mengurangi jumlah data
    (*jumlahData)--;
  }
}

// Fungsi untuk mengonversi format tanggal ke format yang dapat dibandingkan
// Dalam contoh ini, format "YYYY/MM/DD" akan diubah menjadi "YYYY/MM/DD"
// void konversiFormatTanggal(struct Pemesanan *pesanan, int jumlahData)
// {
//   for (int i = 0; i < jumlahData; ++i)
//   {
//     char temp[20];
//     sscanf(pesanan[i].tanggalPemesanan, "%2s/%2s/%4s", temp + 8, temp + 5, temp);
//     sprintf(pesanan[i].tanggalPemesanan, "%s/%s/%s", temp, temp + 5, temp + 8);
//   }
// }

// Fungsi untuk melakukan Bubble Sort berdasarkan tanggal pemesanan
void bubbleSort(struct Pemesanan pesanan[], int jumlahData)
{
  for (int i = 0; i < jumlahData - 1; ++i)
  {
    for (int j = 0; j < jumlahData - i - 1; ++j)
    {
      // Menggunakan fungsi strcmp untuk membandingkan string tanggalPemesanan
      if (strcmp(pesanan[j].tanggalPemesanan, pesanan[j + 1].tanggalPemesanan) > 0)
      {
        // Menukar posisi jika tanggalPemesanan pada indeks j lebih besar dari indeks j+1
        struct Pemesanan temp = pesanan[j];
        pesanan[j] = pesanan[j + 1];
        pesanan[j + 1] = temp;
      }
    }
  }
  tampilData(pesanan, jumlahData);
}

// Fungsi untuk melakukan pencarian dengan metode Sequential Search berdasarkan tanggal pemesanan
int sequentialSearch(struct Pemesanan pesanan[], int jumlahData, char targetTanggal[])
{
  for (int i = 0; i < jumlahData; ++i)
  {
    // Menggunakan fungsi strcmp untuk membandingkan string tanggalPemesanan
    if (strcmp(pesanan[i].tanggalPemesanan, targetTanggal) == 0)
    {
      return i; // Mengembalikan indeks jika tanggal ditemukan
    }
  }
  return -1; // Mengembalikan -1 jika tanggal tidak ditemukan
}

// Fungsi untuk menyimpan data pemesanan ke dalam file teks
void simpanKeFile(struct Pemesanan pesanan[], int jumlahData, const char *namaFile)
{
  FILE *file = fopen(namaFile, "w");
  if (file == NULL)
  {
    printf("Gagal membuka file.\n");
    return;
  }

  for (int i = 0; i < jumlahData; ++i)
  {
    fprintf(file, "%s,%s,%s,%s\n", pesanan[i].tanggalPemesanan, pesanan[i].nama, pesanan[i].tujuan, pesanan[i].tanggalPemakaian);
  }

  fclose(file);
  printf("Data berhasil disimpan ke dalam file %s.\n", namaFile);
}