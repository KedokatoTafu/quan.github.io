#include <iostream>
using namespace std;

struct node {
    float info; 
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

NODE* CreateNode(float x) {  
    NODE* p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void CreateTree(TREE &t, float a[], int n, int &i) {  
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

void LNR(TREE t, FILE* fp) {
    if (t == NULL)
        return;
    LNR(t->pLeft, fp);
    fwrite(&t->info, sizeof(float), 1, fp);
    LNR(t->pRight, fp);
}

int Xuat(const char *filename, TREE t) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL)
        return 0;
    LNR(t, fp);
    fclose(fp);
    return 1;
}

int main() {
    float a[] = {10.5, 5.2, 15.8, 3.1, 9.7, 12.4, 18.9, 7.6, 20.3};
    int n = 9;
    int i = 0;
    TREE root = NULL;

    CreateTree(root, a, n, i);

    if (Xuat("data.out", root))
        cout << "Xuat cay ra tap tin data.out thanh cong!" << endl;
    else
        cout << "Xuat cay that bai!" << endl;

    return 0;
}