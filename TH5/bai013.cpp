#include <iostream>
using namespace std;

struct node {
    float info;
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

void Insert(TREE &p, float theKey) {
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

void NLR(TREE t, FILE* fp) {
    if (t == NULL)
        return;
    fwrite(&t->info, sizeof(float), 1, fp);
    NLR(t->pLeft, fp);
    NLR(t->pRight, fp);
}

int Xuat(char *filename, TREE t) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL)
        return 0;
    NLR(t, fp);
    fclose(fp);
    return 1;
}

void DocVaTaoBST(TREE &t, char *filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        return;
    }

    int x;
    t = NULL;
    while (fread(&x, sizeof(float), 1, fp) == 1) { 
        Insert(t, x);
    }
    fclose(fp);
}

void NLR_Print(TREE t) {
    if (t == NULL)
        return;
    cout << t->info << " ";
    NLR_Print(t->pLeft);
    NLR_Print(t->pRight);
}

int main() {
    TREE root = NULL;
    int a[] = {10, 5, 15, 3, 9, 12, 18, 7, 20};
    int n = 9;
    TREE newRoot = NULL;

    for (int i = 0; i < n; i++) {
        Insert(root, a[i]);
    }

    cout << "Cay ban dau: ";
    NLR_Print(root);
    cout << endl;

    Xuat("data.out", root);
    cout << "Xuat cay ra tap tin data.out thanh cong!" << endl;

    DocVaTaoBST(newRoot, "data.out");

    cout << "Cay tai tao: ";
    NLR_Print(newRoot);
    cout << endl;

    return 0;
}