#include <cstdio>

class Tabung {
private:
    double jariJari;
    double tinggi;

public:
    // Setter
    void setJariJari(double r) {
        jariJari = r;
    }

    void setTinggi(double h) {
        tinggi = h;
    }

    // Getter
    double getJariJari() const {
        return jariJari;
    }

    double getTinggi() const {
        return tinggi;
    }

    // Fungsi untuk menghitung luas permukaan
    double hitungLuasPermukaan() const {
        return 2 * 3.14 * jariJari * (jariJari + tinggi);
    }

    // Fungsi untuk menghitung volume
    double hitungVolume() const {
        return 3.14 * jariJari * jariJari * tinggi;
    }
};

int main() {
    // Membuat objek Tabung
    Tabung tabung;

    // Menggunakan setter
    tabung.setJariJari(4.0);
    tabung.setTinggi(6.0);

    // Menggunakan getter untuk mendapatkan nilai jari-jari dan tinggi
    printf("Jari-Jari: %f\n", tabung.getJariJari());
    printf("Tinggi: %f\n", tabung.getTinggi());

    // Menghitung dan menampilkan luas permukaan
    printf("Luas Permukaan Tabung: %f\n", tabung.hitungLuasPermukaan());

    // Menghitung dan menampilkan volume
    printf("Volume Tabung: %f\n", tabung.hitungVolume());

    return 0;
}