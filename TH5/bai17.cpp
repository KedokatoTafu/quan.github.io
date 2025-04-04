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
        p = CreateNode(theKey);
        return;
    }
    if (theKey < p->info)
        Insert(p->pLeft, theKey);
    else if (theKey > p->info)
        Insert(p->pRight, theKey);
}

void SearchStandFor(TREE &p, TREE &q) {
    if (q->pLeft) {
        SearchStandFor(p, q->pLeft);
    }
    else {
        p->info = q->info;
        TREE temp = q;
        q = q->pRight;
        delete temp;
    }
}

void Delete(TREE &p, int theKey) {
    if (p != NULL) {
        if (p->info > theKey)
            Delete(p->pLeft, theKey);
        else if (p->info < theKey)
            Delete(p->pRight, theKey);
        else {
            NODE* q = p;
            if (q->pRight == NULL) {
                p = q->pLeft;
                delete q;
            }
            else if (q->pLeft == NULL) {
                p = q->pRight;
                delete q;
            }
            else {
                SearchStandFor(p, p->pRight);
            }
        }
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

    Delete(t, 15);
    cout << "Cay sau khi xoa 15 (NLR): ";
    NLR(t);
    cout << endl;

    Delete(t, 5);
    cout << "Cay sau khi xoa 5 (NLR): ";
    NLR(t);
    cout << endl;

    RemoveAll(t);

    return 0;
}