#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Mahasiswa
{
    char nama[50]; /*char karena fungsi yang ada di dalam stdio.h hanya mengenal array character. string punya c++ stdio.h ini punya C*/
    int nim;
    float ipk;
};
Mahasiswa mhs[100];

int main(){
    int data;
    cout << "Masukkan jumlah data: "; cin >> data;

    FILE *tunjuk;
    tunjuk = fopen("mahasiswa.txt", "a");
    if (tunjuk == NULL)
    {
       cout << "ERROR OPENING DATA" << endl;
       exit(1);
    }
    

    for (int i = 0; i < data; i++)
    {
        cout << "Data ke-" << i + 1 << endl;
         cout << "Masukkan nama: ";
        cin.ignore();
        cin.getline(mhs[i].nama, 50);

        // cout << "Masukkan nama: "; cin >> mhs[i].nama;
        cout << "Masukkan nim: "; cin >> mhs[i].nim;
        cout << "Masukkan ipk: "; cin >> mhs[i].ipk;
        cout << endl;

        fprintf(tunjuk, "%s|%d|%f\n", mhs[i].nama, mhs[i].nim, mhs[i].ipk);
    }
    fclose(tunjuk);

    tunjuk = fopen("mahasiswa.txt", "r");
    cout << "======= Data Saat Ini =======" << endl;
    int i = 0;
    while (fscanf(tunjuk," %[^|]|%d|%f", mhs[i].nama, &mhs[i].nim, &mhs[i].ipk) == 3)
    {
        cout << "Data ke-" << i + 1 << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "IPK: " << mhs[i].ipk << endl;
        cout << endl;

        i++;
    }

    fclose(tunjuk); //batas selesai menggunakan file. jadi memorynya akan di kosongkan.
    /*setelah baca buku, tutup buku dan kembalikan*/

    FILE *file;
    file = fopen("data.txt", "w");
    char text[50] = "Belajar file C++ bersama SI-C";

    fputs(text, file);
    fputs("Hallo teman teman SI-C", file);
    fclose(file);

    file = fopen("data.txt", "r");
    fgets(text, 50, file);
    cout << "Hasil bacaan: " << text << endl;
    fclose(file);

    if (remove("data.txt") == 0)
    {
        cout << "file data.txt berhasil di hapus";
    } else{
        cout << "Gagal menghapus file data.txt";
    }

    if (rename("mahasiswa.txt", "mahasiswaUPN.txt") == 0)
    {
        cout << "file mahasiswa.txt berhasil di ganti" << endl;
    } else{
        cout << "Gagal mengganti file mahasiswa.txt";
    }
     

}