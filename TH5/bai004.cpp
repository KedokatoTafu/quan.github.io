#include<iostream>

using namespace std;

struct node
{
    int info;
    struct node*pLeft;
    struct node*pRight;
};
typedef struct node NODE;
typedef NODE*TREE;

NODE* NhoNhat(TREE Root)
{
    if(Root==NULL)
        return NULL;
    NODE*lc = Root;
    while(lc->pLeft)
        lc = lc->pLeft;
    return lc;
}

NODE* LonNhat(TREE Root)
{
    if(Root==NULL)
        return NULL;
    NODE*lc = Root;
    while(lc->pRight)
        lc = lc->pRight;
    return lc;
}

NODE* CreateNode(int x){
    NODE *p = new NODE;
    if(p==NULL)
        return NULL;
    p->info = x;
    p->pLeft = NULL;
    p->pRight= NULL;
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

int main() {
    TREE Root = NULL;
    int a[] = {10, 5, 15, 3, 9, 12, 18, 7, 20};
    int n = 9;

    for (int i = 0; i < n; i++) {
        Insert(Root, a[i]);
    }

    NODE* minNode = NhoNhat(Root);
    cout << "Phan tu nho nhat: " << minNode->info << endl;

    NODE* maxNode = LonNhat(Root);
    cout << "Phan tu lon nhat: " << maxNode->info << endl;

    return 0;
}