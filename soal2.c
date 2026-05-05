/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4 (Dynamic Structures)
 *   Hari dan Tanggal    : Selasa, 5 May 2026
 *   Nama (NIM)          : Rafif Hilman Muhammad (13224073)
 *   Nama File           : soal2.c
 *   Deskripsi           : input karakter "(" atau ")", lalu output menghitung jumlah "(" atau ")" 
                            yang dibutuhkan untuk melengkapi kekosongan
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 50

int main(void){
    char simbol[MAX_STRING_LENGTH];
    
    //melakukan input rangakaian karakter
    gets(simbol);

    int count = 0;
    int counta=0;
    int countb=0;

    int i = 0;

    //melakukan looping untuk pengetesan karakter
    while  (simbol[i] != 0){
        //Jika karakter ke-i adalah "("
        if (strcmp (simbol[i], "(") == 0){
            int j = i+1;
            //Mencari Pasangan karakter
            while  (simbol[j] != 0){
                if (strcmp (simbol[j], "(") == 0){
                    counta++;
                }
                else if (strcmp (simbol[j], ")")){
                    countb++;
                }
                j++;
            }
            //Terdapat pasangan karakter
            if (counta <= countb){
                break;
            }
            //Tidak ada pasangan karakter
            else if (counta > countb){
                count++;
            }
        }
        //Jika karakter ke-i adalah ")"
        else if (strcmp (simbol[i], ")") == 0){
            int j = i-1;
            //Mencari pasangan karakter
            while  (simbol[j] != 0){
                if (strcmp (simbol[j], ")") == 0){
                    counta++;
                }
                else if (strcmp (simbol[j], "(") == 0){
                    countb++;
                }
                j--;
            }
            //Terdapat pasangan karakter
            if (counta <= countb){
                break;
            }
            //Tidak ada pasangan karakter
            else if (counta > countb){
                count++;
            }
        }
        else {
            return 0;
        }
        i++;
    }

    //output jumlah karakter yang dibutuhkan untuk memperbaiki
    printf("%d\n", &count);
    return 0;
}
