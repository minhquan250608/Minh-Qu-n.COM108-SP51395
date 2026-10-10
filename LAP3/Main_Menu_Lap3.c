
#include <stdio.h>
#include <math.h>
void tinhHocLuc(void);
void giaiPTBacHai(void);
void tinhTienDien(void);
int main(void) {
    int luaChon;

    do {
        printf("\n===== MENU CHUONG TRINH LAB 3 =====\n");
        printf("1. Tinh hoc luc sinh vien\n");
        printf("2. Giai phuong trinh bac hai\n");
        printf("3. Tinh tien dien tieu thu\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");

        if (scanf("%d", &luaChon) != 1) {
            printf("Lua chon khong hop le!\n");
            return 1;
        }

        switch (luaChon) {
            case 1:
                tinhHocLuc();
                break;
            case 2:
                giaiPTBacHai();
                break;
            case 3:
                tinhTienDien();
                break;
            case 0:
                printf("Da thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 0);

    return 0;
}
void tinhHocLuc(void) {
    float diem;
    printf("Nhap diem sinh vien (0.0 - 10.0): ");
    if (scanf("%f", &diem) != 1) {
        printf("Diem nhap khong hop le!\n");
        return;
    }

    if (diem < 0 || diem > 10) {
        printf("Diem so nhap vao khong hop le! (truong hop diem ngoai khoang 0.0 - 10.0)\n");
    } else if (diem >= 9.0) {
        printf("Hoc luc: Xuat sac\n");
    } else if (diem >= 8.0) {
        printf("Hoc luc: Gioi\n");
    } else if (diem >= 6.5) {
        printf("Hoc luc: Kha\n");
    } else if (diem >= 5.0) {
        printf("Hoc luc: Trung binh\n");
    } else if (diem >= 3.5) {
        printf("Hoc luc: Yeu\n");
    } else {
        printf("Hoc luc: Kem\n");
    }
}
void giaiPTBacHai(void) {
    double a, b, c, delta, x, x1, x2;

    printf("Nhap a, b, c: ");
    if (scanf("%lf%lf%lf", &a, &b, &c) != 3) {
        printf("Du lieu nhap khong hop le!\n");
        return;
    }

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Phuong trinh co vo so nghiem.\n");
            } else {
                printf("Phuong trinh vo nghiem.\n");
            }
        } else {
            x = -c / b;
            printf("Phuong trinh co nghiem duy nhat: x = %.2f\n", x);
        }
    } else {
        delta = b * b - 4 * a * c;

        if (delta < 0) {
            printf("Phuong trinh vo nghiem.\n");
        } else if (delta == 0) {
            x = -b / (2 * a);
            printf("Phuong trinh co nghiem kep: x = %.2f\n", x);
        } else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);

            printf("Phuong trinh co 2 nghiem phan biet: x1 = %.2f, x2 = %.2f\n",
                   x1, x2);
        }
    }
}
void tinhTienDien(void) {
    double kwh, tien = 0;

    printf("Nhap so kWh dien tieu thu: ");
    if (scanf("%lf", &kwh) != 1) {
        printf("So kWh khong hop le!\n");
        return;
    }

    if (kwh <= 0) {
        printf("So kWh phai lon hon 0!\n");
        return;
    }

    if (kwh <= 50) {
        tien = kwh * 1678;
    } else if (kwh <= 100) {
        tien = 50 * 1678 + (kwh - 50) * 1734;
    } else if (kwh <= 200) {
        tien = 50 * 1678 + 50 * 1734
             + (kwh - 100) * 2014;
    } else if (kwh <= 300) {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014
             + (kwh - 200) * 2536;
    } else if (kwh <= 400) {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014
             + 100 * 2536 + (kwh - 300) * 2834;
    } else {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014
             + 100 * 2536 + 100 * 2834
             + (kwh - 400) * 2927;
    }

    printf("Tong tien dien phai tra: %.0f dong\n", tien);
}

