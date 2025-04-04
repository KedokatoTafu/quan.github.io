#include <stdio.h>

#define MAX 5

struct SoHang {
    float heSo;  
    int bac;    
};

void Swap(struct SoHang& x, struct SoHang& y) {
    struct SoHang temp = x;
    x = y;
    y = temp;
}

void BubbleNoFlag(struct SoHang a[], int n) {
    for (int i = n - 1; i >= 1; i--)
        for (int j = 0; j <= i - 1; j++)
            if (a[j].bac > a[j + 1].bac) 
                Swap(a[j], a[j + 1]);    
}

void xuatMang(struct SoHang a[], int n) {
    printf("Day so hang da sap xep theo bac tang dan:\n");
    for (int i = 0; i < n; i++) {
        printf("He so: %.2f, Bac: %d\n", a[i].heSo, a[i].bac);
    }
}

int main() {
    struct SoHang a[MAX] = {
        {3.5, 20},
        {1.2, 5},
        {4.8, 15},
        {2.1, 10},
        {0.9, 8}
    };

    printf("Day so hang truoc khi sap xep:\n");
    for (int i = 0; i < MAX; i++) {
        printf("He so: %.2f, Bac: %d\n", a[i].heSo, a[i].bac);
    }

    BubbleNoFlag(a, MAX);

    xuatMang(a, MAX);

    return 0;
}

