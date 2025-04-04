#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100

typedef struct MatHangTag {
    char MSMH[11];   
    char TenMH[51]; 
    int SoLuong;     
    int DonGia;    
} MatHang;

void Nhap1MatHang(MatHang &mh)
{
    printf("Ma so mat hang: ");
    gets(mh.MSMH);
    printf("Ten mat hang: ");
    gets(mh.TenMH);
    printf("So luong: ");
    scanf("%d", &mh.SoLuong);
    printf("Don gia: ");
    scanf("%d", &mh.DonGia);
    flushall();
}

void Xuat1MatHang(MatHang mh)
{
    printf("Ma so: %s\n", mh.MSMH);
    printf("Ten mat hang: %s\n", mh.TenMH);
    printf("So luong: %d\n", mh.SoLuong);
    printf("Don gia: %d\n", mh.DonGia);
}

void NhapDanhSach(MatHang a[], int &n)
{
    int i;
    printf("Nhap so luong mat hang: ");
    scanf("%d", &n);
    flushall();
    for(i = 0; i < n; i++)
    {
        printf("\nNhap mat hang thu %d:\n", i+1);
        Nhap1MatHang(a[i]);
    }
}

int TimMatHangTheoTen(MatHang a[], int n, char ten[], MatHang &kq)
{
    int timThay = 0;
    int i = 0;
    while(i < n && timThay == 0)
    {
        if(strcmp(ten, a[i].TenMH) == 0)
        {
            kq = a[i];
            timThay = 1;
        }
        i++;
    }
    if(timThay == 1)
        return i-1;
    else
        return -1;
}

int TinhTongSoLuong(MatHang a[], int n)
{
    int tong = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        tong += a[i].SoLuong;
    }
    return tong;
}

int main()
{
    MatHang a[MAX];
    int n;
    
    NhapDanhSach(a, n);
    
    char ten[51];
    printf("\nNhap ten mat hang can tim: ");
    gets(ten);
    MatHang kq;
    int pos = TimMatHangTheoTen(a, n, ten, kq);
    if(pos != -1)
    {
        printf("\nThong tin mat hang tim duoc:\n");
        Xuat1MatHang(kq);
    }
    else
    {
        printf("\nKhong co mat hang dang tim\n");
    }
    
    int tongSoLuong = TinhTongSoLuong(a, n);
    printf("\nTong so luong cac mat hang: %d\n", tongSoLuong);
    
    return 0;
}