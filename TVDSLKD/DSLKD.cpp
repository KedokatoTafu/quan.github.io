#include<stdio.h>

typedef struct node {
    int info;
    struct node* next;
} Node;

Node* pHead = NULL;

// Khởi tạo danh sách rỗng
void Init(Node* &pHead) {
    pHead = NULL;
}

// Kiểm tra danh sách rỗng
bool IsEmpty(Node* pHead) {
    return (pHead == NULL);
}

// Tạo một Node mới
Node* CreateNode(int X) {
    Node* p = new Node;
    p->info = X;
    p->next = NULL;
    return p;
}

// Duyệt 1 danh sách liên kết (dùng while)
void ShowList(Node* pHead)
{
    Node* p = pHead;
    if(p == NULL)
        printf("\n Danh sach rong");
    else
        while(p != NULL)
        {
            printf("%d \t",p->info);
            p = p->next;
        }
}

// (Dùng for)
/*void ShowList(Node* pHead)
{
    if(pHead == NULL)
        printf("\n Danh sach rong");
    else
        for (Node* p = pHead; p!=NULL; p = p->next)
            printf("%d \t",p->info);
}*/

// Tìm kiếm 1 phần tử
Node* Find(Node* pHead, int x)
{
    // x la noi dung can tim
    bool found = false;
    Node *p = pHead;
    while ((p != NULL) && (! found))
        if (p->info == x)
            found = true;
        else
            p = p->next;
    if (! found)
        p = NULL;
    return p;
}

Node* FindOrder(Node* pHead, int x)
{
    // Tìm x trong danh sách đã có thứ tự
    bool found = false;
    Node *p = pHead;
    while ((p != NULL) && (! found))
        if (p->info == x)
            found = true;
        else if (p->info < x)
            p = p->next;
        else
            p = NULL;
    if (! found)
        p = NULL;
    return p;
}

// Thêm 1 phần tửtử vào đầu danh sách
void InsertFirst(Node* &pHead, int x) {
    Node* p = CreateNode(x);
    p->next = pHead;
    pHead = p;
}

// Thêm 1 phần tử vào sau 1 nútnút
void InsertAfter(Node* p, int x)
{
    if(p!=NULL){
        // Thêm vào ngay sau item
        Node* q = CreateNode(x);
        q->next = p->next; // (1)
        p->next = q; // (2)
    }
}

// Thêm vào danh sách có thứ tự
void InsertOrder(Node* &pHead, int x)
{
    // Thêm x vào danh sách có thứ tự tăng dần
    Node* tp;
    Node* p = pHead;
    bool cont = true;
    while ((p != NULL) && cont)
        if (p->info < x)
        {
            tp = p;
            p = p->next;
        }
        else cont = false;
    // Xen nút q vào giữa nút p và nút tp
    if(p == pHead)
        InsertFirst(pHead, x);
    else
        InsertAfter(tp, x);
}

// Loại bỏ 1 phần tử ở đầu danh sáchsách
void DeleteFirst(Node* &pHead)
{
    if (IsEmpty(pHead))
        printf("List is empty!");
    else {
        Node *p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

// Loại bỏ 1 phần tử sau
void DeleteAfter(Node* p)
{
    // Thêm x vào danh sách có thứ tự tăng dần
    if (p==NULL || p->next ==NULL)
        //kiem tra nut sau p co ton tai ko
        printf("Khong the xoa nut nay!");
    else {
        Node* q = p->next;
        p->next = q->next;
        delete q;
    }
}

// Loại bỏ một phần tử có nội dung X
Node* Remove(Node* &pHead, int x)
// Tìm và bỏ x trong danh sách first chưa có thứ tự
{
    Node *tp;
    Node *p = pHead;
    bool found = false;
    while ((p != NULL) && ! found) {
        if (p->info != x)
        {
            tp = p;
            p = p->next;
        }
        else
            found = true;
    }
    if (found)
    {
        if (p == pHead) // Loại bỏ phần tử đầu tiên
            pHead = p->next;
        else
            tp->next = p->next;
        delete p;
    }
}

Node* RemoveOrder(Node* &pHead, int x)
// Tìm và bỏ x trong danh sách first đã có thứ tự
{
    Node *tp;
    Node *p = pHead;
    bool found = false;
    while ((p != NULL) && ! found) {
        if (p->info < x)
        {
            tp = p;
            p = p->next;
        }
        else if( p->info == x) found = true;
        else p = NULL;
    }
    if (found)
    {
        if (p == pHead) // Loại bỏ phần tử đầu tiên
            pHead = p->next;
        else
            tp->next = p->next;
        delete p;
    }
}

// Xóa toàn bộ danh sách
void ClearList(Node* &pHead)
// Xóa toàn bộ danh sách
{
    Node* p;
    while (pHead!=NULL){
        p = pHead;
        pHead = p->next;
        delete p;
    } // hết while
} // hết ClearList

// Sắp xếp danh sách dùng Selection Sort
void SelectionSort(Node* &pHead)
// Sắp xếp danh sách tăng dần
{
    Node * p, *q, *pmin;
    int vmin;
    for(p = pHead; p->next != NULL; p = p->next){
        vmin = p->info;
        pmin = p;
        for(q = p->next;q != NULL;q = q->next){
            if (q->info < vmin) {
                vmin = q->info;
                pmin = q;
            } // hết if
        } // hết for q
        pmin->info = p->info;
        p->info = vmin;
    } // hết for p
} // hết Sort