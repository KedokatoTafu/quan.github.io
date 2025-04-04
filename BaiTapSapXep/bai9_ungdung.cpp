#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
struct Sinh_Vien {
    int ma_so;
    string ho_dem;
    string ten;
    int ngay, thang, nam;
    string phai;
    float diem_TB;
};
// H�m nhap th�ng tin mot sinh vi�n
Sinh_Vien nhapSinhVien() {
    Sinh_Vien sv;
    cout << "Nhap thong tin sinh vien:\n";
    cout << "Ma so: "; cin >> sv.ma_so;
    cin.ignore();  
    cout << "Ho dem: "; getline(cin, sv.ho_dem);
    cout << "Ten: "; getline(cin, sv.ten);
    cout << "Ngay sinh: "; cin >> sv.ngay;
    cout << "Thang sinh: "; cin >> sv.thang;
    cout << "Nam sinh: "; cin >> sv.nam;
    cout << "Phai (Nam/Nu): "; cin >> sv.phai;
    cout << "Diem TB: "; cin >> sv.diem_TB;
    return sv;
}
// Ham hien thi th�ng tin sinh vi�n
void hien_Thi_Sinh_Vien(const Sinh_Vien& sv) {
    cout << sv.ma_so << "\t" << sv.ho_dem << " " << sv.ten << "\t"
         << sv.ngay << "/" << sv.thang << "/" << sv.nam << "\t"
         << sv.phai << "\t" << sv.diem_TB << endl;
}
// H�m kiem tra tr�ng m� so sinh vi�n
bool kiem_Tra_Trung_Ma(const vector<Sinh_Vien>& ds, int ma_so) {
    for (const auto& sv : ds) {
        if (sv.ma_so == ma_so) return true;
    }
    return false;
}

// H�m sap xep danh s�ch sinh vi�n theo m� so
void sap_xep_theo_ma_so(vector<Sinh_Vien>& ds) {
    sort(ds.begin(), ds.end(), [](const Sinh_Vien& a, const Sinh_Vien& b) {
        return a.ma_so < b.ma_so;
    });
}

// H�m luu danh s�ch sinh vi�n v�o file
void luu_File_Sinh_Vien(const vector<Sinh_Vien>& ds, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file " << filename << endl;
        return;
    }
    for (const auto& sv : ds) {
        file << sv.ma_so << "," << sv.ho_dem << "," << sv.ten << ","
             << sv.ngay << "," << sv.thang << "," << sv.nam << ","
             << sv.phai << "," << sv.diem_TB << endl;
    }
    file.close();
}

// H�m luu file index (chi chua m� so sinh vi�n)
void luu_File_Index(const vector<Sinh_Vien>& ds, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file " << filename << endl;
        return;
    }
    for (const auto& sv : ds) {
        file << sv.ma_so << endl;
    }
    file.close();
}

// Chuong tr�nh chinh
int main() {
    vector<Sinh_Vien> danhSachSV;
    cout << "Nhap danh sach sinh vien (toi thieu 10 sinh vien):\n";
    
    while (danhSachSV.size() < 10) {
        Sinh_Vien sv = nhapSinhVien();
        if (kiem_Tra_Trung_Ma(danhSachSV, sv.ma_so)) {
            cout << "Ma so bi trung! Nhap lai.\n";
            continue;
        }
        danhSachSV.push_back(sv);
    }
    // Luu danh s�ch sinh vi�n goc
    luu_File_Sinh_Vien(danhSachSV, "SINHVIEN.DAT");
    // Sap xep theo m� so v� luu file index
    sap_xep_theo_ma_so(danhSachSV);
    luu_File_Index(danhSachSV, "SVMASO.IDX");

    // Hien thi danh s�ch sau khi sap xep
    cout << "\nDanh sach sinh vien sau khi sap xep theo ma so:\n";
    for (const auto& sv : danhSachSV) {
        hien_Thi_Sinh_Vien(sv);
    }

    return 0;
}

