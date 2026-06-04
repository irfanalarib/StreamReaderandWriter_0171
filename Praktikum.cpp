#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <exception>
#include <stdexcept>

using namespace std;

class TokoElektronik {
private:
    array<string, 3> etalaseBarang;

public:
    TokoElektronik() {
        etalaseBarang = {"Laptop ASUS", "Smartphone Samsung", "Smart TV LG"};
    }

    string ambilBarangDariEtalase(size_t nomorRak) {
        try {
            return etalaseBarang.at(nomorRak);
        }
        catch (const out_of_range& e) {
            throw runtime_error("Gagal Mengambil Barang : Rak nomor " + to_string(nomorRak) + " kosong atau tidak tersedia!");
        }
    }
};

const string FILE_GUDANG = "gudang.txt";

void tampilkanGudang() {
    ifstream infile(FILE_GUDANG);
    string baris;
    int nomor = 1;

    cout << "\n=========================================" << endl;
    cout << "      DAFTAR BARANG DI GUDANG (FILE)     " << endl;
    cout << "=========================================" << endl;

    if (infile.is_open()) {
        bool adaBarang = false;
        while (getline(infile, baris)) {
            if (!baris.empty()) {
                cout << nomor << ". " << baris << endl;
                nomor++;
                adaBarang = true;
            }
        }
        if (!adaBarang) {
            cout << "[ Gudang Kosong / Belum Ada Data ]" << endl;
        }
        infile.close();
    } else {
        cout << "[ Catatan: File " << FILE_GUDANG << " belum dibuat. Silakan tambah barang terlebih dahulu. ]" << endl;
    }
    cout << "=========================================" << endl;
}

void tambahBarang() {
    ofstream outfile(FILE_GUDANG, ios::app); 
    if (outfile.is_open()) {
        string namaBarang;
        cout << "Masukkan Nama Barang Baru: ";
        cin.ignore();
        getline(cin, namaBarang);

        if (!namaBarang.empty()) {
            outfile << namaBarang << endl;
            cout << "=> Sukses: '" << namaBarang << "' berhasil disimpan ke gudang." << endl;
        }
        outfile.close();
    } else {
        cout << "=> Error: Gagal membuka file gudang!" << endl;
    }
}

void perbaruiBarang() {
    tampilkanGudang();
    
    ifstream infile(FILE_GUDANG);
    if (!infile.is_open()) {
        cout << "=> Gagal memperbarui, file tidak ditemukan." << endl;
        return;
    }

    string baris;
    string tempGudang[100];
    int totalBarang = 0;

    while (getline(infile, baris)) {
        if (!baris.empty()) {
            tempGudang[totalBarang] = baris;
            totalBarang++;
        }
    }
    infile.close();

    if (totalBarang == 0) return;
}