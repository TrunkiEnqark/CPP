#include <string>
#include <iostream>

using namespace std;

enum TrangThaiSanPham {ConHang = 1, DaBanHet = 2};

class SanPham {
private:
    string ten;
    int con_lai, gia;
    TrangThaiSanPham san_pham;
public:
// Cac ham nhap
    void nhap_ten();
    void nhap_trang_thai();

// Cac ham in
    void in_trang_thai();
    void in_ten();

// Ham kiem tra
    void kiem_tra();
};

void SanPham::nhap_ten() {
    cout << "Nhap ten: ";
    cin >> ten;
}

void SanPham::kiem_tra() {
    if (san_pham == ConHang) {
        cout << "Con hang\n";
    } else {
        cout << "Het hang\n";
    }
} 

void SanPham::in_ten() {
    cout << "Ten san pham: " << ten << '\n';
}

void SanPham::nhap_trang_thai() {
    cout << "1. Con hang\n";
    cout << "2. Het hang\n";
    cout << "Nhap so tu 1 den 2 theo bang tren: \n";
    int id;
    cin >> id;
    switch (id) {
        case ConHang: {
            san_pham = ConHang;
            break;
        }
        case DaBanHet: {
            san_pham = DaBanHet;
            break;
        }
        default: {
            break;
        }
    }
}

void SanPham::in_trang_thai() {
    switch (san_pham) {
        case ConHang: {
            cout << "Con hang\n";
            break;
        } 
        case DaBanHet: {
            cout << "Da ban het\n";
            break;
        }
        default: {
            break;
        }
    }
}