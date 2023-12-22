#ifndef STRUCTS_H
#define STRUCTS_H

struct UserData
{
  char username[20];
  char password[20];
};

struct Pemesanan {
    char tanggalPemesanan[20];
    char nama[50];
    char tujuan[50];
    char tanggalPemakaian[20];
};

#endif