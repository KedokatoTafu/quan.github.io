#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100

typedef struct DienThoaiTag {
    char maDT[11];     
    char nhanHieu[21]; 
    int gia;        
} DienThoai;

void Nhap1DienThoai(DienThoai &dt)
{
    printf("Ma dien thoai: ");
    gets(dt.maDT);
    printf("Nhan hieu: ");
    gets(dt.nhanHieu);
    printf("Gia: ");
    scanf("%d", &dt.gia);
    flushall();
}

void Xuat1DienThoai(DienThoai dt)
{
    printf("Ma dien thoai: %s\n", dt.maDT);
    printf("Nhan hieu: %s\n", dt.nhanHieu);
    printf("Gia: %d\n", dt.gia);
}

void NhapMangDienThoai(DienThoai a[], int &n)
{
    int i;
    printf("Nhap so luong dien thoai: ");
    scanf("%d", &n);
    flushall();
    for(i = 0; i < n; i++)
    {
        printf("\nNhap dien thoai thu %d:\n", i+1);
        Nhap1DienThoai(a[i]);
    }
}

int TimDienThoaiTheoMa(DienThoai a[], int n, char ma[], DienThoai &kq)
{
    int timThay = 0;
    int i = 0;
    while(i < n && timThay == 0)
    {
        if(strcmp(ma, a[i].maDT) == 0)
        {
            kq = a[i];
            timThay = 1;
        }
        i++;
    }
    if(timThay == 1)
        return i-1;  // trả về vị trí
    else
        return -1;
}

int ThemDienThoai(DienThoai a[], int &n, DienThoai dt)
{
    if(n >= MAX)
    {
        printf("Danh sach da day.\n");
        return 0;
    }
    DienThoai tmp;
    if(TimDienThoaiTheoMa(a, n, dt.maDT, tmp) != -1)
    {
        printf("Dien thoai voi ma %s da ton tai.\n", dt.maDT);
        return 0;
    }
    a[n] = dt;
    n++;
    return 1;
}

int CapNhatGia(DienThoai a[], int n, char ma[], int giaMoi)
{
    int pos = TimDienThoaiTheoMa(a, n, ma, a[0]);
    if(pos == -1)
        return 0;
    a[pos].gia = giaMoi;
    return 1;
}

int XoaDienThoai(DienThoai a[], int &n, char ma[])
{
    int pos = TimDienThoaiTheoMa(a, n, ma, a[0]);
    if(pos == -1)
        return 0;
    int i;
    for(i = pos; i < n - 1; i++)
    {
        a[i] = a[i+1];
    }
    n--;
    return 1;
}

void XuatDanhSach(DienThoai a[], int n)
{
    int i;
    printf("\nDanh sach dien thoai:\n");
    for(i = 0; i < n; i++)
    {
        printf("\nDien thoai thu %d:\n", i+1);
        Xuat1DienThoai(a[i]);
    }
}

int main()
{
    DienThoai ds[MAX];
    int n = 0;
    int luaChon;
    char ma[11];
    DienThoai dt;
    int giaMoi;
    
    do {
        printf("\n======== MENU QUAN LY DIEN THOAI ========\n");
        printf("1. Nhap danh sach dien thoai\n");
        printf("2. Them dien thoai\n");
        printf("3. Tim dien thoai theo ma\n");
        printf("4. Cap nhat gia dien thoai\n");
        printf("5. Xoa dien thoai\n");
        printf("6. Xuat danh sach dien thoai\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        flushall();
        switch(luaChon)
        {
            case 1:
                NhapMangDienThoai(ds, n);
                break;
            case 2:
                printf("Nhap thong tin dien thoai can them:\n");
                Nhap1DienThoai(dt);
                if(ThemDienThoai(ds, n, dt))
                    printf("Them dien thoai thanh cong.\n");
                else
                    printf("Them dien thoai that bai (danh sach day hoac ma da ton tai).\n");
                break;
            case 3:
                printf("Nhap ma dien thoai can tim: ");
                gets(ma);
                if(TimDienThoaiTheoMa(ds, n, ma, dt) != -1)
                {
                    printf("Thong tin dien thoai tim duoc:\n");
                    Xuat1DienThoai(dt);
                }
                else
                    printf("Khong tim thay dien thoai voi ma %s.\n", ma);
                break;
            case 4:
                printf("Nhap ma dien thoai can cap nhat gia: ");
                gets(ma);
                printf("Nhap gia moi: ");
                scanf("%d", &giaMoi);
                flushall();
                if(CapNhatGia(ds, n, ma, giaMoi))
                    printf("Cap nhat gia thanh cong.\n");
                else
                    printf("Cap nhat gia that bai. Khong tim thay dien thoai voi ma %s.\n", ma);
                break;
            case 5:
                printf("Nhap ma dien thoai can xoa: ");
                gets(ma);
                if(XoaDienThoai(ds, n, ma))
                    printf("Xoa dien thoai thanh cong.\n");
                else
                    printf("Xoa that bai. Khong tim thay dien thoai voi ma %s.\n", ma);
                break;
            case 6:
                XuatDanhSach(ds, n);
                break;
            case 7:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while(luaChon != 7);
    
    return 0;
}