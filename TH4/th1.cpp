#include <iostream>
#include <string>
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

int PeekStack(StackInt &s) {
    if (IsEmpty(s)) return -1;
    return s.arr[s.top];
}

void Clear(StackInt &s) {
    s.top = -1;
    s.count = 0;
}

typedef struct Node {
    int info;
    struct Node *next;
} Node;

typedef struct {
    Node* top;
    int count;
} LinkedStackInt;

Node* CreateNode(int x) {
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void InitStack(LinkedStackInt &s) {
    s.top = NULL;
    s.count = 0;
}

bool IsEmpty(LinkedStackInt &s) {
    return s.top == NULL;
}

void PushStack(LinkedStackInt &s, int x) {
    Node *p = CreateNode(x);
    p->next = s.top;
    s.top = p;
    s.count++;
}

int PopStack(LinkedStackInt &s) {
    if (IsEmpty(s)) return -1;
    int x = s.top->info;
    Node *p = s.top;
    s.top = s.top->next;
    delete p;
    s.count--;
    return x;
}

int PeekStack(LinkedStackInt &s) {
    if (IsEmpty(s)) return -1;
    return s.top->info;
}

void Clear(LinkedStackInt &s) {
    while (s.top != NULL) {
        Node* p = s.top;
        s.top = s.top->next;
        delete p;
    }
    s.count = 0;
}

void ReverseNumber(int n) {
    StackInt s;
    InitStack(s, 10);
    
    while (n > 0) {
        PushStack(s, n % 10);
        n /= 10;
    }
    
    cout << "So dao nguoc: ";
    while (!IsEmpty(s)) {
        cout << PopStack(s);
    }
    cout << endl;
    delete[] s.arr;
}

typedef struct {
    char* arr;
    int top;
    int size;
} StackString;

void InitStack(StackString &s, int size) {
    s.top = -1;
    s.size = size;
    s.arr = new char[size];
}

bool IsEmpty(StackString &s) {
    return s.top == -1;
}

void PushStack(StackString &s, char x) {
    if (s.top < s.size - 1) {
        s.top++;
        s.arr[s.top] = x;
    }
}

char PopStack(StackString &s) {
    if (IsEmpty(s)) return '\0';
    char x = s.arr[s.top];
    s.top--;
    return x;
}

bool IsPalindrome(string str) {
    StackString s;
    InitStack(s, str.length());
    
    for (int i = 0; i < str.length()/2; i++) {
        PushStack(s, str[i]);
    }
    
    int start = str.length()/2 + str.length()%2;
    for (int i = start; i < str.length(); i++) {
        if (str[i] != PopStack(s)) {
            delete[] s.arr;
            return false;
        }
    }
    delete[] s.arr;
    return true;
}

void DecimalToBinary(int n) {
    StackInt s;
    InitStack(s, 32);
    
    if (n == 0) {
        cout << "So nhi phan: 0" << endl;
        delete[] s.arr;
        return;
    }
    
    while (n > 0) {
        PushStack(s, n % 2);
        n /= 2;
    }
    
    cout << "So nhi phan: ";
    while (!IsEmpty(s)) {
        cout << PopStack(s);
    }
    cout << endl;
    delete[] s.arr;
}

int main() {
    int n;
    cout << "Nhap so nguyen de dao nguoc: ";
    cin >> n;
    ReverseNumber(n);
    
    string str;
    cout << "Nhap chuoi de kiem tra doi xung: ";
    getline(cin, str);
    if (IsPalindrome(str)) {
        cout << "Chuoi \"" << str << "\" la chuoi doi xung" << endl;
    } else {
        cout << "Chuoi \"" << str << "\" khong phai chuoi doi xung" << endl;
    }
    
    int decimal;
    cout << "Nhap so thap phan de chuyen sang nhi phan: ";
    cin >> decimal;
    DecimalToBinary(decimal);
    
    return 0;
}