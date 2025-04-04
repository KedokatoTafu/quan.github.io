#include <iostream>
using namespace std;
#define MAX 100

void NhapMangKyTu(char **a, int *n) {
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> *n;
    while(*n <= 0 || *n > MAX) {
        cout << "Nhap sai! Nhap lai: ";
        cin >> *n;
    }
    *a = new char[*n]; 
    for (int i = 0; i < *n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> *((*a) + i);
    }
}

void KiemTraMangKyTu(char *a, int n) {
    bool chanLe = true;  
    bool toanChan = true; 
    for (int i = 0; i < n - 1; i++) {
        if ((*(a + i)) % 2 == (*(a + i + 1)) % 2) {
            chanLe = false;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((*(a + i)) % 2 != 0) {
            toanChan = false;
            break;
        }
    }
    if (chanLe)
        cout << "+ Day co tinh chat chan le" << endl;
    else
        cout << "+ Day khong co tinh chat chan le" << endl;
    
    if (toanChan)
        cout << "+ Day co tinh chat toan chan" << endl;
    else
        cout << "+ Day khong co tinh chat toan chan" << endl;
}

int main() {
    char *a = NULL;
    int n;
    
    NhapMangKyTu(&a, &n);
    
    KiemTraMangKyTu(a, n);
    
    delete [] a;
    
    return 0;
}