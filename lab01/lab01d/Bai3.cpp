#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000 

void ChenKyTuTaiViTri(char s[], int k, char c)
{
    int len = strlen(s);
    if(k <= 0 || k >= len) 
    {
        printf("Vi tri can chen khong hop le.\n");
        return;
    }
    for(int i = len; i >= k; i--)
    {
        s[i+1] = s[i];
    }
    s[k] = c;
}

int main()
{
    char s[MAX+1] = {0};  
    int k;
    char ch;
    char original[MAX+1] = {0};
    
    printf("Moi ban nhap chuoi s: ");
    fflush(stdin);  
    gets(s);
    
    strcpy(original, s);
    
    printf("Moi ban nhap vi tri can chen: ");
    scanf("%d", &k);
    
    fflush(stdin);
    printf("Moi ban nhap ky tu chen: ");
    scanf("%c", &ch);
    
    ChenKyTuTaiViTri(s, k, ch);
    
    printf("Chuoi \"%s\" sau khi them ky tu \"%c\" vao vi tri %d: %s\n", 
           original, ch, k, s);
    
    system("PAUSE");
    return 0;
}