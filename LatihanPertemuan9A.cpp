#include <iostream>
#include <string>
using namespace std;

class Mahasiswa{
private:
    string nama;
    string nim;
    float nilai;
public:
    Mahasiswa(string n, string i) : nama(n), nim(i), nilai(0) {}
    void tampil() {
        cout << "Nama Mahasiswa : " << nama << endl;
        cout << "NIM : " << nim << endl;
        cout << "Nilai : " << nilai << endl << endl;
    }
    friend class Dosen;
};

class Dosen {
private:
    string nama;
    string nidn;
    string pangkat;
    float gaji;
public:
    Dosen(string n, string id, string p, float g) : nama(n), nidn(id), pangkat(p), gaji(g) {}
    friend float aksesGaji(Dosen* d);
    friend class Staff;
    void beriNilai(Mahasiswa* m, float nilai) {
        m->nilai = nilai; 
    }
};

class Staff {
private:
    string nama;
    int idStaff;
    float gaji;
public:
    Staff(string n, int id, float g) : nama(n), idStaff(id), gaji(g) {}

    void ubahPangkat(Dosen* d, string pangkatBaru) {
        d->pangkat = pangkatBaru;
    }
    friend float lihatGajiStaff(Staff* s);
};

float aksesGaji(Dosen* d) {
    return d->gaji;
}

float lihatGajiStaff(Staff* s) {
    return s->gaji;
}

int main(){
}