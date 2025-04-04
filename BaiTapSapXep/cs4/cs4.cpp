#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 30000

void nhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % MAX;
    }
}

void Swap(int& x, int& y)
{
    // Hoán đổi x với y
    int temp = x;
    x = y;
    y = temp;
}

void Insertion(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = a[i];
        bool cont = true;
        while ((j >= 0) && cont)
            if (a[j] > x)
            {
                a[j+1] = a[j];
                j--;
            }
            else
                cont = false;
        a[j+1] = x;
    }
}

void Selection(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        // Tìm a[kmin] nhỏ nhất trong dãy [i, n-1]
        int minval = a[i];
        int kmin = i;
        for (int j = i+1; j < n; j++)
            if (minval > a[j])
            {
                minval = a[j];
                kmin = j;
            }
        // Hoán đổi a[i] với a[kmin]
        Swap(a[i], a[kmin]);
    }
}

void Sift(int a[], int p, int q)
{
    int x = a[p];
    int i = p;
    int j = 2 * i + 1;
    bool cont = true;
    while((j <= q) and cont)
    {
        if(j < q)
            if(a[j] < a[j+1])
                j = j + 1;
        if(x < a[j])
        {
            a[i] = a[j];
            i = j;
            j = j * 2 + 1;
        }
        else
            cont = false;
    }
    a[i] = x;
}

void HeapSort(int a[], int n)
{
    // Giai đoạn 1: tạo heap ban đầu
    int k = n / 2 - 1;
    for (int i = k; i >= 0; i--)
        Sift(a, i, n-1);
    // Giai đoạn 2: tạo mảng có thứ tự
    for (int i = n-1; i > 0; i--)
    {
        Swap(a[0], a[i]);
        Sift(a, 0, i-1);
    }
}

void BubbleNoFlag(int a[], int n)
// Bubble Sort không cờ
{
    for (int i = n-1; i >= 1; i--)
        for (int j = 0; j <= i - 1; j++)
            if (a[j] > a[j+1])
                Swap(a[j], a[j+1]);
}

void Partition(int a[], int p, int q)
{
    int x = a[(p + q) / 2]; 
    int i = p;
    int j = q;
    do 
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j)
        {
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i > j);
    if (p < j)
        Partition(a, p, j);
    if (i < q)
        Partition(a, i, q);
}

void QuickSort(int a[], int n)
{
    // Phân hoạch dãy a0 .. an-1
    Partition(a, 0, n-1);
}

void Merge(int a[], int temp[], int p, int t, int q)
// Trộn dãy a[p]..a[t-1] với dãy a[t]..a[q] đưa vào mảng temp
{
    int i = p;
    int k = t - 1;
    int n = 0;
    while ((p <= k) && (t <= q))
    {
        if (a[p] < a[t])
        {
            temp[n] = a[p];
            p++;
        }
        else
        {
            temp[n] = a[t];
            t++;
        }
        n++;
    }
    while (p <= k)
    {
        temp[n] = a[p];
        n++;
        p++;
    }
    while (t <= q)
    {
        temp[n] = a[t];
        n++;
        t++;
    }
    for (int j = 0; j < n; j++)
        a[i+j] = temp[j];
}

void RecMergeSort(int a[], int temp[], int p, int q)
// Sắp thứ tự trộn dãy a[p]..a[q]
{
    if (p < q)
    {
        int k = (p + q) / 2;
        RecMergeSort(a, temp, p, k);
        RecMergeSort(a, temp, k+1, q);
        Merge(a, temp, p, k+1, q);
    }
}

void MergeSort(int a[], int n)
{
    int temp[n];
    RecMergeSort(a, temp, 0, n-1);
}

void taoFile(int a[], int &n)
{
	FILE *f;
	f=fopen("data.inp","wt");
	fprintf(f, "%d\n", MAX);
    for (int i = 0; i < MAX; i++) {
        fprintf(f, "%d\n", rand() % MAX);
    }
	fclose(f);
}

void docFile(int a[], int &n)
{
	FILE *f;
	f=fopen("data.inp","rt");
	fscanf(f,"%d",&n);
	for (int i=0;i<n;i++)
	fscanf(f,"%d",&a[i]);
	fclose(f);
}

void xuatFile(int a[], int n, double time)
{
	FILE *f;
	f=fopen("merge.out","wt");
	fprintf(f, "Ket qua:\n");
    fprintf(f, "Thoi gian: %.3f ms\n", time);
    fprintf(f, "Mang da sap xep:\n");
    for (int i = 0; i < n; i++)
        fprintf(f, "%d\n", a[i]);
    fclose(f);
}

int main() {
    int n, a[MAX], temp[MAX];
    //taoFile(a,n);
    docFile(a,n);
    long t_start=clock();
	MergeSort(a,n);
	long t_end=clock();
    double time = (double)(t_end - t_start) * 1000 / CLOCKS_PER_SEC;
    xuatFile(a, n, time);    
    return 0;
}