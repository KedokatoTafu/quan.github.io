#include <iostream>
using namespace std;
void sap_xep_giam_dan(int arr[], int vi_tri[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);     
                swap(vi_tri[i], vi_tri[j]); 
            }
        }
    }
}
void tim_k_gia_tri_lon_nhat(int arr[], int n, int k) {
    int* arrCopy = new int[n]; 
    int* vi_tri = new int[n]; 
    for (int i = 0; i < n; ++i) {
        arrCopy[i] = arr[i];
        vi_tri[i] = i;
    }
    sap_xep_giam_dan(arrCopy, vi_tri, n);
    cout << "Vi tri cua " << k << " phan tu co gia tri lon nhat : ";
    for (int i = 0; i < k; ++i) {
        cout << vi_tri[i] << " ";
    }
    cout << endl;
    delete[] arrCopy;
    delete[] vi_tri;
}

int main() {
    int n, k;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    int* arr = new int[n]; 
    cout << "Nhap " << n << " phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Nhap so k: ";
    cin >> k;
    tim_k_gia_tri_lon_nhat(arr, n, k);
    delete[] arr;
    return 0;
}

