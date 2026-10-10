#include <stdio.h>
int giaoDich(double *soDu, double tongTien,
             double tyLeHoanTien, double *tienHoan) {
    if (*soDu < tongTien) {
        *tienHoan = 0;
        return 0;
    }
    *soDu -= tongTien;
    *tienHoan = tongTien * tyLeHoanTien / 100.0;
    *soDu += *tienHoan;
    return 1;
}
int main(void) {
    double soDu, tongTien, tyLeHoanTien, tienHoan = 0;
    int ketQua;
    printf("Nhap so du vi: ");
    scanf("%lf", &soDu);
    printf("Nhap tien hoa don: ");
    scanf("%lf", &tongTien);
    printf("Nhap ty le hoan tien (%%): ");
    scanf("%lf", &tyLeHoanTien);
    ketQua = giaoDich(&soDu, tongTien,
                      tyLeHoanTien, &tienHoan);
    if (ketQua == 0) {
        printf("Giao dich that bai!\n");
    } else {
        printf("Giao dich thanh cong!\n");
    }
    printf("So du vi hien tai: %.2f\n", soDu);
    printf("Tien hoan: %.2f\n", tienHoan);
    return 0;
}