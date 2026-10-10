#include <stdio.h>
int phanPhoiTien(int tien, int *to500,
                 int *to200, int *to100, int *to50) {
    if (tien <= 0 || tien % 50000 != 0) {
        return 0;
    }
    *to500 = tien / 500000;
    tien %= 500000;
    *to200 = tien / 200000;
    tien %= 200000;
    *to100 = tien / 100000;
    tien %= 100000;
    *to50 = tien / 50000;
    return *to500 + *to200 + *to100 + *to50;
}
int main(void) {
    int tien;
    int to500 = 0, to200 = 0, to100 = 0, to50 = 0;
    int tongSoTo;
    printf("Nhap so tien can rut (boi so 50000): ");
    scanf("%d", &tien);
    tongSoTo = phanPhoiTien(tien, &to500, &to200, &to100, &to50);
    if (tongSoTo == 0) {
        printf("So tien khong hop le!\n");
        return 0;
    }
    printf("So to 500000: %d\n", to500);
    printf("So to 200000: %d\n", to200);
    printf("So to 100000: %d\n", to100);
    printf("So to 50000: %d\n", to50);
    printf("Tong so to: %d\n", tongSoTo);
    return 0;
}