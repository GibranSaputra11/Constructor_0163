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
};    

int main(){
}