#include <iostream>
using namespace std;

struct nodetree {
    int info;
    struct nodetree* pLeft;
    struct nodetree* pRight;
};
typedef struct nodetree NODETREE;
typedef NODETREE* TREE;

struct nodelist {
    int info;
    struct nodelist* pNext;
};
typedef struct nodelist NODELIST;

struct list {
    NODELIST* pHead;
    NODELIST* pTail;
};
typedef struct list LIST;

void Init(LIST &l) {
    l.pHead = l.pTail = NULL;
}

NODELIST* GetNode(int x) {
    NODELIST* p = new NODELIST;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &l, NODELIST* p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

NODETREE* CreateNode(int x) {
    NODETREE* p = new NODETREE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void Insert(TREE &p, int theKey) {
    if (p == NULL) {
        NODETREE* newNode = CreateNode(theKey);
        p = newNode;
    }
    else if (p->info > theKey) {
        Insert(p->pLeft, theKey);
    }
    else {
        Insert(p->pRight, theKey);
    }
}

void RNL(TREE Root, LIST &l) {
    if (Root == NULL)
        return;
    RNL(Root->pRight, l);        
    NODELIST* p = GetNode(Root->info);
    if (p != NULL)
        AddTail(l, p);           
    RNL(Root->pLeft, l);           
}

void BuildList(TREE Root, LIST &l) {
    Init(l); 
    RNL(Root, l);
}

void PrintList(LIST l) {
    NODELIST* p = l.pHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

int main() {
    TREE root = NULL;
    int a[] = {10, 5, 15, 3, 9, 12, 18, 7, 20};
    int n = 9;

    for (int i = 0; i < n; i++) {
        Insert(root, a[i]);
    }

    LIST l;
    BuildList(root, l);

    cout << "Danh sach giam dan: ";
    PrintList(l);

    return 0;
}