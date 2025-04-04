#include <iostream>
using namespace std;

struct BST_NODE {
    int Key;  
    int So_lan;    
    struct BST_NODE* Left;
    struct BST_NODE* Right;
};

struct BST_TREE {
    struct BST_NODE* pRoot;
};
struct BST_TREE t;

BST_NODE* CreateNode(int x) {
    BST_NODE* p = new BST_NODE;
    if (p == NULL)
        return NULL;
    p->Key = x;
    p->So_lan = 1;
    p->Left = NULL;
    p->Right = NULL;
    return p;
}

void Insert(BST_TREE &t, int theKey) {
    if (t.pRoot == NULL) {
        BST_NODE* newNode = CreateNode(theKey);
        t.pRoot = newNode;
        return;
    }
    BST_NODE* current = t.pRoot;
    while (true) {
        if (theKey < current->Key) {
            if (current->Left == NULL) {
                current->Left = CreateNode(theKey);
                break;
            }
            current = current->Left;
        }
        else if (theKey > current->Key) {
            if (current->Right == NULL) {
                current->Right = CreateNode(theKey);
                break;
            }
            current = current->Right;
        }
        else { 
            current->So_lan++;
            break;
        }
    }
}

int DeleteNode(BST_TREE &t, int x) {
    if (t.pRoot == NULL)
        return 0;
    if (t.pRoot->Key == x) {
        if (t.pRoot->So_lan > 0) {
            t.pRoot->So_lan--;
            return 1;
        }
        return 0;
    }
    if (x < t.pRoot->Key)
        return DeleteNode(*(BST_TREE*)&t.pRoot->Left, x);
    return DeleteNode(*(BST_TREE*)&t.pRoot->Right, x);
}

void XoaGiaTri(BST_TREE &t, int X) { 
    int kq = DeleteNode(t, X);
    if (kq == 0)
        printf("Khong ton tai X hoac So_lan da la 0\n");
    else
        printf("Xoa thanh cong.\n");
}

void NLR(BST_NODE* Root) {
    if (Root == NULL)
        return;
    if (Root->So_lan > 0)
        printf("%4d (So_lan: %d)", Root->Key, Root->So_lan);
    NLR(Root->Left);
    NLR(Root->Right);
}

void LietKe(BST_TREE t) {
    NLR(t.pRoot);
    printf("\n");
}

int main() {
    BST_TREE t;
    t.pRoot = NULL;

    int a[] = {10, 5, 15, 5, 10, 3, 9, 15, 20};
    int n = 9;
    for (int i = 0; i < n; i++) {
        Insert(t, a[i]);
    }

    printf("Cay ban dau (NLR):\n");
    LietKe(t);

    XoaGiaTri(t, 5);
    printf("Sau khi xoa 5:\n");
    LietKe(t);

    XoaGiaTri(t, 5);
    printf("Sau khi xoa 5 lan nua:\n");
    LietKe(t);

    XoaGiaTri(t, 7);
    printf("Sau khi thu xoa 7:\n");
    LietKe(t);

    return 0;
}

