#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000  

void SapXepChuoi(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (s[i] > s[j])
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main()
{
    char s[MAX+1] = {0};
    printf("Moi ban nhap chuoi s: ");
    fflush(stdin); 
    gets(s);
    
    SapXepChuoi(s);
    
    printf("Chuoi \"%s\" sau khi sap xep: %s\n", s, s);
    
    system("PAUSE");
    return 0;
}