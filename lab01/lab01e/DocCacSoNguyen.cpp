#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define FI "DaySoNguyen.inp" 

void DocCacSoNguyen(int a[], int *n)
{
    FILE *fi;
    fi = fopen(FI, "rt");
    if(fi == NULL)
    {
        printf("Khong the doc file %s\n", FI);
        exit(1);
    }
    fscanf(fi, "%d", n);
    for(int i = 0; i < *n; i++)
    {
        fscanf(fi, "%d", &a[i]);
    }
    fclose(fi);
}

int main()
{
    int a[MAX];
    int n;
    
    DocCacSoNguyen(a, &n);
    
    printf("So luong so nguyen: %d\n", n);
    printf("Day so nguyen doc duoc:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    system("PAUSE");
    return 0;
}