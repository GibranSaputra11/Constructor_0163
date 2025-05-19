#include <iostream>
using namespace std;

class mahasiswa{
    private:
        static int jmlmhs; // Stattic varible (akan dimiliki oleh semua objek) ini nanti dapat diakses oleh objek mhs1, mhs1 dst. biasanya digunakn untuk status general yang tidak spesifik.
    public:
        string status; // tibe varible biasa bukan static
        string nama;
        int nim;
        mahasiswa(string pNama, int pNim){ // Konstruktor. dimanan program dibawhan ini akan otomatis berjalan ketika di run. Mmberikan nilai awal ketika program di eksekusi.
            status = "Mahasiswa Baru ";
            nama = pNama;
            nim = pNim;
            cout << "Mahasiswa Dibuat " << nama << endl;
            cout << "Status = " << status << endl;
            ++jmlmhs;
        }; 
        ~mahasiswa(){ //Destruktor (untuk mengahpus hit memori)
            cout << "Mahasiswa dengan nama : " << nama << " Dihancurkan" << endl;
            --jmlmhs;
        }; 
        static int getTotalMhs(){ // merupakan static variable juga tapi ini fungsi
            return jmlmhs;
        };
};

int mahasiswa::jmlmhs = 0;

int main(){
    cout << "Jumlah Mahasiswa = " << mahasiswa::getTotalMhs() << endl; // disini mencoba memanggil static member
    mahasiswa mhs1("Rudy", 28); 
    mahasiswa mhs2("Joko", 90);
    mhs2.status = "Mahasiswa uzur";
    cout << mhs2.status << endl;
    mahasiswa mhs3("Wobo", 69);
    cout << "Jumlah Mahasiswa = " << mahasiswa::getTotalMhs() << endl;
    {
        mahasiswa mhs4("Dewo", 98);
        cout << "Jumlah Mahasiswa Dalam Breket= " << mahasiswa::getTotalMhs() << endl;
    }
    cout << "Jumlah Mahasiswa = " << mahasiswa::getTotalMhs() << endl;
    return 0; // tanda kalo program sudah selesai atau same ahir. nah ini juga sebagi pertanda kalo destruktor sudah terpanggil.
}