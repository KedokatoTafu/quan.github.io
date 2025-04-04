#include <iostream>
using namespace std;
#define MAX 100

void NhapMang(int **a, int *n) {
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> *n;
    while(*n <= 0 || *n > MAX) {
        cout << "Nhap sai! Nhap lai: ";
        cin >> *n;
    }
    *a = new int[*n]; 
    for(int i = 0; i < *n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> *((*a) + i);
    }
}

void XuatMang(int *a, int n) {
    cout << "Day so co " << n << " phan tu: ";
    for(int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
    cout << endl;
}

void KiemTraMang(int *a, int n) {
    bool chanLe = true;
    bool toanChan = true;
    for(int i = 0; i < n - 1; i++) {
        if( (*(a + i)) % 2 == (*(a + i + 1)) % 2 ) {
            chanLe = false;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if( (*(a + i)) % 2 != 0 ) {
            toanChan = false;
            break;
        }
    }
    if(chanLe)
        cout << "+ Day co tinh chat chan le" << endl;
    else
        cout << "+ Day khong co tinh chat chan le" << endl;
    
    if(toanChan)
        cout << "+ Day co tinh chat toan chan" << endl;
    else
        cout << "+ Day khong co tinh chat toan chan" << endl;
}

int main() {
    int *a = NULL;
    int n;
    
    cout << "+ Day so a" << endl;
    NhapMang(&a, &n);
    
    KiemTraMang(a, n);
    
    delete [] a;
    system("PAUSE");
    return 0;
}