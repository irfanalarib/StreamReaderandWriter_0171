#include <iostream>
using namespace std;

int main(){

    //membuat isi dari try untuk menguji error
    try {
        cout << "Selamat Belajar Di Prodi TI UMY" << endl;
        //throw 0.5; //melemparkan sebuah integer main
        cout << "Pernyataan tidak akan di tampilkan" << endl;
    }
    //kondisi jika throw yang bertipe data integer
    catch (int a) {
        cout << "Pengecualian akan di eksekusi: " << endl;
    }
    //kondisi jika throw yang bertipe selain integer
    catch (...) {
        cout << "Default Pengecualian  di eksekusi: " << endl;
    }
    return 0;
}