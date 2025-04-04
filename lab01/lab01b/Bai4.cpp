#include <iostream>
using namespace std;
#define MAX 100

void NhapMang(float **a, int *n) {
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> *n;
    while(*n <= 0 || *n > MAX) {
        cout << "Nhap sai! Nhap lai: ";
        cin >> *n;
    }
    *a = new float[*n];
    for(int i = 0; i < *n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> *((*a) + i);
    }
}

void XuatMang(float *a, int n) {
    cout << "Day so co " << n << " phan tu: ";
    for(int i = 0; i < n; i++) {
        cout << *((a) + i) << " ";
    }
    cout << endl;
}

void MergeArrays(float *a, int n, float *b, int m, float **c) {
    *c = new float[n + m];
    int i = 0, j = 0, k = 0;
    while(i < n && j < m) {
        if(*(a + i) <= *(b + j)) {
            *(*c + k) = *(a + i);
            i++;
        } else {
            *(*c + k) = *(b + j);
            j++;
        }
        k++;
    }
    while(i < n) {
        *(*c + k) = *(a + i);
        i++; k++;
    }
    while(j < m) {
        *(*c + k) = *(b + j);
        j++; k++;
    }
}

int main() {
    float *a = NULL, *b = NULL, *c = NULL;
    int n, m;
    
    cout << "+ Day so a" << endl;
    NhapMang(&a, &n);
    
    cout << "+ Day so b" << endl;
    NhapMang(&b, &m);
    
    MergeArrays(a, n, b, m, &c);
    
    cout << "+ Day so c" << endl;
    cout << "Day so co " << (n + m) << " phan tu: ";
    XuatMang(c, n + m);
    
    delete [] a;
    delete [] b;
    delete [] c;
    system("PAUSE");
    return 0;
}