#include <stdio.h>
double kiemDinhSanLuong(void) {
    double wh;
    do {
        printf("Nhap san luong dien (Wh > 0): ");
        scanf("%lf", &wh);
        if (wh <= 0) {
            printf("Gia tri khong hop le! Nhap lai.\n");
        }
    } while (wh <= 0);
    return wh;
}
double quyDoiKWh(double wh) {
    return wh / 1000.0;
}
double tinhCuocPhi(double kwh, double donGia) {
    return kwh * donGia;
}
int main(void) {
    double wh, kwh, donGia, tongTien;
    wh = kiemDinhSanLuong();
    kwh = quyDoiKWh(wh);
    printf("Nhap don gia (VND/kWh): ");
    scanf("%lf", &donGia);
    tongTien = tinhCuocPhi(kwh, donGia);
    printf("San luong da sac: %.0f Wh\n", wh);
    printf("Dien nang: %.2f kWh\n", kwh);
    printf("Tong cuoc phi: %.2f VND\n", tongTien);
    return 0;
}