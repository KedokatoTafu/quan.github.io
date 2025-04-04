#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20 

struct LoaiHoa {
    char Ten[51];     
    int SoLuong;       
    char DVT[21];     
    double DonGia;   
};

struct DanhSachLoaiHoa {
    struct LoaiHoa aLoaiHoa[MAX];
    int SoLuong;                
};

void NhapDanhSach(struct DanhSachLoaiHoa *ds)
{
    int i;
    printf("Nhap so luong loai hoa: ");
    scanf("%d", &(*ds).SoLuong);
    while((*ds).SoLuong <= 0 || (*ds).SoLuong > MAX)
    {
        printf("Nhap sai! Nhap lai: ");
        scanf("%d", &(*ds).SoLuong);
    }
    for(i = 0; i < (*ds).SoLuong; i++)
    {
        printf("\nNhap thong tin loai hoa %d:\n", i);
        printf("+ Ten loai: ");
        fflush(stdin);
        gets((*ds).aLoaiHoa[i].Ten);
        printf("+ So luong: ");
        scanf("%d", &(*ds).aLoaiHoa[i].SoLuong);
        while((*ds).aLoaiHoa[i].SoLuong < 0)
        {
            printf("+ So luong phai >= 0, nhap lai: ");
            scanf("%d", &(*ds).aLoaiHoa[i].SoLuong);
        }
        printf("+ Don vi tinh: ");
        fflush(stdin);
        gets((*ds).aLoaiHoa[i].DVT);
        printf("+ Don gia: ");
        scanf("%lf", &(*ds).aLoaiHoa[i].DonGia);
    }
}
 
void XuatDanhSach(struct DanhSachLoaiHoa ds)
{
    int i;
    printf("\nDanh sach loai hoa:\n");
    printf("STT\tTen loai\tSo luong\tDVT\tDon gia\n");
    for(i = 0; i < ds.SoLuong; i++)
    {
        printf("%d\t%s\t\t%d\t\t%s\t%.2lf\n", i+1,
               ds.aLoaiHoa[i].Ten,
               ds.aLoaiHoa[i].SoLuong,
               ds.aLoaiHoa[i].DVT,
               ds.aLoaiHoa[i].DonGia);
    }
}
 
int TimLoaiHoa(struct DanhSachLoaiHoa ds, char *tenloai)
{
    int i;
    for(i = 0; i < ds.SoLuong; i++)
    {
        if(strcmp(ds.aLoaiHoa[i].Ten, tenloai) == 0)
            return i;
    }
    return -1;
}

void XuLyBanHoa(struct DanhSachLoaiHoa *ds, char *tenloai, int soluong)
{
    int pos = TimLoaiHoa(*ds, tenloai);
    if(pos == -1)
    {
        printf("Loai hoa '%s' khong ton tai.\n", tenloai);
    }
    else
    {
        if((*ds).aLoaiHoa[pos].SoLuong < soluong)
        {
            printf("Khong du so luong ban. So luong hien tai: %d.\n", (*ds).aLoaiHoa[pos].SoLuong);
        }
        else
        {
            double tongTien = soluong * (*ds).aLoaiHoa[pos].DonGia;
            printf("Loai hoa '%s' co du so luong. Tong tien: %.2lf.\n", tenloai, tongTien);
            (*ds).aLoaiHoa[pos].SoLuong -= soluong;
        }
    }
}
 
int main()
{
    struct DanhSachLoaiHoa ds;
    char tenloai[51];
    int soluong;
    
    NhapDanhSach(&ds);
    
    XuatDanhSach(ds);
    
    printf("\nNhap ten loai hoa can ban: ");
    fflush(stdin);
    gets(tenloai);
    printf("Nhap so luong can ban: ");
    scanf("%d", &soluong);
    
    XuLyBanHoa(&ds, tenloai, soluong);
    
    return 0;
}