#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Định nghĩa cấu trúc dữ liệu
struct PhongThi {
    int soPhong;
    char tenNha;
    int khaNangChua;
};

// Hàm nhập danh sách phòng thi
void nhapDanhSach(vector<PhongThi>& danhSach, int n) {
    for (int i = 0; i < n; i++) {
        PhongThi phong;
        cout << "Nhap so phong, nha, kha nang chua: ";
        cin >> phong.soPhong >> phong.tenNha >> phong.khaNangChua;
        danhSach.push_back(phong);
    }
}

// Hàm in danh sách phòng thi
void inDanhSach(const vector<PhongThi>& danhSach) {
    for (const auto& phong : danhSach) {
        cout << "Phong " << phong.soPhong << " - Nha " << phong.tenNha << " - Suc chua " << phong.khaNangChua << endl;
    }
    cout << "----------------------------" << endl;
}

// Hàm sắp xếp giảm dần theo Khả năng chứa
void sapXepTheoKhaNangChua(vector<PhongThi>& danhSach) {
    sort(danhSach.begin(), danhSach.end(), [](const PhongThi& a, const PhongThi& b) {
        return a.khaNangChua > b.khaNangChua;
        });
}

// Hàm sắp xếp theo Nhà (A->Z), cùng Nhà thì theo Số phòng tăng dần
void sapXepTheoNhaTangDan(vector<PhongThi>& danhSach) {
    sort(danhSach.begin(), danhSach.end(), [](const PhongThi& a, const PhongThi& b) {
        if (a.tenNha == b.tenNha) return a.soPhong < b.soPhong;
        return a.tenNha < b.tenNha;
        });
}

// Hàm sắp xếp theo Nhà (A->Z), cùng Nhà thì theo Khả năng chứa giảm dần
void sapXepTheoNhaGiamKhaNangChua(vector<PhongThi>& danhSach) {
    sort(danhSach.begin(), danhSach.end(), [](const PhongThi& a, const PhongThi& b) {
        if (a.tenNha == b.tenNha) return a.khaNangChua > b.khaNangChua;
        return a.tenNha < b.tenNha;
        });
}

int main() {
    int n;
    cout << "Nhap so luong phong thi: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong phong thi khong hop le." << endl;
        return 1; // Thoát với mã lỗi
    }

    vector<PhongThi> danhSach;
    nhapDanhSach(danhSach, n);

    // 1. Sắp xếp giảm dần theo Khả năng chứa
    sapXepTheoKhaNangChua(danhSach);
    cout << "Danh sach phong thi (giam dan theo suc chua):" << endl;
    inDanhSach(danhSach);

    // 2. Sắp xếp theo Nhà (A->Z), cùng Nhà thì theo Số phòng tăng dần
    sapXepTheoNhaTangDan(danhSach);
    cout << "Danh sach phong thi (tang dan theo Nha, cung Nha tang dan theo so phong):" << endl;
    inDanhSach(danhSach);

    // 3. Sắp xếp theo Nhà (A->Z), cùng Nhà thì theo Khả năng chứa giảm dần
    sapXepTheoNhaGiamKhaNangChua(danhSach);
    cout << "Danh sach phong thi (tang dan theo Nha, cung Nha giam dan theo suc chua):" << endl;
    inDanhSach(danhSach);

    return 0;
}