#include <iostream>
using namespace std;

struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void Init(TREE &t) {
    t = NULL;
}

NODE* GetNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

int InsertNode(TREE &t, int x) {
    if (t) {
        if (t->info == x)
            return 0;
        if (t->info < x)
            return InsertNode(t->pRight, x);
        return InsertNode(t->pLeft, x);
    }
    t = GetNode(x);
    if (t == NULL)
        return -1;
    return 1;
}

int TaoCay(TREE &t, int a[], int n) {
    Init(t);
    for (int i = 0; i < n; i++) {
        if (InsertNode(t, a[i]) == -1)
            return 0;
    }
    return 1;
}

void LNR(TREE t, int a[], int &n) {
    if (t == NULL)
        return;
    LNR(t->pLeft, a, n);
    a[n] = t->info; 
    n++;
    LNR(t->pRight, a, n);
}

void RemoveAll(TREE &t) {
    if (t == NULL)
        return;
    RemoveAll(t->pLeft);
    RemoveAll(t->pRight);
    delete t;
    t = NULL;
}

void SortArray(int a[], int n) {
    TREE t;
    if (TaoCay(t, a, n)) {
        int index = 0;
        LNR(t, a, index);
    }
    RemoveAll(t);
}

void NLR(TREE t) {
    if (t == NULL)
        return;
    cout << t->info << " ";
    NLR(t->pLeft);
    NLR(t->pRight);
}

void XuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int a[] = {10, 5, 15, 3, 9, 12, 18, 7, 20};
    int n = 9;
    TREE t;

    cout << "Mang truoc khi sap xep: ";
    XuatMang(a, n);
    cout<<endl;

    TaoCay(t, a, n);
    cout << "Cay sau khi tao: ";
    NLR(t);
    cout << endl;

    SortArray(a, n);

    cout << "Mang sau khi sap xep tang dan: ";
    XuatMang(a, n);

    return 0;
}