#include <iostream>
using namespace std;

void phanTuChung(int x[], int nx, int y[], int ny, int z[], int nz) {
    for (int i = 0; i < nx - 1; ++i) {
        for (int j = 0; j < nx - i - 1; ++j) {
            if (x[j] > x[j + 1]) swap(x[j], x[j + 1]);
        }
    }
    for (int i = 0; i < ny - 1; ++i) {
        for (int j = 0; j < ny - i - 1; ++j) {
            if (y[j] > y[j + 1]) swap(y[j], y[j + 1]);
        }
    }
    for (int i = 0; i < nz - 1; ++i) {
        for (int j = 0; j < nz - i - 1; ++j) {
            if (z[j] > z[j + 1]) swap(z[j], z[j + 1]);
        }
    }

    int i = 0, j = 0, k = 0;
    int count = 0;
    int common[100];
    bool found = false;

    while (i < nx && j < ny && k < nz) {
        if (x[i] == y[j] && y[j] == z[k]) {
            if (!found || common[count - 1] != x[i]) {
                common[count++] = x[i];
                found = true;
            }
            i++;
            j++;
            k++;
        }

        else {
            if (x[i] < y[j] && x[i] < z[k]) {
                i++;
            }
            
            else if (y[j] < z[k]) {
                j++;
            }
            
            else {
                k++;
            }
            found = false;
        }
    }

    cout << count << endl;

    for (int i = 0; i < count; ++i) {
        cout << common[i] << " ";
    }
    cout << endl;
}

int main() {
    int nx, ny, nz;
    cin >> nx;
    int x[nx];
    for (int i = 0; i < nx; ++i) cin >> x[i];

    cin >> ny;
    int y[ny];
    for (int i = 0; i < ny; ++i) cin >> y[i];

    cin >> nz;
    int z[nz];
    for (int i = 0; i < nz; ++i) cin >> z[i];

    phanTuChung(x, nx, y, ny, z, nz);
    return 0;
}