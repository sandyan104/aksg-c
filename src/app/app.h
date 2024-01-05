#ifndef APP_H
#define APP_H
#include "../structs/structs.h"

int isValidDate(const char *date);
void inputData(struct Pemesanan pesanan[], int *jumlahData);
void tampilData(struct Pemesanan pesanan[], int jumlahData);
void editData(struct Pemesanan pesanan[], int jumlahData);
void hapusData(struct Pemesanan pesanan[], int *jumlahData);
void bubbleSort(struct Pemesanan pesanan[], int jumlahData);
int sequentialSearch(struct Pemesanan pesanan[], int jumlahData, char targetTanggal[]);
void simpanKeFile(struct Pemesanan pesanan[], int jumlahData, const char *namaFile);

#endif