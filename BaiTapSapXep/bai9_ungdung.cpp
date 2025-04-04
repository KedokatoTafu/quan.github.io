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
// Hàm nhap thông tin mot sinh viên
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
// Ham hien thi thông tin sinh viên
void hien_Thi_Sinh_Vien(const Sinh_Vien& sv) {
    cout << sv.ma_so << "\t" << sv.ho_dem << " " << sv.ten << "\t"
         << sv.ngay << "/" << sv.thang << "/" << sv.nam << "\t"
         << sv.phai << "\t" << sv.diem_TB << endl;
}
// Hàm kiem tra trùng mã so sinh viên
bool kiem_Tra_Trung_Ma(const vector<Sinh_Vien>& ds, int ma_so) {
    for (const auto& sv : ds) {
        if (sv.ma_so == ma_so) return true;
    }
    return false;
}

// Hàm sap xep danh sách sinh viên theo mã so
void sap_xep_theo_ma_so(vector<Sinh_Vien>& ds) {
    sort(ds.begin(), ds.end(), [](const Sinh_Vien& a, const Sinh_Vien& b) {
        return a.ma_so < b.ma_so;
    });
}

// Hàm luu danh sách sinh viên vào file
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

// Hàm luu file index (chi chua mã so sinh viên)
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

// Chuong trình chinh
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
    // Luu danh sách sinh viên goc
    luu_File_Sinh_Vien(danhSachSV, "SINHVIEN.DAT");
    // Sap xep theo mã so và luu file index
    sap_xep_theo_ma_so(danhSachSV);
    luu_File_Index(danhSachSV, "SVMASO.IDX");

    // Hien thi danh sách sau khi sap xep
    cout << "\nDanh sach sinh vien sau khi sap xep theo ma so:\n";
    for (const auto& sv : danhSachSV) {
        hien_Thi_Sinh_Vien(sv);
    }

    return 0;
}

