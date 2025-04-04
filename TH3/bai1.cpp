#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* next;
} Node;

Node* pHead = NULL;

void Init(Node* &pHead) {
    pHead = NULL;
}

bool IsEmpty(Node* pHead) {
    return (pHead == NULL);
}

Node* CreateNode(int X) {
    Node* p = new Node;
    p->info = X;
    p->next = NULL;
    return p;
}

void ShowList(Node* pHead) {
    Node* p = pHead;
    if (p == NULL)
        printf("\nDanh sach rong");
    else
        while (p != NULL) {
            printf("%d \t", p->info);
            p = p->next;
        }
    printf("\n");
}

void InsertFirst(Node* &pHead, int x) {
    Node* p = CreateNode(x);
    p->next = pHead;
    pHead = p;
}

Node* Remove(Node* &pHead, int x) {
    Node *tp, *p = pHead;
    bool found = false;
    while ((p != NULL) && !found) {
        if (p->info != x) {
            tp = p;
            p = p->next;
        } else
            found = true;
    }
    if (found) {
        if (p == pHead)
            pHead = p->next;
        else
            tp->next = p->next;
        delete p;
    }
    return pHead;
}

void ClearList(Node* &pHead) {
    Node* p;
    while (pHead != NULL) {
        p = pHead;
        pHead = p->next;
        delete p;
    }
}

// Thêm danh sách thứ hai vào danh sách thứ nhất
void AppendList(Node* &pHead1, Node* pHead2) {
    Node* p = pHead2;
    while (p != NULL) {
        InsertFirst(pHead1, p->info);
        p = p->next;
    }
}

int main() {
    Node *pHead1, *pHead2;
    int x, k;

    Init(pHead1);
    Init(pHead2);

    printf("Nhap 10 so nguyen:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &x);
        InsertFirst(pHead1, x);
    }

    printf("Danh sach 1 ban dau:\n");
    ShowList(pHead1);

    printf("Nhap so k can xoa: ");
    scanf("%d", &k);
    Remove(pHead1, k);

    printf("Danh sach 1 sau khi xoa %d:\n", k);
    ShowList(pHead1);

    printf("Nhap 5 so nguyen cho danh sach 2:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &x);
        InsertFirst(pHead2, x);
    }

    AppendList(pHead1, pHead2);

    printf("Danh sach 1 sau khi them danh sach 2:\n");
    ShowList(pHead1);

    ClearList(pHead1);
    ClearList(pHead2);

    return 0;
}