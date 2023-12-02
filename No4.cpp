#include <iostream>
#include <string>
#include <map>

using namespace std;

// Struktur untuk merepresentasikan mata kuliah dan nilai
struct MataKuliah {
    string nama;
    double nilai;
};

// Struktur untuk merepresentasikan mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    map<string, MataKuliah> catatan_akademik;
};

// Fungsi untuk menambahkan mata kuliah dan nilai
void tambahMataKuliah(Mahasiswa& mahasiswa, string nama_matkul, double nilai) {
    MataKuliah matkul = {nama_matkul, nilai};
    mahasiswa.catatan_akademik[nama_matkul] = matkul;
}

// Fungsi untuk menghitung rata-rata nilai
double hitungRataRata(const Mahasiswa& mahasiswa) {
    if (mahasiswa.catatan_akademik.empty()) {
        return 0.0;
    }

    double total_nilai = 0.0;
    for (const auto& pair : mahasiswa.catatan_akademik) {
        total_nilai += pair.second.nilai;
    }

    return total_nilai / mahasiswa.catatan_akademik.size();
}

// Fungsi untuk menampilkan catatan akademik
void tampilkanCatatanAkademik(const Mahasiswa& mahasiswa) {
    cout << "Catatan Akademik " << mahasiswa.nama << " (" << mahasiswa.nim << "):" << endl;
    if (mahasiswa.catatan_akademik.empty()) {
        cout << "Belum ada data mata kuliah." << endl;
    } else {
        for (const auto& pair : mahasiswa.catatan_akademik) {
            cout << pair.first << ": " << pair.second.nilai << endl;
        }
        double rata_rata = hitungRataRata(mahasiswa);
        cout << "Rata-rata nilai: " << rata_rata << endl;
    }
}

int main() {
    map<string, Mahasiswa> data_mahasiswa;

    while (true) {
        cout << "\n=== Sistem Manajemen Catatan Akademik ===" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tambah Mata Kuliah dan Nilai" << endl;
        cout << "3. Tampilkan Catatan Akademik Mahasiswa" << endl;
        cout << "4. Keluar" << endl;

        int pilihan;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                Mahasiswa mahasiswa;
                cout << "Masukkan nama mahasiswa: ";
                cin >> mahasiswa.nama;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> mahasiswa.nim;
                data_mahasiswa[mahasiswa.nim] = mahasiswa;
                cout << "Mahasiswa " << mahasiswa.nama << " dengan NIM " << mahasiswa.nim << " berhasil ditambahkan." << endl;
                break;
            }

            case 2: {
                string nim;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;

                auto it = data_mahasiswa.find(nim);
                if (it != data_mahasiswa.end()) {
                    string nama_matkul;
                    double nilai;

                    cout << "Masukkan nama mata kuliah: ";
                    cin >> nama_matkul;
                    cout << "Masukkan nilai: ";
                    cin >> nilai;

                    tambahMataKuliah(it->second, nama_matkul, nilai);
                    cout << "Data mata kuliah " << nama_matkul << " dengan nilai " << nilai << " berhasil ditambahkan." << endl;
                } else {
                    cout << "NIM tidak ditemukan. Mohon tambahkan mahasiswa terlebih dahulu." << endl;
                }
                break;
            }

            case 3: {
                string nim;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;

                auto it = data_mahasiswa.find(nim);
                if (it != data_mahasiswa.end()) {
                    tampilkanCatatanAkademik(it->second);
                } else {
                    cout << "NIM tidak ditemukan. Mohon tambahkan mahasiswa terlebih dahulu." << endl;
                }
                break;
            }

            case 4:
                cout << "Terima kasih! Program selesai." << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang benar." << endl;
                break;
        }
    }

    return 0;
}
