#include <stdio.h>
#include <math.h>

int findMax ( int a, int b, int c);
int checkYear ( int year);

#include <stdio.h>
#include <math.h>

int findMax(int a, int b, int c);
int checkYear(int year);
void swap(int *a, int *b);
void checkTriangle(float a, float b, float c);

int main() {
    int chon;

    do {
        printf("\n+------------------------------------------+\n");
        printf("|          MENU CHUONG TRINH LAB 5         |\n");
        printf("+------------------------------------------+\n");
        printf("| 1. Tim gia tri lon nhat trong 3 so        |\n");
        printf("| 2. Kiem tra nam nhuan                     |\n");
        printf("| 3. Hoan vi 2 so (Su dung Con tro)         |\n");
        printf("| 4. Kiem tra & Phan loai Tam giac          |\n");
        printf("| 5. Thoat chuong trinh                     |\n");
        printf("+------------------------------------------+\n");
        printf("Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: {
                int a, b, c;
                printf("Nhap 3 so nguyen a, b, c: ");
                scanf("%d%d%d", &a, &b, &c);

                printf("Gia tri lon nhat trong 3 so la: %d\n",
                       findMax(a, b, c));
                break;
            }

            case 2: {
                int year;
                printf("Nhap nam: ");
                scanf("%d", &year);

                if (checkYear(year))
                    printf("Nam %d la nam nhuan.\n", year);
                else
                    printf("Nam %d khong phai la nam nhuan.\n", year);
                break;
            }

            case 3: {
                int a, b;
                printf("Nhap a, b: ");
                scanf("%d%d", &a, &b);

                printf("Truoc khi hoan vi: a = %d, b = %d\n", a, b);
                swap(&a, &b);
                printf("Sau khi hoan vi: a = %d, b = %d\n", a, b);
                break;
            }

            case 4: {
                float a, b, c;
                printf("Nhap 3 canh tam giac: ");
                scanf("%f%f%f", &a, &b, &c);

                checkTriangle(a, b, c);
                break;
            }

            case 5:
                printf("Da thoat chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon 1-5.\n");
        }

    } while (chon != 5);

    return 0;
}

int findMax(int a, int b, int c) {
    int max = a;

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    return max;
}

int checkYear(int year) {
    if (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    }

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void checkTriangle(float a, float b, float c) {
    if (a <= 0 || b <= 0 || c <= 0 ||
        a + b <= c || a + c <= b || b + c <= a) {
        printf("Day khong phai la 3 canh cua mot tam giac.\n");
        return;
    }

    int deu = (fabsf(a - b) < 0.01f &&
               fabsf(b - c) < 0.01f);

    int can = (fabsf(a - b) < 0.01f ||
               fabsf(a - c) < 0.01f ||
               fabsf(b - c) < 0.01f);

    int vuong =
        (fabsf(a*a + b*b - c*c) < 0.01f ||
         fabsf(a*a + c*c - b*b) < 0.01f ||
         fabsf(b*b + c*c - a*a) < 0.01f);

    if (deu) {
        printf("Day la tam giac deu.\n");
    } else if (vuong && can) {
        printf("Day la tam giac vuong can.\n");
    } else if (vuong) {
        printf("Day la tam giac vuong.\n");
    } else if (can) {
        printf("Day la tam giac can.\n");
    } else {
        printf("Day la tam giac thuong.\n");
    }
}

