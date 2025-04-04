#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
    int front;
    int rear;
    int count;
    int size;
    int *arr;
} Queue;

void Init(Queue &s, int size) {
    s.front = s.rear = -1;
    s.count = 0;
    s.size = size;
    s.arr = new int[s.size];
}

bool IsEmpty(Queue &q) {
    return q.front == -1;
}

bool IsFull(Queue &q) {
    return (q.rear - q.front + 1 == 0) || (q.rear - q.front + 1 == q.size);
}

void Enqueue(Queue &q, int x) {
    if (q.front == -1)
        q.front = 0;
    q.rear++;
    if (q.rear == q.size)
        q.rear = 0;
    q.arr[q.rear] = x;
    q.count++;
}

int Dequeue(Queue &q) {
    int x = q.arr[q.front];
    if (q.front == q.rear) {
        q.front = -1;
        q.rear = -1;
    } else {
        q.front++;
        if (q.front == q.size)
            q.front = 0;
    }
    q.count--;
    return x;
}

int Peek(Queue &q) {
    return q.arr[q.front];
}

void Clear(Queue &q) {
    q.front = -1;
    q.rear = -1;
    q.count = 0;
    delete[] q.arr;
}

typedef struct Node {
    int info;
    struct Node* next;
} Node;

typedef struct {
    Node *front, *rear;
    int count;
} LinkedQueueInt;

