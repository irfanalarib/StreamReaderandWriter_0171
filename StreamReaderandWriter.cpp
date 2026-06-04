#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    //deklarasi variabel baris untu meyimpan data string
    string baris;

    //membukan file dalam mode menulis
    ofstream outfile;

    //menuju kesebuah data file
    outfile.open("contohfile.txt");

    cout << ">= Menulis file, \'q\' untuk keluar" << endl;

    //unlimited loop untuk menulis file
    while (true)
    {
        cout <<"-";
        //mendapat setiap karakter dalam satu baris 
        getline(cin, baris);
        //kondisi false jika baris hanya berisi karakter q
        if (baris == "q") break;
        //menulis dan memasukkan nilai dari variabel baris ke dalam file 
        outfile << baris << endl;
    }
    //menutup file
    outfile.close();

    //membuka file dalam mode membaca
    ifstream infile;
    //menuju kesebuah data file
    infile.open("contohfile.txt");

    cout << endl <<  ">= Membuka dan Membaca file" << endl;
    //konsisi jika file ada
    if (infile.is_open())
    {
        //perulangan untuk meluncurkan setiap baris
        while (getline(infile, baris))
        {
            cout << baris << endl;
        }
        //menutup file
        infile.close();
    }
    //kondisi jika file tidak ada
    else cout << "Unable to open file"
    return 0;
}