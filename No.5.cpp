#include <iostream>
#include <string>

using namespace std;

class Mobil {
public:
    string nama;
    string model;
    double kecepatan;


    Mobil(const string &nama, const string &model, double kecepatan)
        : nama(nama), model(model), kecepatan(kecepatan) {}

    void getInfo() const {
        cout << "Nama: " << nama << endl;
        cout << "Model: " << model << endl;
        cout << "Kecepatan: " << kecepatan << " km/h" << endl;
    }

    void percepat(double tambahanKecepatan) {
        kecepatan += tambahanKecepatan;
        cout << "Mobil dipercepat. Kecepatan sekarang: " << kecepatan << " km/h" << endl;
    }

    void perlambat(double penguranganKecepatan) {
        if (kecepatan - penguranganKecepatan < 0) {
            kecepatan = 0;
        } else {
            kecepatan -= penguranganKecepatan;
        }
        cout << "Mobil diperlambat. Kecepatan sekarang: " << kecepatan << " km/h" << endl;
    }
};

int main() {
    Mobil mobil1("Toyota", "Camry", 60.0);

    cout << "Informasi awal mobil:" << endl;
    mobil1.getInfo();
    cout << endl;mobil1.percepat(30.0);

    Mobil mobil2("Honda", "Civic", 50.0);

    cout << "Informasi awal mobil:" << endl;
    mobil2.getInfo();
    cout << endl;

    mobil2.perlambat(10.0);

    return 0;
}
