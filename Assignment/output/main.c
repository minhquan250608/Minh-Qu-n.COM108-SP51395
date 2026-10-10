#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
typedef struct {
    char hoTen[50];
    float diem;
    char hocLuc[20];
} SinhVien;
typedef struct {
    int tu;
    int mau;
} PhanSo;
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();
void chucNang5();
void chucNang6();
void chucNang7();
void chucNang8();
void chucNang9();
void chucNang10();
int timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
PhanSo toiGiuongPhanSo(PhanSo ps) {
    int ucln = timUCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    return ps;
}
int main() {
    int luaChon;
    do {
        printf("\n================= MENU CHUONG TRINH =================\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim UCLN va BCNN cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT (2/15)\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat chuong trinh\n");
        printf("=====================================================\n");
        printf("Moi ban chon chuc nang (0-10): ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 7: chucNang7(); break;
            case 8: chucNang8(); break;
            case 9: chucNang9(); break;
            case 10: chucNang10(); break;
            case 0:
                printf("\nCam on ban da su dung chuong trinh! Tam biet.\n");
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon lai!\n");
        }
    } while (luaChon != 0);
    return 0;
}
void chucNang1() {
    float x;
    printf("\n--- CHUC NANG 1: KIEM TRA SO NGUYEN ---\n");
    printf("Nhap vao so x: ");
    scanf("%f", &x);
    if (x == (int)x) {
        printf("%.2f LA so nguyen.\n", x);
        int n = (int)x;
        int laSoNguyenTo = 1;
        if (n < 2) laSoNguyenTo = 0;
        else {
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    laSoNguyenTo = 0;
                    break;
                }
            }
        }
        if (laSoNguyenTo) printf("%d LA so nguyen to.\n", n);
        else printf("%d KHONG PHAI la so nguyen to.\n", n);
        int sq = (int)sqrt(n);
        if (n >= 0 && sq * sq == n) printf("%d LA so chinh phuong.\n", n);
        else printf("%d KHONG PHAI la so chinh phuong.\n", n);
    } else {
        printf("%.2f KHONG PHAI la so nguyen.\n", x);
        printf("%.2f KHONG PHAI la so nguyen to.\n", x);
        printf("%.2f KHONG PHAI la so chinh phuong.\n", x);
    }
}
void chucNang2() {
    int x, y;
    printf("\n--- CHUC NANG 2: TIM UCLN VA BCNN ---\n");
    printf("Nhap so nguyen x: ");
    scanf("%d", &x);
    printf("Nhap so nguyen y: ");
    scanf("%d", &y);
    int ucln = timUCLN(x, y);
    int bcnn = abs(x * y) / ucln;
    printf("Uoc so chung lon nhat cua %d va %d la: %d\n", x, y, ucln);
    printf("Boi so chung nho nhat cua %d va %d la: %d\n", x, y, bcnn);
}
void chucNang3() {
    int gioBatDau, gioKetThuc;
    printf("\n--- CHUC NANG 3: TINH TIEN KARAOKE ---\n");
    printf("Nhap gio bat dau (12 - 23): ");
    scanf("%d", &gioBatDau);
    printf("Nhap gio ket thuc (12 - 23): ");
    scanf("%d", &gioKetThuc);
    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc) {
        printf("Gio khong hop le! Quan chi hoat dong tu 12h den 23h.\n");
        return;
    }
    int tongGio = gioKetThuc - gioBatDau;
    double tongTien = 0;
    if (tongGio <= 3) {
        tongTien = tongGio * 150000;
    } else {
        tongTien = 3 * 150000 + (tongGio - 3) * (150000 * 0.7);
    }
    if (gioBatDau >= 14 && gioBatDau <= 17) {
        tongTien = tongTien * 0.9; // Giam 10%
    }
    printf("Tong so gio hat: %d h\n", tongGio);
    printf("So tien can thanh toan: %.0f VND\n", tongTien);
}
void chucNang4() {
    double kWh;
    printf("\n--- CHUC NANG 4: TINH TIEN DIEN ---\n");
    printf("Nhap so kWh dien su dung: ");
    scanf("%lf", &kWh);
    if (kWh < 0) {
        printf("So kWh khong hop le!\n");
        return;
    }
    double tienDien = 0;
    if (kWh <= 50) {
        tienDien = kWh * 1678;
    } else if (kWh <= 100) {
        tienDien = 50 * 1678 + (kWh - 50) * 1734;
    } else if (kWh <= 200) {
        tienDien = 50 * 1678 + 50 * 1734 + (kWh - 100) * 2014;
    } else if (kWh <= 300) {
        tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kWh - 200) * 2536;
    } else if (kWh <= 400) {
        tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kWh - 300) * 2834;
    } else {
        tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kWh - 400) * 2927;
    }
    printf("Tong tien dien phai tra: %.0f VND\n", tienDien);
}
void chucNang5() {
    int tien;
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int soTo[9] = {0};

    printf("\n--- CHUC NANG 5: DOI TIEN ---\n");
    printf("Nhap vao so tien can doi: ");
    scanf("%d", &tien);

    if (tien <= 0) {
        printf("So tien khong hop le!\n");
        return;
    }

    int temp = tien;
    printf("Cac menh gia tien duoc doi ra:\n");
    for (int i = 0; i < 9; i++) {
        if (temp >= menhGia[i]) {
            soTo[i] = temp / menhGia[i];
            temp %= menhGia[i];
            printf("- %d to menh gia %d\n", soTo[i], menhGia[i]);
        }
    }
}
void chucNang6() {
    double tienVay;
    printf("\n--- CHUC NANG 6: TINH LAI SUAT VAY TRA GOP ---\n");
    printf("Nhap so tien muon vay (VND): ");
    scanf("%lf", &tienVay);
    double gocPhaiTra = tienVay / 12;
    double tienConLai = tienVay;
    double laiSuat = 0.05; 
    printf("\n%-10s %-15s %-15s %-15s %-15s\n", "Ky han", "Lai phai tra", "Goc phai tra", "So tien phai tra", "So tien con lai");
    for (int i = 1; i <= 12; i++) {
        double laiPhaiTra = tienConLai * laiSuat;
        double tongPhaiTra = laiPhaiTra + gocPhaiTra;
        tienConLai -= gocPhaiTra;
        if (tienConLai < 0) tienConLai = 0;

        printf("%-10d %-15.0f %-15.0f %-15.0f %-15.0f\n", i, laiPhaiTra, gocPhaiTra, tongPhaiTra, tienConLai);
    }
}
void chucNang7() {
    double phanTramVay;
    printf("\n--- CHUC NANG 7: VAY TIEN MUA XE ---\n");
    printf("Nhap phan tram vay toi da (vi du: 80 - nghia la tra truoc 20%%): ");
    scanf("%lf", &phanTramVay);
    if (phanTramVay <= 0 || phanTramVay > 100) {
        printf("Phan tram khong hop le!\n");
        return;
    }
    double tienDuocVay = 500000000; 
    double giaTriXe = tienDuocVay / (phanTramVay / 100.0);
    double tienTraTruoc = giaTriXe - tienDuocVay;
    int nam = 24;
    int thoiHanThang = nam * 12; 
    double laiNam = 0.072; 
    double laiThang = laiNam / 12;
    double gocHangThang = tienDuocVay / thoiHanThang;
    double laiThangDau = tienDuocVay * laiThang;
    double traThangDau = gocHangThang + laiThangDau;
    printf("Gia tri xe: %.0f VND\n", giaTriXe);
    printf("So tien phai tra lan dau (tra truoc): %.0f VND\n", tienTraTruoc);
    printf("So tien tra hang thang (thang dau tien): %.0f VND\n", traThangDau);
}
void chucNang8() {
    int n;
    printf("\n--- CHUC NANG 8: SAP XEP THONG TIN SINH VIEN ---\n");
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();
    SinhVien ds[100];
    for (int i = 0; i < n; i++) {
        printf("\nNhap ho ten SV %d: ", i + 1);
        fgets(ds[i].hoTen, sizeof(ds[i].hoTen), stdin);
        ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = 0;
        printf("Nhap diem SV %d: ", i + 1);
        scanf("%f", &ds[i].diem);
        getchar();
        if (ds[i].diem >= 9.0) strcpy(ds[i].hocLuc, "Xuat sac");
        else if (ds[i].diem >= 8.0) strcpy(ds[i].hocLuc, "Gioi");
        else if (ds[i].diem >= 6.5) strcpy(ds[i].hocLuc, "Kha");
        else if (ds[i].diem >= 5.0) strcpy(ds[i].hocLuc, "Trung binh");
        else strcpy(ds[i].hocLuc, "Yeu");
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diem < ds[j].diem) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("\n--- DANH SACH SINH VIEN SAU KHI SAP XEP (GIAM DAN) ---\n");
    for (int i = 0; i < n; i++) {
        printf("Ho ten: %-25s | Diem: %-5.1f | Hoc luc: %s\n", ds[i].hoTen, ds[i].diem, ds[i].hocLuc);
    }
}
void chucNang9() {
    int so1, so2;
    printf("\n--- CHUC NANG 9: GAME FPOLY-LOTT (2/15) ---\n");
    printf("Nhap so thu nhat (01 - 15): ");
    scanf("%d", &so1);
    printf("Nhap so thu hai (01 - 15): ");
    scanf("%d", &so2);
    if (so1 < 1 || so1 > 15 || so2 < 1 || so2 > 15) {
        printf("So nhap vao khong hop le!\n");
        return;
    }
    srand(time(NULL));
    int res1 = rand() % 15 + 1;
    int res2 = rand() % 15 + 1;
    printf("Ket qua so xo ngau nhien: %02d - %02d\n", res1, res2);
    int trung = 0;
    if (so1 == res1 || so1 == res2) trung++;
    if (so2 == res1 || so2 == res2) trung++;
    if (trung == 2) {
        printf("Chuc mung ban da trung giai nhat!\n");
    } else if (trung == 1) {
        printf("Chuc mung ban da trung giai nhi!\n");
    } else {
        printf("Chuc ban may man lan sau!\n");
    }
}
void chucNang10() {
    PhanSo ps1, ps2;
    printf("\n--- CHUC NANG 10: TINH TOAN PHAN SO ---\n");
    printf("Nhap tu so va mau so cua phan so 1: ");
    scanf("%d%d", &ps1.tu, &ps1.mau);
    printf("Nhap tu so va mau so cua phan so 2: ");
    scanf("%d%d", &ps2.tu, &ps2.mau);
    if (ps1.mau == 0 || ps2.mau == 0) {
        printf("Mau so phai khac 0!\n");
        return;
    }
    PhanSo tong = {ps1.tu * ps2.mau + ps2.tu * ps1.mau, ps1.mau * ps2.mau};
    tong = toiGiuongPhanSo(tong);
    PhanSo hieu = {ps1.tu * ps2.mau - ps2.tu * ps1.mau, ps1.mau * ps2.mau};
    hieu = toiGiuongPhanSo(hieu);
    PhanSo tich = {ps1.tu * ps2.tu, ps1.mau * ps2.mau};
    tich = toiGiuongPhanSo(tich);
    PhanSo thuong = {ps1.tu * ps2.mau, ps1.mau * ps2.tu};
    printf("\nKet qua:\n");
    printf("Tong: %d/%d\n", tong.tu, tong.mau);
    printf("Hieu: %d/%d\n", hieu.tu, hieu.mau);
    printf("Tich: %d/%d\n", tich.tu, tich.mau);
    if (thuong.mau != 0) {
        thuong = toiGiuongPhanSo(thuong);
        printf("Thuong: %d/%d\n", thuong.tu, thuong.mau);
    } else {
        printf("Thuong: Khong the thuc hien phep chia (tu so 2 bang 0)\n");
    }
}