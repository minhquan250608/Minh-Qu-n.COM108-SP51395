#include <stdio.h>

#define PI 3.14159

int main() {
    float chieuDai, chieuRong;
    float banKinh;
    float chuViHinhChuNhat;
    float dienTichHinhChuNhat;
    float chuViHinhTron;
    float dienTichHinhTron;
    printf("Nhap chieu dai: ");
    scanf("%f", &chieuDai);
    printf("Nhap chieu rong: ");
    scanf("%f", &chieuRong);
    chuViHinhChuNhat = 2 * (chieuDai + chieuRong);
    dienTichHinhChuNhat = chieuDai * chieuRong;
    printf("Nhap ban kinh: ");
    scanf("%f", &banKinh);
    chuViHinhTron = 2 * PI * banKinh;
    dienTichHinhTron = PI * banKinh * banKinh;
    printf("Chu vi hinh chu nhat: %.2f\n", chuViHinhChuNhat);
    printf("Dien tich hinh chu nhat: %.2f\n", dienTichHinhChuNhat);
    printf("Chu vi hinh tron: %.2f\n", chuViHinhTron);
    printf("Dien tich hinh tron: %.2f\n", dienTichHinhTron);

    return 0;
}