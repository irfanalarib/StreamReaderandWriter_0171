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

    int pilihanNomor;
    cout << "Pilih nomor barang yang ingin diubah: ";
    cin >> pilihanNomor;

    if (pilihanNomor > 0 && pilihanNomor <= totalBarang) {
        string namaBaru;
        cout << "Masukkan nama baru untuk '" << tempGudang[pilihanNomor - 1] << "': ";
        cin.ignore();
        getline(cin, namaBaru);

        tempGudang[pilihanNomor - 1] = namaBaru;

        // Tulis ulang seluruh data baru ke file (ios::out menimpa file lama)
        ofstream outfile(FILE_GUDANG, ios::out);
        for (int i = 0; i < totalBarang; i++) {
            outfile << tempGudang[i] << endl;
        }
        outfile.close();
        cout << "=> Sukses: Data barang berhasil diperbarui!" << endl;
    } else {
        cout << "=> Pilihan tidak valid!" << endl;
    }
}

void hapusBarang() {
    tampilkanGudang();

    ifstream infile(FILE_GUDANG);
    if (!infile.is_open()) {
        cout << "=> Gagal menghapus, file tidak ditemukan." << endl;
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

    int pilihanNomor;
    cout << "Pilih nomor barang yang ingin dihapus: ";
    cin >> pilihanNomor;

    if (pilihanNomor > 0 && pilihanNomor <= totalBarang) {
        cout << "=> Sukses: '" << tempGudang[pilihanNomor - 1] << "' berhasil dihapus." << endl;

        ofstream outfile(FILE_GUDANG, ios::out);
        for (int i = 0; i < totalBarang; i++) {
            if (i != (pilihanNomor - 1)) {
                outfile << tempGudang[i] << endl;
            }
        }
        outfile.close();
    }else {
        cout << "=> Pilihan tidak valid!" << endl;
    }
}

void jalankanSimulasiEtalase(TokoElektronik& toko) {
    cout << "\n=== MEMULAI SIMULASI ETALASE TOKO ===" << endl;

    cout << "\n[Skenario 1] Mengambil barang di rak indeks ke-1..." << endl;
    try {
        string barang = toko.ambilBarangDariEtalase(1);
        cout << "Hasil Skenario 1 (Sukses): Barang ditemukan -> " << barang << endl;
    }
    catch (const runtime_error& e) {
        cout << "Hasil Skenario 1 (Gagal): " << e.what() << endl;
    }

    cout << "\n[Skenario 2] Mengambil barang di rak indeks ke-5..." << endl;
    try {
        string barang = toko.ambilBarangDariEtalase(5);
        cout << "Hasil Skenario 2 (Sukses): Barang ditemukan -> " << barang << endl;
    }
    catch (const runtime_error& e) {
        cout << "Hasil Skenario 2 (Ditangkap Aman): " << e.what() << endl;
    }
    cout << "\n=====================================" << endl;
}

int main() {
    TokoElektronik gibranJaya; 
    int pilihanMenu;

    do {
        // Read: Menampilkan daftar barang secara otomatis saat menu dibuka
        tampilkanGudang();

        cout << "\n=== SISTEM MANAJEMEN TOKO \"GIBRAN JAYA\" ===" << endl;
        cout << "1. Tambah Barang Baru Ke Gudang (Create)" << endl;
        cout << "2. Perbarui Data Barang Gudang (Update)" << endl;
        cout << "3. Hapus Data Barang Gudang (Delete)" << endl;
        cout << "4. Jalankan Simulasi Etalase (Uji Exception)" << endl;
        cout << "5. Keluar Aplikasi" << endl;
        cout << "Pilih opsi menu (1-5): ";
        cin >> pilihanMenu;

    } 
}