#include <iostream>
#include <exception>
#include <array>
using namespace std;

int main() 
{
    cout << "Awal program" << endl; //penanda
    try {
        // deklarasi array dengan panjang 3
        array<int, 3> data = {1, 2, 3};
        //memanggil array dengan index 5 yang berarti akan terjadi error
        cout << data.at(5) << endl;
    }
}