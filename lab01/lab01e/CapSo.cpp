#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10000
#define FIN "CapSo.INP"
#define FOUT "CapSo.OUT"

void DocDuLieu(int a[], int *n, int *k)
{
    FILE *fin;
    fin = fopen(FIN, "rt");
    if(fin == NULL)
    {
        printf("Khong the mo file %s\n", FIN);
        exit(1);
    }
    fscanf(fin, "%d %d", n, k);
    for(int i = 0; i < *n; i++)
    {
        fscanf(fin, "%d", &a[i]);
    }
    fclose(fin);
}

void TimCapSo(int a[], int n, int k, int result[][2], int *count)
{
    *count = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] + a[j] == k)
            {
                result[*count][0] = a[i];
                result[*count][1] = a[j];
                (*count)++;
            }
        }
    }
}

void GhiKetQua(int result[][2], int count)
{
    FILE *fout;
    fout = fopen(FOUT, "wt");
    if(fout == NULL)
    {
        printf("Khong the tao file %s\n", FOUT);
        exit(1);
    }
    if(count == 0)
        fprintf(fout, "0\n");
    else
    {
        for(int i = 0; i < count; i++)
        {
            fprintf(fout, "%d %d\n", result[i][0], result[i][1]);
        }
    }
    fclose(fout);
}

void ProcessCapSo(void)
{
    int a[MAX_N];
    int n, k;
    DocDuLieu(a, &n, &k);
    
    int result[10000][2];
    int count;
    
    TimCapSo(a, n, k, result, &count);
    
    GhiKetQua(result, count);
}

int main(void)
{
    ProcessCapSo();
    return 0;
}