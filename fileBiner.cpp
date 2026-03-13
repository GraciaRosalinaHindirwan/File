#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    FILE *file;
    char nama[50];
    char c;

    file = fopen("data.txt","wb");

    cout << "Masukkan nama: ";
    cin >> nama;

    fwrite(nama,sizeof(nama),1,file);
    fclose(file);

    file = fopen("data.txt","rb");

    while(fread(&c,sizeof(char),1,file))
    {
        cout << c << " -> " << (int)c << endl;
    }

    fclose(file);
}