#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 100
#define MAX_COL 100
#define FI "MangSo.inp"

void DocMang2CSoNguyen(int a[][MAX_COL], int *n, int *m)
{
    FILE *fi;
    fi = fopen(FI, "rt");
    if (fi == NULL)
    {
        printf("Khong the mo file %s\n", FI);
        exit(1);
    }
    fscanf(fi, "%d %d", n, m);
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            fscanf(fi, "%d", &a[i][j]);
        }
    }
    fclose(fi);
}

int main()
{
    int a[MAX_ROW][MAX_COL];
    int n, m;
    
    DocMang2CSoNguyen(a, &n, &m);
    
    printf("Mang 2 chieu doc duoc tu file \"%s\":\n", FI);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    system("PAUSE");
    return 0;
}