#include <iostream>

class PersegiPanjang {
public:
    double panjang;
    double lebar;

    // Setter
    void setPanjang(double p) {
        panjang = p;
    }

    void setLebar(double l) {
        lebar = l;
    }

    // Getter
    double getPanjang() const {
        return panjang;
    }

    double getLebar() const {
        return lebar;
    }

    // Fungsi untuk menghitung luas
    double hitungLuas() const {
        return panjang * lebar;
    }
};

int main() {
    // Membuat objek PersegiPanjang
    PersegiPanjang persegi;

    // Menggunakan setter
    persegi.setPanjang(5.0);
    persegi.setLebar(3.0);

    // Menggunakan getter untuk mendapatkan nilai panjang dan lebar
    printf("Panjang: %f\n", persegi.getPanjang());
    printf("Lebar: %f\n", persegi.getLebar());

    // Menghitung dan menampilkan luas
    printf("Luas Persegi Panjang: %f\n", persegi.hitungLuas());

    return 0;
}