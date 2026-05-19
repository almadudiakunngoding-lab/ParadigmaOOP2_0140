#include <iostream>
#include <string>

using namespace std;

class RekeningBank {
protected:
    string nomorRekening;
    double saldo;

public:
    RekeningBank(string no, double saldoAwal) : nomorRekening(no), saldo(saldoAwal) {}

    virtual void potongAdmin() = 0;

    void tampilkanInfo() {
        cout << "No Rek: " << nomorRekening << " | Saldo Akhir: Rp " << saldo << endl;
    }
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string no, double saldoAwal) : RekeningBank(no, saldoAwal) {}

    void potongAdmin() override {
        cout << "Rekening Syariah: Bebas biaya administrasi" << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string no, double saldoAwal) : RekeningBank(no, saldoAwal) {}

    void potongAdmin() override {
        double admin = 15000;
        saldo -= admin;
        cout << "Rekening Konvensional: Dipotong biaya admin Rp " << admin << endl;
    }
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string no, double saldoAwal) : RekeningBank(no, saldoAwal) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Rekening Premium: Bebas biaya administrasi" << endl;
        } else {
            double admin = 50000;
            saldo -= admin;
            cout << "Rekening Premium: Dipotong biaya admin Rp " << admin << endl;
        }
    }
};

int main() {
    RekeningBank* akun;

    RekeningSyariah tabunganKu("SYR-001", 500000);
    RekeningKonvensional tabunganBisnis("KNV-099", 2000000);
    RekeningPremium akunPremium1("PRM-101", 15000000);
    RekeningPremium akunPremium2("PRM-102", 7000000);

    akun = &tabunganKu;
    akun->potongAdmin();
    akun->tampilkanInfo();

    cout << "-----------------------------------------------" << endl;
    cout << endl;

    akun = &tabunganBisnis;
    akun->potongAdmin();
    akun->tampilkanInfo();

    cout << "-----------------------------------------------" << endl;
    cout << endl;

    akun = &akunPremium1;
    akun->potongAdmin();
    akun->tampilkanInfo();

    cout << "-----------------------------------------------" << endl;
    cout << endl;

    akun = &akunPremium2;
    akun->potongAdmin();
    akun->tampilkanInfo();

    return 0;
}