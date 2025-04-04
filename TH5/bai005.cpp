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

void CreateTree(TREE &t, int a[], int n, int &i) {
    if (i < n) {
        if (a[i] == 0) {
            t = NULL;
        } else {
            t = CreateNode(a[i]); 
            i++;
            CreateTree(t->pLeft, a, n, i); 
            i++;
            CreateTree(t->pRight, a, n, i); 
        }
    }
}

int DemMotCon(TREE t) {
    if (t == NULL)
        return 0;
    if ((t->pLeft && !t->pRight) || (!t->pLeft && t->pRight))
        return 1 + DemMotCon(t->pLeft) + DemMotCon(t->pRight);
    return DemMotCon(t->pLeft) + DemMotCon(t->pRight);
}

int main() {
    int n = 11;
    int a[] = {1, 2, 4, 0, 0, 0, 3, 0, 5, 0, 0};
    int i = 0;
    TREE root = NULL;
    CreateTree(root, a, n, i);

    cout << "So nut co mot nhanh con: " << DemMotCon(root) << endl;

    return 0;
}