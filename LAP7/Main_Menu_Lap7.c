
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void demNguyenAmPhuAm(void);
void dangNhap(void);
void sapXepChuoi(void);
void doiSangThapLucPhan(void);
void xoaXuongDong(char s[]);

int main() {
    int chon;

    do {
        printf("\n+----------------------------------------------+\n");
        printf("|             MENU CHUONG TRINH LAB 7          |\n");
        printf("+----------------------------------------------+\n");
        printf("| 1. Dem nguyen am va phu am cua chuoi         |\n");
        printf("| 2. Dang nhap bang Username va Password       |\n");
        printf("| 3. Sap xep chuoi theo chu cai                |\n");
        printf("| 4. Doi so thap phan sang thap luc phan       |\n");
        printf("| 5. Thoat chuong trinh                        |\n");
        printf("+----------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");

        if (scanf("%d", &chon) != 1) {
            while (getchar() != '\n');
            printf("Lua chon khong hop le!\n");
            continue;
        }
        while (getchar() != '\n');

        switch (chon) {
            case 1:
                demNguyenAmPhuAm();
                break;
            case 2:
                dangNhap();
                break;
            case 3:
                sapXepChuoi();
                break;
            case 4:
                doiSangThapLucPhan();
                break;
            case 5:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 5);

    return 0;
}

void xoaXuongDong(char s[]) {
    s[strcspn(s, "\n")] = '\0';
}

void demNguyenAmPhuAm(void) {
    char s[200];
    int nguyenAm = 0, phuAm = 0;

    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    xoaXuongDong(s);

    for (int i = 0; s[i] != '\0'; i++) {
        char c = (char)tolower((unsigned char)s[i]);

        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                nguyenAm++;
            } else {
                phuAm++;
            }
        }
    }

    printf("Chuoi '%s' co chua: %d nguyen am va %d phu am.\n",
           s, nguyenAm, phuAm);
}
void dangNhap(void) {
    char username[50];
    char password[50];
    char matKhau[50];
    int i = 0;
    int c;

    printf("Nhap username: ");
    fgets(username, sizeof(username), stdin);
    xoaXuongDong(username);

    printf("Nhap password: ");

    while (1) {
        c = getch();

        if (c == '\r') {
            break;
        } else if (c == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else if (c >= 32 && c <= 126) {
            if (i < (int)sizeof(password) - 1) {
                password[i++] = (char)c;
                printf("*");
            }
        }
    }

    password[i] = '\0';
    printf("\n");

    strcpy(matKhau, "12345");

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, matKhau) == 0) {
        printf("Dang nhap thanh cong!\n");
    } else {
        printf("Dang nhap that bai!\n");
    }
}

void sapXepChuoi(void) {
    char s[5][200];
    char temp[200];

    for (int i = 0; i < 5; i++) {
        printf("Nhap chuoi %d: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        xoaXuongDong(s[i]);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

    printf("\nCac chuoi sau khi sap xep:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", s[i]);
    }
}

void doiSangThapLucPhan(void) {
    int n;
    char hex[50];
    char temp[50];
    char kyTuHex[] = "0123456789ABCDEF";
    int i = 0, j;

    printf("Nhap so thap phan: ");

    if (scanf("%d", &n) != 1) {
        while (getchar() != '\n');
        printf("So nhap vao khong hop le!\n");
        return;
    }
    while (getchar() != '\n');

    if (n < 0) {
        printf("So nhap vao khong hop le!\n");
        return;
    }

    if (n == 0) {
        strcpy(hex, "0");
    } else {
        while (n > 0) {
            hex[i++] = kyTuHex[n % 16];
            n /= 16;
        }
        hex[i] = '\0';

        for (j = 0; j < i; j++) {
            temp[j] = hex[i - 1 - j];
        }
        temp[i] = '\0';
        strcpy(hex, temp);
    }

    printf("So thap luc phan cua [so thap phan] la: [%s]\n",
           hex);
}
