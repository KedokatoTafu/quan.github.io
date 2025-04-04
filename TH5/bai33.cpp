#include <iostream>
using namespace std;

struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

// StackStack
typedef struct stack_node {
    TREE tree_node;
    struct stack_node* next;
} StackNode;

typedef struct {
    StackNode* top;
    int count;
} Stack;

void InitStack(Stack &s) {
    s.top = NULL;
    s.count = 0;
}

StackNode* CreateStackNode(TREE x) {
    StackNode* p = new StackNode;
    p->tree_node = x;
    p->next = NULL;
    return p;
}

bool IsEmptyStack(Stack &s) {
    return s.top == NULL;
}

void Push(Stack &s, TREE x) {
    StackNode* p = CreateStackNode(x);
    p->next = s.top;
    s.top = p;
    s.count++;
}

TREE Pop(Stack &s) {
    if (IsEmptyStack(s)) return NULL;
    StackNode* p = s.top;
    TREE x = p->tree_node;
    s.top = p->next;
    s.count--;
    delete p;
    return x;
}

void ClearStack(Stack &s) {
    while (!IsEmptyStack(s)) {
        StackNode* p = s.top;
        s.top = p->next;
        delete p;
    }
    s.count = 0;
}

// Queue
typedef struct queue_node {
    TREE tree_node;
    struct queue_node* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int count;
} Queue;

void InitQueue(Queue &q) {
    q.front = q.rear = NULL;
    q.count = 0;
}

QueueNode* CreateQueueNode(TREE x) {
    QueueNode* p = new QueueNode;
    p->tree_node = x;
    p->next = NULL;
    return p;
}

bool IsEmptyQueue(Queue &q) {
    return q.front == NULL;
}

void Enqueue(Queue &q, TREE x) {
    QueueNode* p = CreateQueueNode(x);
    if (q.front == NULL) {
        q.front = q.rear = p;
    } else {
        q.rear->next = p;
        q.rear = p;
    }
    q.count++;
}

TREE Dequeue(Queue &q) {
    if (IsEmptyQueue(q)) return NULL;
    QueueNode* p = q.front;
    TREE x = p->tree_node;
    q.front = p->next;
    if (q.front == NULL) q.rear = NULL;
    q.count--;
    delete p;
    return x;
}

void ClearQueue(Queue &q) {
    while (!IsEmptyQueue(q)) {
        QueueNode* p = q.front;
        q.front = p->next;
        delete p;
    }
    q.rear = NULL;
    q.count = 0;
}

// Cây nhị phân
NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) return NULL;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(TREE &t, int x) {
    if (t == NULL) {
        t = CreateNode(x);
        return;
    }
    if (x < t->info)
        Insert(t->pLeft, x);
    else if (x > t->info)
        Insert(t->pRight, x);
}

void RemoveAll(TREE &t) {
    if (t == NULL) return;
    RemoveAll(t->pLeft);
    RemoveAll(t->pRight);
    delete t;
    t = NULL;
}

// Duyệt NLR không đệ quy dùng Stack
void PreOrderNonRecursive(TREE t) {
    if (t == NULL) return;
    Stack s;
    InitStack(s);
    Push(s, t);

    cout << "Duyet NLR bang Stack: ";
    while (!IsEmptyStack(s)) {
        TREE p = Pop(s);
        cout << p->info << " ";

        // Push nhánh phải trước (vì stack LIFO, nhánh trái sẽ được xử lý trước)
        if (p->pRight) Push(s, p->pRight);
        if (p->pLeft) Push(s, p->pLeft);
    }
    cout << endl;
    ClearStack(s);
}

// Duyệt theo mức không đệ quy dùng Queue
void LevelOrderNonRecursive(TREE t) {
    if (t == NULL) return;
    Queue q;
    InitQueue(q);
    Enqueue(q, t);

    cout << "Duyet theo muc bang Queue: ";
    while (!IsEmptyQueue(q)) {
        TREE p = Dequeue(q);
        cout << p->info << " ";

        // Thêm nhánh trái và phải vào queue (theo thứ tự từ trái sang phải)
        if (p->pLeft) Enqueue(q, p->pLeft);
        if (p->pRight) Enqueue(q, p->pRight);
    }
    cout << endl;
    ClearQueue(q);
}

int main() {
    TREE t = NULL;
    int a[] = {10, 5, 15, 3, 9, 12, 18, 7, 20};
    int n = 9;

    for (int i = 0; i < n; i++) {
        Insert(t, a[i]);
    }

    PreOrderNonRecursive(t);

    LevelOrderNonRecursive(t);

    RemoveAll(t);

    return 0;
}