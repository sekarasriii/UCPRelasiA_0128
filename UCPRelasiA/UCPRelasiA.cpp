#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Proyek;

class Karyawan {
public:
    string namaKaryawan;
    vector<Proyek*> daftarProyek;
    vector<class Perusahaan*> daftar_perusahaan;

    Karyawan(string nama) : namaKaryawan(nama) {
        cout << "Karyawan \"" << namaKaryawan << "\" terdaftar\n";
    }

    void tambahPerusahaan(class Perusahaan*);
    void tambahProyek(Proyek*);
    void cetakPerusahaan();
    void cetakProyek();
};

class Proyek {
public:
    string namaProyek;
    vector<Karyawan*> daftar_karyawan;

    Proyek(string nama) : namaProyek(nama) {
        cout << "Proyek \"" << namaProyek << "\" terdaftar\n";
    }

    void tambahKaryawan(Karyawan* karyawan) {
        daftar_karyawan.push_back(karyawan);
    }

    void cetakKaryawan() {
        cout << "Daftar karyawan proyek \"" << namaProyek << "\":\n";
        for (auto& karyawan : daftar_karyawan) {
            cout << karyawan->namaKaryawan << "\n";
        }
        cout << endl;
    }
};

class Perusahaan {
public:
    string namaPerusahaan;
    vector<Karyawan*> daftar_karyawan;

    Perusahaan(string nama) : namaPerusahaan(nama) {
        cout << "Perusahaan \"" << namaPerusahaan << "\" terdaftar\n";
    }

    void tambahKaryawan(Karyawan* karyawan) {
        daftar_karyawan.push_back(karyawan);
        karyawan->tambahPerusahaan(this);
    }

    void cetakKaryawan() {
        cout << "Daftar karyawan dari perusahaan \"" << namaPerusahaan << "\":\n";
        for (auto& karyawan : daftar_karyawan) {
            cout << karyawan->namaKaryawan << "\n";
        }
        cout << endl;
    }
};

void Karyawan::tambahPerusahaan(Perusahaan* perusahaan) {
    daftar_perusahaan.push_back(perusahaan);
}

void Karyawan::tambahProyek(Proyek* proyek) {
    daftarProyek.push_back(proyek);
    proyek->tambahKaryawan(this);
}

void Karyawan::cetakPerusahaan() {
    cout << "Daftar perusahaan yang dimiliki \"" << namaKaryawan << "\":\n";
    for (auto& perusahaan : daftar_perusahaan) {
        cout << perusahaan->namaPerusahaan << "\n";
    }
    cout << endl;
}

void Karyawan::cetakProyek() {
    cout << "Daftar proyek karyawan \"" << namaKaryawan << "\":\n";
    for (auto& proyek : daftarProyek) {
        cout << proyek->namaProyek << "\n";
    }
    cout << endl;
}

int main() {
    Perusahaan* varPerusahaan = new Perusahaan("PT. Maju Mundur");

    Karyawan* varKaryawan1 = new Karyawan("Budi");
    Karyawan* varKaryawan2 = new Karyawan("Andi");

    varPerusahaan->tambahKaryawan(varKaryawan1);
    varPerusahaan->tambahKaryawan(varKaryawan2);

    Proyek* varProyek1 = new Proyek("Sistem Informasi");
    Proyek* varProyek2 = new Proyek("Sistem Keamanan");

    varKaryawan1->tambahProyek(varProyek1);
    varKaryawan1->tambahProyek(varProyek2);
    varKaryawan2->tambahProyek(varProyek1);

    varPerusahaan->cetakKaryawan();

    varKaryawan1->cetakPerusahaan();
    varKaryawan2->cetakPerusahaan();

    varKaryawan1->cetakProyek();
    varKaryawan2->cetakProyek();

    varProyek1->cetakKaryawan();
    varProyek2->cetakKaryawan();

    delete varKaryawan1;
    delete varKaryawan2;
    delete varProyek1;
    delete varProyek2;
    delete varPerusahaan;

    return 0;
}