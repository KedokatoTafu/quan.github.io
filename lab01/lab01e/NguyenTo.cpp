#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define FIN "NT.INP"
#define FOUT "NT.OUT"

int LaNguyenTo(int x)
{
    if(x < 2)
        return 0;
    int i;
    for(i = 2; i <= (int)sqrt(x); i++)
    {
        if(x % i == 0)
            return 0;
    }
    return 1;
}

void SapXepTangDan(int a[], int m)
{
    int i, j;
    for(i = 0; i < m - 1; i++)
    {
        for(j = i + 1; j < m; j++)
        {
            if(a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void DocMangSoNguyen(int a[], int *n)
{
    FILE *fin = fopen(FIN, "rt");
    if(fin == NULL)
    {
        printf("Khong the mo file %s\n", FIN);
        exit(1);
    }
    fscanf(fin, "%d", n);
    for(int i = 0; i < *n; i++)
    {
        fscanf(fin, "%d", &a[i]);
    }
    fclose(fin);
}

void GhiKQ(int a[], int m)
{
    FILE *fout = fopen(FOUT, "wt");
    if(fout == NULL)
    {
        printf("Khong the tao file %s\n", FOUT);
        exit(1);
    }
    fprintf(fout, "%d\n", m);
    if(m > 0)
    {
        for(int i = 0; i < m; i++)
        {
            fprintf(fout, "%d ", a[i]);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);
}

int main()
{
    int a[10000];
    int n;
    
    DocMangSoNguyen(a, &n);
    
    int primeArray[10000];
    int m = 0;  
    
    for(int i = 0; i < n; i++)
    {
        if(LaNguyenTo(a[i]))
        {
            primeArray[m] = a[i];
            m++;
        }
    }
    
    if(m > 0)
        SapXepTangDan(primeArray, m);
    
    GhiKQ(primeArray, m);
    
    return 0;
}