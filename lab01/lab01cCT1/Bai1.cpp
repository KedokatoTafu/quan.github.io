#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 

struct NhanVien {
    char MaSo[11];    
    char Ho[11];     
    char Ten[51];  
    int Phai;       
    int ThamNien;    
};

struct PhongBan {
    NhanVien aNhanVien[MAX]; 
    int SoLuong;            
};

void NhapPhongBan(struct PhongBan &pb)
{
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &pb.SoLuong);
    while(pb.SoLuong <= 0 || pb.SoLuong > MAX)
    {
        printf("Nhap sai! Nhap lai: ");
        scanf("%d", &pb.SoLuong);
    }
    for(int i = 0; i < pb.SoLuong; i++)
    {
        printf("Nhap thong tin nhan vien %d:\n", i);
        printf("+ Ma so: ");
        fflush(stdin);  
        gets(pb.aNhanVien[i].MaSo);
        printf("+ Ho: ");
        fflush(stdin);
        gets(pb.aNhanVien[i].Ho);
        printf("+ Ten: ");
        fflush(stdin);
        gets(pb.aNhanVien[i].Ten);
        printf("+ Phai (0-Nu, 1-Nam): ");
        scanf("%d", &pb.aNhanVien[i].Phai);
        while(pb.aNhanVien[i].Phai != 0 && pb.aNhanVien[i].Phai != 1)
        {
            printf("+ Nhap sai! Nhap lai (0-Nu, 1-Nam): ");
            scanf("%d", &pb.aNhanVien[i].Phai);
        }
        printf("+ Tham nien: ");
        scanf("%d", &pb.aNhanVien[i].ThamNien);
        while(pb.aNhanVien[i].ThamNien < 0)
        {
            printf("+ Nhap sai! Tham nien phai >= 0, nhap lai: ");
            scanf("%d", &pb.aNhanVien[i].ThamNien);
        }
    }
}

void XuatPhongBan(struct PhongBan pb)
{
    printf("Phong ban co %d nhan vien:\n", pb.SoLuong);
    printf("STT\tMa so\tHo\tTen\t\tPhai\tTham nien\n");
    for(int i = 0; i < pb.SoLuong; i++)
    {
        printf("%d\t%s\t%s\t%s\t", i+1,
               pb.aNhanVien[i].MaSo,
               pb.aNhanVien[i].Ho,
               pb.aNhanVien[i].Ten);
        if(pb.aNhanVien[i].Phai == 1)
            printf("Nam\t");
        else
            printf("Nu\t");
        printf("%d\n", pb.aNhanVien[i].ThamNien);
    }
}

void DemSiSo(struct PhongBan pb, int &sonam, int &sonu)
{
    sonam = 0;
    sonu = 0;
    for(int i = 0; i < pb.SoLuong; i++)
    {
        if(pb.aNhanVien[i].Phai == 1)
            sonam++;
        else
            sonu++;
    }
}

void SapXepTangTheoThamNien(struct PhongBan &pb)
{
    for(int i = 0; i < pb.SoLuong - 1; i++)
        for(int j = i + 1; j < pb.SoLuong; j++)
        {
            if(pb.aNhanVien[i].ThamNien > pb.aNhanVien[j].ThamNien)
            {
                struct NhanVien tmp = pb.aNhanVien[i];
                pb.aNhanVien[i] = pb.aNhanVien[j];
                pb.aNhanVien[j] = tmp;
            }
        }
}

int main()
{
    struct PhongBan pb;
    int sonam, sonu;
    
    NhapPhongBan(pb);
    
    XuatPhongBan(pb);
    
    DemSiSo(pb, sonam, sonu);
    printf("\n+ Dem si so nhan vien trong phong ban:\n");
    printf("Phong ban co %d nhan vien, trong do %d nam va %d nu.\n", pb.SoLuong, sonam, sonu);
    
    SapXepTangTheoThamNien(pb);
    printf("\n+ Danh sach nhan vien sau khi sap xep theo tham nien tang dan:\n");
    XuatPhongBan(pb);
    
    return 0;
}