#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string baris;

    //membuat ojek output file stram
    ofstream outfile;
    //membuka file untuk ditulisi
    outfile.open("contohfile.txt");

    cout << ">= Menulis file, \'q\' untuk keluar" << endl;

    //unlimited lopp untuk menulis
    while (true) {
        cout << "_ ";
        //mendapatkan setiap karakter dalam satu baris
        getline(cin, baris);
        // loop akan berhenti jika anda memasukan karakter q
        if (baris == "q") break;
        //menulis dan memasukan nilai dari 'baris' ke dalam file
        outfile << baris << endl;
    }
    //selesai dalam menulis sekarang tutup filenya
    outfile.close();

    //membuat objek input file stram
    ifstream infile;
    //membuka file yang dituliskan
    infile.open("contohfile.txt");

    cout << endl << ">= Membuka dan membaca file " << endl;
    //jika file ada maka
    if (infile.is_open())
    {
        //melakukan perulangan setiap baris
        while (getline(infile, baris))
        {
            //dan tampilkan disini
            cout << baris << '\n';
        }
    }
}