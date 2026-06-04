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

    cout << ">= Menulis file, \'q\' untuk keluar" << endl;

    //loop untuk menulis isi file
    while (true)
    {
        cout <<"-";
        //mendapat setiap karakter dalam satu baris 
        getline(cin, baris);
        //kondisi jika baris berisi hanya q
        if (baris == "q") break;
        //menulis dan memasukkan nilai dari  baris ke dalam file 
        outfile << baris << endl;
    }
    //menutup file
    outfile.close();

    //membuka file dalam mode membaca
    ifstream infile;

    //menuju kesebuah nama file dalam ekstensi .txt
    infile.open(NamaFile + ".txt", ios::in);

    cout << endl <<  ">= Membuka dan Membaca file" << endl;
    //kondisi jika file ada
    if (infile.is_open())
    {
        //perulangan untuk menampilkan setiap baris
        while (getline(infile, baris))
        {
            cout << baris << endl;
        }
        //menutup file
        infile.close();
    }
    //kondisi jika file tidak ada
    else cout << "Unable to open file";
    return 0;
}