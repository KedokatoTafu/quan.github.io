#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) return NULL;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(TREE &p, int theKey) {
    if (p == NULL) {
        NODE* newNode = CreateNode(theKey);
        p = newNode;
    }
    else if (p->info > theKey) { 
        Insert(p->pLeft, theKey);
    }
    else {
        Insert(p->pRight, theKey);
    }
}

int ChieuCao(TREE t) {
    if (t == NULL)
        return 0;
    int a = ChieuCao(t->pLeft);
    int b = ChieuCao(t->pRight);
    if (a > b)
        return a + 1;
    return b + 1;
}

NODE* LonNhat(TREE t) {
    if (t == NULL)
        return NULL;
    NODE* lc = t;
    NODE* a = LonNhat(t->pLeft);
    if (a && a->info > lc->info)
        lc = a;
    NODE* b = LonNhat(t->pRight);
    if (b && b->info > lc->info)
        lc = b;
    return lc;
}

NODE* NhoNhat(TREE t) {
    if (t == NULL)
        return NULL;
    NODE* lc = t;
    NODE* a = NhoNhat(t->pLeft);
    if (a && a->info < lc->info)
        lc = a;
    NODE* b = NhoNhat(t->pRight);
    if (b && b->info < lc->info)
        lc = b;
    return lc;
}

int ktCanBang(TREE Root) {
    if (Root == NULL)
        return 1;
    if (ktCanBang(Root->pLeft) == 0)
        return 0;
    if (ktCanBang(Root->pRight) == 0)
        return 0;
    NODE* a = LonNhat(Root->pLeft);
    if (a && a->info > Root->info)
        return 0;
    a = NhoNhat(Root->pRight);
    if (a && a->info < Root->info)
        return 0;
    int x = ChieuCao(Root->pLeft);
    int y = ChieuCao(Root->pRight);
    if (abs(x - y) > 1)
        return 0; 
    return 1;
}

void NLR(TREE t) {
    if (t == NULL) return;
    cout << t->info << " ";
    NLR(t->pLeft);
    NLR(t->pRight);
}

void RemoveAll(TREE &t) {
    if (t == NULL) return;
    RemoveAll(t->pLeft);
    RemoveAll(t->pRight);
    delete t;
    t = NULL;
}

int main() {
    TREE t = NULL;
    int a[] = {10, 5, 15, 3, 9, 12, 18};
    int n = 7;

    for (int i = 0; i < n; i++) {
        Insert(t, a[i]);
    }

    cout << "Cay: ";
    NLR(t);
    cout << endl;

    if (ktCanBang(t))
        cout << "Cay can bang" << endl;
    else
        cout << "Cay khong can bang" << endl;

    RemoveAll(t);

    return 0;
}