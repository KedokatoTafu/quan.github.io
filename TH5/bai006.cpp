#include <iostream>
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
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
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

int DemNode(TREE t) {
    if (t == NULL)
        return 0;
    int a = DemNode(t->pLeft);
    int b = DemNode(t->pRight);
    return (a + b + 1);
}

int TongNode(TREE t) {
    if (t == NULL)
        return 0;
    int a = TongNode(t->pLeft);
    int b = TongNode(t->pRight);
    return (a + b + t->info);
}

int main() {
    TREE root = NULL;
    int a[] = {10, 5, 15, 3, 9, 12, 18, 7, 20};
    int n = 9;

    for (int i = 0; i < n; i++) {
        Insert(root, a[i]);
    }

    cout << "So nut trong cay: " << DemNode(root) << endl;
    cout << "Tong gia tri cac nut: " << TongNode(root) << endl;

    return 0;
}