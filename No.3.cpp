#include <iostream>
#include <string>

using namespace std;

class Rekening {
public:
    string nama;
    string nomorRekening;
    double saldo;


    Rekening(const string &nama, const string &nomorRekening, double saldo)
        : nama(nama), nomorRekening(nomorRekening), saldo(saldo) {}

    void getInfo() const {
        cout << "Nama: " << nama << endl;
        cout << "Nomor Rekening: " << nomorRekening << endl;
        cout << "Saldo: $" << saldo << endl;
    }

    void tambahSaldo(double jumlah) {
        saldo += jumlah;
        cout << "Saldo berhasil ditambahkan. Saldo sekarang: $" << saldo << endl;
    }

    void kurangiSaldo(double jumlah) {
        if (jumlah > saldo) {
            cout << "Saldo tidak mencukupi." << endl;
        } else {
            saldo -= jumlah;
            cout << "Saldo berhasil dikurangi. Saldo sekarang: $" << saldo << endl;
        }
    }
};

int main() {
    Rekening rekening("Adisty Nurharumandari", "5221 8540 6623", 500000.0);

    cout << "Informasi awal rekening:" << endl;
    rekening.getInfo();
    cout << endl;

    rekening.tambahSaldo(100000.0);
    rekening.kurangiSaldo(25000.0);

    return 0;
}
