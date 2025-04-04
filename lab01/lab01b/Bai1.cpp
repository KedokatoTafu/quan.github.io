#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void giaiPTBac2(double *pa, double *pb, double *pc) {
    double a = *pa;
    double b = *pb;
    double c = *pc;
    
    if(a == 0) {
        if(b == 0) {
            if(c == 0)
                printf("Phuong trinh co vo so nghiem\n");
            else
                printf("Phuong trinh vo nghiem\n");
        }
        else {
            double x = -c / b;
            printf("Phuong trinh co 1 nghiem\n");
            printf("%.2f\n", x);
        }
    }
    else {
        double delta = b * b - 4 * a * c;
        if(delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Phuong trinh co 2 nghiem\n");
            // In ra theo thứ tự tăng dần
            if(x1 < x2)
                printf("%.2f %.2f\n", x1, x2);
            else
                printf("%.2f %.2f\n", x2, x1);
        }
        else if(delta == 0) {
            double x = -b / (2 * a);
            printf("Phuong trinh co 1 nghiem\n");
            printf("%.2f\n", x);
        }
        else {
            printf("Phuong trinh vo nghiem\n");
        }
    }
}

int main() {
    double a, b, c;
    printf("Moi nhap du lieu: ");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    giaiPTBac2(&a, &b, &c);

    return 0;
}