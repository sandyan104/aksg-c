#ifndef APP_H
#define APP_H
#include "../structs/structs.h"

void inputData(pesanan, jumlahData);
void tampilData(pesanan, jumlahData);
void editData(pesanan, jumlahData);
void hapusData(pesanan, jumlahData);
void bubbleSort(pesanan, jumlahData);
int sequentialSearch(pesanan, jumlahData, targetTanggal);
void simpanKeFile(pesanan, jumlahData, namaFile);

#endif