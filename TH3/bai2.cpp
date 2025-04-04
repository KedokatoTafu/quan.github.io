#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sinhvien {
    char hoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
    struct sinhvien* next;
} SinhVien;

typedef SinhVien* ListSV;

SinhVien* CreateSinhVien(const char* hoTen, const char* diaChi, const char* lop, int khoa) {
    SinhVien* p = (SinhVien*)malloc(sizeof(SinhVien));
    strcpy(p->hoTen, hoTen);
    strcpy(p->diaChi, diaChi);
    strcpy(p->lop, lop);
    p->khoa = khoa;
    p->next = NULL;
    return p;
}

void NhapSinhVien(SinhVien* sv) {
    printf("Nhap ho ten: ");
    scanf(" %[^\n]s", sv->hoTen);
    printf("Nhap dia chi: ");
    scanf(" %[^\n]s", sv->diaChi);
    printf("Nhap lop: ");
    scanf(" %[^\n]s", sv->lop);
    printf("Nhap khoa: ");
    scanf("%d", &sv->khoa);
}

void XuatSinhVien(SinhVien* sv) {
    printf("Ho ten: %s, Dia chi: %s, Lop: %s, Khoa: %d\n", sv->hoTen, sv->diaChi, sv->lop, sv->khoa);
}

int SoSanhHoTen(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->hoTen, sv2->hoTen);
}

int SoSanhDiaChi(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->diaChi, sv2->diaChi);
}

int SoSanhLop(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->lop, sv2->lop);
}

int SoSanhKhoa(SinhVien* sv1, SinhVien* sv2) {
    return sv1->khoa - sv2->khoa;
}

void Init(ListSV &pHead) {
    pHead = NULL;
}

bool IsEmpty(ListSV pHead) {
    return (pHead == NULL);
}

void InsertFirst(ListSV &pHead, SinhVien* sv) {
    sv->next = pHead;
    pHead = sv;
}

void ShowList(ListSV pHead) {
    ListSV p = pHead;
    if (p == NULL)
        printf("\nDanh sach rong\n");
    else
        while (p != NULL) {
            XuatSinhVien(p);
            p = p->next;
        }
}

void RemoveSVByName(ListSV &pHead, const char* hoTen) {
    ListSV tp = NULL, p = pHead;
    bool found = false;
    while (p != NULL && !found) {
        if (strcmp(p->hoTen, hoTen) != 0) {
            tp = p;
            p = p->next;
        } else
            found = true;
    }
    if (found) {
        if (p == pHead)
            pHead = p->next;
        else
            tp->next = p->next;
        delete(p);
    }
}

void RemoveSVByAddress(ListSV &pHead, const char* diaChi) {
    ListSV tp = NULL, p = pHead;
    bool found = false;
    while (p != NULL && !found) {
        if (strcmp(p->diaChi, diaChi) != 0) {
            tp = p;
            p = p->next;
        } else
            found = true;
    }
    if (found) {
        if (p == pHead)
            pHead = p->next;
        else
            tp->next = p->next;
        delete(p);
    }
}

void ClearList(ListSV &pHead) {
    ListSV p;
    while (pHead != NULL) {
        p = pHead;
        pHead = p->next;
        delete(p);
    }
}

void AppendList(ListSV &pHead1, ListSV pHead2) {
    ListSV p = pHead2;
    while (p != NULL) {
        SinhVien* sv = CreateSinhVien(p->hoTen, p->diaChi, p->lop, p->khoa);
        InsertFirst(pHead1, sv);
        p = p->next;
    }
}

void SelectionSort(ListSV &pHead) {
    ListSV p, q, pmin;
    for (p = pHead; p != NULL && p->next != NULL; p = p->next) {
        pmin = p;
        for (q = p->next; q != NULL; q = q->next) {
            if (strcmp(q->hoTen, pmin->hoTen) < 0) { // trả về giá trị âm nếu q->hoTen nhỏ hơn pmin->hoTen
                pmin = q;
            }
        }
        if (pmin != p) {
            SinhVien temp = *p;
            *p = *pmin;
            *pmin = temp;
            pmin->next = p->next;
            p->next = temp.next;
        }
    }
}

int main() {
    ListSV pHead1;
    Init(pHead1);

    printf("Nhap thong tin 10 sinh vien:\n");
    for (int i = 0; i < 10; i++) {
        SinhVien* sv = (SinhVien*)malloc(sizeof(SinhVien));
        printf("Sinh vien %d:\n", i + 1);
        NhapSinhVien(sv);
        InsertFirst(pHead1, sv);
    }

    // InsertFirst(pHead1, CreateSinhVien("Nguyen Van A", "12 Tran Phu", "CNTT01", 2020));
    // InsertFirst(pHead1, CreateSinhVien("Tran Thi B", "45 Le Loi", "CNTT02", 2021));
    // InsertFirst(pHead1, CreateSinhVien("Le Van C", "78 Nguyen Hue", "CNTT03", 2022));
    // InsertFirst(pHead1, CreateSinhVien("Pham Thi D", "23 Hong Bang", "CNTT01", 2020));
    // InsertFirst(pHead1, CreateSinhVien("Nguyen Van Teo", "56 Nguyen Trai", "CNTT02", 2021));
    // InsertFirst(pHead1, CreateSinhVien("Hoang Van E", "89 Le Thanh Ton", "CNTT03", 2022));
    // InsertFirst(pHead1, CreateSinhVien("Bui Thi F", "Nguyen Van Cu", "CNTT01", 2020));
    // InsertFirst(pHead1, CreateSinhVien("Vu Van G", "34 Tran Hung Dao", "CNTT02", 2021));
    // InsertFirst(pHead1, CreateSinhVien("Do Thi H", "67 Pham Ngu Lao", "CNTT03", 2022));
    // InsertFirst(pHead1, CreateSinhVien("Ngo Van I", "90 Ly Thuong Kiet", "CNTT01", 2020));

    printf("\nDanh sach sinh vien ban dau:\n");
    ShowList(pHead1);

    RemoveSVByName(pHead1, "Nguyen Van Teo");

    RemoveSVByAddress(pHead1, "Nguyen Van Cu");

    SinhVien* newSV = CreateSinhVien("Tran Thi Mo", "25 Hong Bang", "TT0901", 2009);
    InsertFirst(pHead1, newSV);

    printf("\nDanh sach sinh vien cuoi cung:\n");
    ShowList(pHead1);

    ClearList(pHead1);

    return 0;
}