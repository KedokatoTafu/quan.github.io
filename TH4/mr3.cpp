#include <iostream>
using namespace std;

typedef struct {
    int top;
    int count;
    int size;
    int *arr;
} StackInt;

void InitStack(StackInt &s, int size) {
    s.top = -1;
    s.count = 0;
    s.size = size;
    s.arr = new int[s.size];
}

bool IsEmpty(StackInt &s) {
    return s.top == -1;
}

bool IsFull(StackInt &s) {
    return s.top == s.size - 1;
}

void PushStack(StackInt &s, int x) {
    if (!IsFull(s)) {
        s.top++;
        s.arr[s.top] = x;
        s.count++;
    }
}

int PopStack(StackInt &s) {
    if (IsEmpty(s)) return -1;
    int x = s.arr[s.top];
    s.top--;
    s.count--;
    return x;
}

void Clear(StackInt &s) {
    s.top = -1;
    s.count = 0;
    delete[] s.arr;
}

long fibo(int n) {
    if (n == 0 || n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

long fiboStack(int n) {
    StackInt s;
    InitStack(s, n + 1);
    
    PushStack(s, n);
    long total = 0;
    
    while (!IsEmpty(s)) {
        int current = PopStack(s);
        
        if (current == 0 || current == 1) {
            total += 1;
        } else {
            PushStack(s, current - 1);
            PushStack(s, current - 2);
        }
    }
    
    Clear(s);
    return total;
}

void reverseNumber(int n) {
    if (n < 10) {
        cout << n;
        return;
    }
    cout << n % 10;
    reverseNumber(n / 10);
}

void reverseNumberStack(int n) {
    StackInt s;
    InitStack(s, 10);
    
    while (n > 0) {
        PushStack(s, n % 10);
        n /= 10;
    }
    
    while (!IsEmpty(s)) {
        cout << PopStack(s);
    }
    
    Clear(s);
}

void DiChuyen(int n, int a, int b, int c) {
    if (n == 1)
        cout << a << " -> " << c << endl;
    else {
        DiChuyen(n - 1, a, c, b);
        DiChuyen(1, a, b, c);
        DiChuyen(n - 1, b, a, c);
    }
}

struct TowerState {
    int n;
    int a, b, c;
    int step;
};

typedef struct {
    int top;
    int count;
    int size;
    TowerState *arr;
} TowerStack;

void InitTowerStack(TowerStack &s, int size) {
    s.top = -1;
    s.count = 0;
    s.size = size;
    s.arr = new TowerState[s.size];
}

bool IsEmpty(TowerStack &s) {
    return s.top == -1;
}

bool IsFull(TowerStack &s) {
    return s.top == s.size - 1;
}

void PushTowerStack(TowerStack &s, TowerState x) {
    if (!IsFull(s)) {
        s.top++;
        s.arr[s.top] = x;
        s.count++;
    }
}

TowerState PopTowerStack(TowerStack &s) {
    TowerState x = {0, 0, 0, 0, 0};
    if (!IsEmpty(s)) {
        x = s.arr[s.top];
        s.top--;
        s.count--;
    }
    return x;
}

void ClearTowerStack(TowerStack &s) {
    s.top = -1;
    s.count = 0;
    delete[] s.arr;
}

void hanoiStack(int n, int a, int b, int c) {
    TowerStack s;
    InitTowerStack(s, n * 3); // Kích thước đủ lớn cho 3 bước mỗi tầng
    
    PushTowerStack(s, {n, a, b, c, 0});
    
    while (!IsEmpty(s)) {
        TowerState current = PopTowerStack(s);
        
        if (current.n == 1) {
            cout << current.a << " -> " << current.c << endl;
        } else {
            if (current.step == 0) {
                PushTowerStack(s, {current.n, current.a, current.b, current.c, 1});
                PushTowerStack(s, {current.n - 1, current.a, current.c, current.b, 0});
            } else if (current.step == 1) {
                PushTowerStack(s, {current.n, current.a, current.b, current.c, 2});
                PushTowerStack(s, {1, current.a, current.b, current.c, 0});
            } else if (current.step == 2) {
                PushTowerStack(s, {current.n - 1, current.b, current.a, current.c, 0});
            }
        }
    }
    
    ClearTowerStack(s);
}

int main() {
    // (a) Fibonacci
    int n1;
    cout << "Nhap n de tinh Fibonacci: ";
    cin >> n1;
    cout << "F(" << n1 << ") bang de quy: " << fibo(n1) << endl;
    cout << "F(" << n1 << ") bang stack: " << fiboStack(n1) << endl;
    
    // (b) Đảo số
    int n2;
    cout << "Nhap so de dao nguoc: ";
    cin >> n2;
    cout << "Dao nguoc bang de quy: ";
    reverseNumber(n2);
    cout << endl;
    cout << "Dao nguoc bang stack: ";
    reverseNumberStack(n2);
    cout << endl;
    
    // (c) Tháp Hà Nội
    int n3;
    cout << "Nhap so tang thap Hanoi: ";
    cin >> n3;
    cout << "Di chuyen bang de quy:\n";
    DiChuyen(n3, 1, 2, 3);
    cout << "Di chuyen bang stack:\n";
    hanoiStack(n3, 1, 2, 3);
    
    return 0;
}