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

void NLR(TREE t) {
    if (t == NULL)
        return;
    cout << t->info << " ";
    NLR(t->pLeft);
    NLR(t->pRight);
}

void RemoveAll(TREE &t) {
    if (t == NULL)
        return;
    RemoveAll(t->pLeft); 
    RemoveAll(t->pRight);
    delete t;
    t = NULL;
}

int main() {
    TREE t = NULL;
    int a[] = {10, 5, 15, 3, 9, 12, 18, 7, 20};
    int n = 9;

    for (int i = 0; i < n; i++) {
        Insert(t, a[i]);
    }

    cout << "Cay truoc khi xoa (NLR): ";
    NLR(t);
    cout << endl;

    RemoveAll(t);

    return 0;
}