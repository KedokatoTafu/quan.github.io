#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000  

void XoaKyTuTaiViTri(char s[], int k)
{
    int len = strlen(s);
    if(k < 0 || k >= len)
    {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for(int i = k; i < len; i++)
    {
        s[i] = s[i+1];
    }
}

int main()
{
    char s[MAX+1] = {0};      
    char original[MAX+1] = {0}; 
    int k;
    
    printf("Moi ban nhap chuoi s: ");
    fflush(stdin);
    gets(s);
    
    strcpy(original, s);
    
    printf("Moi ban nhap vi tri can xoa: ");
    scanf("%d", &k);
    
    XoaKyTuTaiViTri(s, k);
    
    printf("Chuoi \"%s\" sau khi xoa ky tu tai vi tri %d: %s\n", original, k, s);
    
    system("PAUSE");
    return 0;
}