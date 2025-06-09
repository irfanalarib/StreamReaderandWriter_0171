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
}