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

int DemNode(TREE Root)
{
    if(Root==NULL)
        return 0;
    int a=DemNode(Root->pLeft);
    int b=DemNode(Root->pRight);
    return (a+b+1);
}

int TongNode(TREE Root)
{
    if(Root==NULL)
        return 0;
    int a=TongNode(Root->pLeft);
    int b=TongNode(Root->pRight);
    return (a+b+Root->info);
}

float TrungBinhCong(TREE Root)
{
    int s = TongNode(Root);
    int dem = DemNode(Root);
    if(dem==0)
        return 0;
    return (float)s/dem;
}

int DemDuong(TREE Root)
{
    if(Root==NULL)
        return 0;
    int a=DemDuong(Root->pLeft);
    int b=DemDuong(Root->pRight);
    if(Root->info>0)
        return (a+b+1);
    return (a+b);
}

int TongDuong(TREE Root)
{
    if(Root==NULL)
        return 0;
    int a=TongDuong(Root->pLeft);
    int b=TongDuong(Root->pRight);
    if(Root->info>0)
        return (a+b+Root->info);
    return (a+b);
}

float TrungBinhDuong(TREE Root)
{
    int s = TongDuong(Root);
    int dem=DemDuong(Root);
    if(dem==0)
        return 0;
    return (float)s/dem;
}

int DemAm(TREE Root)
{
    if(Root==NULL)
        return 0;
    int a=DemAm(Root->pLeft);
    int b=DemAm(Root->pRight);
    if(Root->info<0)
        return (a+b+1);
    return (a+b);
}

int TongAm(TREE Root)
{
    if(Root==NULL)
        return 0;
    int a=TongAm(Root->pLeft);
    int b=TongAm(Root->pRight);
    if(Root->info<0)
        return (a+b+Root->info);
    return (a+b);
}

float TrungBinhCongAm(TREE Root)
{
    int s = TongAm(Root);
    int dem = DemAm(Root);
    if(dem==0)
        return 0;
    return (float)s/dem;
}

float TinhTySo(TREE Root)
{
    int a = TongDuong(Root);
    int b = TongAm(Root);
    if(b==0)
        return 0;
    return (float)a/b;
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

void CreateTree(TREE &t, int a[], int n, int &i) {
    if (i < n) {
        if (a[i] == 0) {
            t = NULL;
        } else {
            t = CreateNode(a[i]); // Tạo node gốc
            i++;
            CreateTree(t->pLeft, a, n, i); // Tạo nhánh trái
            i++;
            CreateTree(t->pRight, a, n, i); // Tạo nhánh phải
        }
    }
}

int main() {
    int n = 10;
    int a[] = {1, -8, 2, 9, -3, 4, 7, 3, 6, -5};
    int i = 0;
    TREE root = NULL;
    CreateTree(root, a, n, i);

    cout << "So node: " << DemNode(root) << endl;
    cout << "Tong gia tri cac node: " << TongNode(root) << endl;
    cout << "Trung binh cong: " << TrungBinhCong(root) << endl;
    cout << "So node duong: " << DemDuong(root) << endl;
    cout << "Tong node duong: " << TongDuong(root) << endl;
    cout << "Trung binh duong: " << TrungBinhDuong(root) << endl;
    cout << "So node am: " << DemAm(root) << endl;
    cout << "Tong node am: " << TongAm(root) << endl;
    cout << "Trung binh am: " << TrungBinhCongAm(root) << endl;
    cout << "Ty so tong duong/tong am: " << TinhTySo(root) << endl;
    return 0;
}