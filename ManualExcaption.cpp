#include <iostream>
using namespace std;

int main()
{
    try {
        cout << "Selamat Belajar di Prodi TI UMY" << endl;
        throw 3.5; //melemparkan sebuah integer maka
        cout << "Pernyataan tidak akan di eksekusi" << endl;
    }
    catch (int a) {
        //blok ini akan dieksekusi
        cout << a << " : Pengecualian akan dieksekusi" << endl;
    }
    catch (...) {
        //*jika selain intefer maka block ini akan  di eksekusi*/
        cout << "default pengecualian dieksekusi" << endl;
    }
    return 0;
}