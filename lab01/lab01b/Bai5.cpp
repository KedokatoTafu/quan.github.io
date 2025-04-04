#include <stdio.h>
#include <stdlib.h>
#define MAX 100 

void NhapMang(int **a, int *n)
{
    printf("Moi ban nhap so luong phan tu: ");
    scanf("%d", n);
    while((*n) <= 0 || (*n) > MAX)
    {
        printf("Nhap sai! Nhap lai: ");
        scanf("%d", n);
    }
    (*a) = new int[(*n)];
    for(int i = 0; i < (*n); i++)
    {
        printf("Phan tu %d: ", i);
        scanf("%d", (*a) + i);
    }
}

void XuatMang(int *a, int n)
{
    printf("Day so co %d phan tu: ", n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

int DemChan(int *a, int n)
{
    int dem = 0;
    for(int i = 0; i < n; i++)
    {
        if(*(a + i) % 2 == 0)
            dem++;
    }
    return dem;
}

int DemLe(int *a, int n)
{
    int dem = 0;
    for(int i = 0; i < n; i++)
    {
        if(*(a + i) % 2 != 0)
            dem++;
    }
    return dem;
}

void TachChan(int *a, int n, int **b, int *m)
{
    *m = DemChan(a, n);
    *b = new int[*m];
    int cs = 0;
    for(int i = 0; i < n; i++)
    {
        if(*(a + i) % 2 == 0)
        {
            *(*b + cs) = *(a + i);
            cs++;
        }
    }
}

void TachLe(int *a, int n, int **c, int *p)
{
    *p = DemLe(a, n);
    *c = new int[*p]; 
    int cs = 0;
    for(int i = 0; i < n; i++)
    {
        if(*(a + i) % 2 != 0)
        {
            *(*c + cs) = *(a + i);
            cs++;
        }
    }
}

int main()
{
    int *a = NULL;  
    int n;         
    int *b = NULL;  
    int *c = NULL;  
    int nChan, nLe;

    printf("+ Day so a\n");
    NhapMang(&a, &n);

    TachChan(a, n, &b, &nChan);
    TachLe(a, n, &c, &nLe);

    printf("+ Day so b chua so chan\n");
    printf("Day so co %d phan tu: ", nChan);
    XuatMang(b, nChan);

    printf("+ Day so c\n");
    printf("Day so co %d phan tu: ", nLe);
    XuatMang(c, nLe);

    delete [] a;
    delete [] b;
    delete [] c;

    system("PAUSE");
    return 0;
}