Node* CreateNode(int x) {
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void InitQueue(LinkedQueueInt &q) {
    q.front = q.rear = NULL;
    q.count = 0;
}

bool IsEmpty(LinkedQueueInt &q) {
    return q.front == NULL;
}

void Enqueue(LinkedQueueInt &q, int x) {
    Node* p = CreateNode(x);
    if (q.front == NULL) {
        q.front = q.rear = p;
    } else {
        q.rear->next = p;
        q.rear = p;
    }
    q.count++;
}

int Dequeue(LinkedQueueInt &q) {
    if (IsEmpty(q)) return -1;
    Node *p = q.front;
    int x = p->info;
    q.front = p->next;
    if (q.front == NULL) q.rear = NULL;
    delete p;
    q.count--;
    return x;
}

int PeekQueue(LinkedQueueInt &q) {
    if (IsEmpty(q)) return -1;
    return q.front->info;
}

void Clear(LinkedQueueInt &q) {
    while (!IsEmpty(q)) {
        Dequeue(q);
    }
}

struct Dancer {
    char name[100];
    char sex[10];
};

void GetName(Dancer &d, const char *n) {
    strcpy(d.name, n);
}

char* ToString(Dancer &d) {
    return d.name;
}

void NewDancers(Queue &male, Queue &female, char dancers[][30]) {
    Dancer m, w;
    if (male.count > 0 && female.count > 0) {
        int mId = Dequeue(male);
        int fId = Dequeue(female);
        GetName(m, dancers[mId - 1] + 2);
        GetName(w, dancers[fId - 1] + 2);
        printf("Cap dien vien: %s va %s\n", m.name, w.name);
    } else if ((male.count > 0) && (female.count == 0))
        printf("Dang cho dien vien nu.\n");
    else if ((female.count > 0) && (male.count == 0))
        printf("Dang cho dien vien nam.\n");
}

void HeadOfLine(Queue &male, Queue &female, char dancers[][30]) {
    Dancer m, w;
    if (male.count > 0)
        GetName(m, dancers[Peek(male) - 1] + 2);
    if (female.count > 0)
        GetName(w, dancers[Peek(female) - 1] + 2);
    if (male.count > 0 && female.count > 0)
        printf("Cap dien vien ke tiep: %s \t %s\n", m.name, w.name);
    else if (male.count > 0)
        printf("Dien vien nam ke tiep: %s\n", m.name);
    else if (female.count > 0)
        printf("Dien vien nu ke tiep: %s\n", w.name);
}

void StartDancing(Queue &male, Queue &female, char dancers[][30]) {
    Dancer m, w;
    printf("Cac cap dien vien:\n");
    for (int i = 0; i <= 3; i++) {
        if (IsEmpty(male) || IsEmpty(female)) break;
        int mId = Dequeue(male);
        int fId = Dequeue(female);
        GetName(m, dancers[mId - 1] + 2);
        GetName(w, dancers[fId - 1] + 2);
        printf("%s \t %s\n", m.name, w.name);
    }
}

void ShowQueue(Queue &q, char dancers[][30]) {
    int tempFront = q.front;
    int tempCount = q.count;
    while (tempCount > 0) {
        int id = q.arr[tempFront];
        printf("%s ", dancers[id - 1] + 2);
        tempFront++;
        if (tempFront == q.size) tempFront = 0;
        tempCount--;
    }
    printf("\n");
}

void FormLines(Queue &male, Queue &female) {
    Dancer d;
    char dancers[][30] = {"F Trang", "M Truc", "M Thien", "M Bao", "F Thu", 
                          "M Tien", "F Thuy", "M Nghia", "F Thao", "M Phuoc", 
                          "M Hung", "F Vy"};
    int n = 12;
    char person[30];
    for (int i = 0; i < n; i++) {
        strcpy(person, dancers[i]);
        strncpy(d.sex, person, 1);
        strncpy(d.name, person + 2, strlen(person) - 2);
        d.name[strlen(person) - 2] = '\0';
        if (strcmp(d.sex, "M") == 0)
            Enqueue(male, i + 1);
        else
            Enqueue(female, i + 1);
    }
}

enum DigitType {ONES = 1, TENS = 10};

void DisplayArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void RadixSort(Queue bin[], int a[], int n, int digit) {
    int snum;
    for (int i = 0; i < n; i++) {
        if (digit == ONES)
            snum = a[i] % 10;
        else
            snum = a[i] / 10;
        Enqueue(bin[snum], a[i]);
    }
}

void BuildArray(Queue bin[], int a[], int n) {
    n = 0;
    for (int i = 0; i <= 9; i++)
        while (bin[i].count > 0) {
            a[n] = Dequeue(bin[i]);
            n++;
        }
}

int main() {
    // Phần (b)
    Queue males, females;
    Init(males, 10);
    Init(females, 10);
    
    char dancers[][30] = {"F Trang", "M Truc", "M Thien", "M Bao", "F Thu", 
                          "M Tien", "F Thuy", "M Nghia", "F Thao", "M Phuoc", 
                          "M Hung", "F Vy"};
    
    FormLines(males, females);
    printf("Danh sach dien vien nam:");
    ShowQueue(males, dancers);
    printf("Danh sach dien vien nu:");
    ShowQueue(females, dancers);
    
    StartDancing(males, females, dancers);
    if ((males.count > 0) || (females.count > 0))
        HeadOfLine(males, females, dancers);
    NewDancers(males, females, dancers);
    if ((males.count > 0) || (females.count > 0))
        HeadOfLine(males, females, dancers);
    NewDancers(males, females, dancers);
    printf("\n");
    
    Clear(males);
    Clear(females);
    
    // Phần (c)
    int nums[] = {91, 46, 85, 15, 92, 35, 31, 22}; 
    Queue numQueue[10];
    int n = 8; // Thêm biến n
    for (int i = 0; i < 10; i++)
        Init(numQueue[i], 10); 
    
    printf("Day ban dau: ");
    DisplayArray(nums, n);
    printf("\n");
    
    RadixSort(numQueue, nums, n, ONES);
    BuildArray(numQueue, nums, n);
    printf("Ket qua buoc 1:");
    DisplayArray(nums, n);
    printf("\n\n");
    
    RadixSort(numQueue, nums, n, TENS);
    BuildArray(numQueue, nums, n); 
    printf("Ket qua buoc 2: ");
    DisplayArray(nums, n);
    printf("\n");
    
    for (int i = 0; i < 10; i++)
        Clear(numQueue[i]);
    
    return 0;
}