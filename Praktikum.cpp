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

}