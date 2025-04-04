#include <iostream>
#include <math.h>

void giaiPTBac2(double a, double b, double c, double results[], int &count) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Phuong trinh co vo so nghiem\n");
            }
            
            else {
                printf("Phuong trinh vo nghiem\n");
            }
            return;
        }
        
        else {
            double x = -c / b;
            results[count++] = x;
        }
        return;
    }

    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        return;
    }
    
    else if (delta == 0) {
        double x = -b / (2 * a);
        results[count++] = x;
    }
    
    else {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        results[count++] = x1;
        results[count++] = x2;
    }
}

void sapXepTangDan(double arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void giaiPTTrungPhuong(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Phuong trinh co vo so nghiem\n");
            }
            
            else {
                printf("Phuong trinh vo nghiem\n");
            }
        }
        
        else {
            double x = -c / b;
            double results[2];
            int count = 0;
            results[count++] = x;

            double finalResults[4];
            int finalCount = 0;

            for (int i = 0; i < count; ++i) {
                if (results[i] >= 0) {
                    finalResults[finalCount++] = -sqrt(results[i]);
                    finalResults[finalCount++] = sqrt(results[i]);
                }
            }

            if (finalCount == 0) {
                printf("Phuong trinh vo nghiem\n");
            }
            
            else {
                sapXepTangDan(finalResults, finalCount);
                printf("Phuong trinh co %d nghiem\n", finalCount);
                for (int i = 0; i < finalCount; ++i) {
                    printf("%.2f ", finalResults[i]);
                }
                printf("\n");
            }
        }
        return;
    }

    double results[4];
    int count = 0;
    giaiPTBac2(a, b, c, results, count);

    if (count == 0) {
        printf("Phuong trinh vo nghiem\n");
    }
    
    else {
        double finalResults[8];
        int finalCount = 0;

        for (int i = 0; i < count; ++i) {
            if (results[i] >= 0) {
                finalResults[finalCount++] = -sqrt(results[i]);
                finalResults[finalCount++] = sqrt(results[i]);
            }
        }

        if (finalCount == 0) {
            printf("Phuong trinh vo nghiem\n");
        } else {
            sapXepTangDan(finalResults, finalCount);
            printf("Phuong trinh co %d nghiem\n", finalCount);
            for (int i = 0; i < finalCount; ++i) {
                printf("%.2f ", finalResults[i]);
            }
            printf("\n");
        }
    }
}

int main() {
    double a, b, c;
    printf("Moi nhap du lieu: ");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    giaiPTTrungPhuong(a, b, c);

    return 0;
}