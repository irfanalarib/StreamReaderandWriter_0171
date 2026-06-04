#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    //deklarasi variabel baris dan namafile
    string baris, NamaFile;

    //membuat inputan nama file
    cout << "Masukkan nama file: ";
    cin >> NamaFile;

    //membuka file dalam mode menulis
    ofstream outfile;
    //menuju kesebuah nama file dalam ekstensi .txt
    outfile.open(NamaFile + ".txt", ios::out);
}