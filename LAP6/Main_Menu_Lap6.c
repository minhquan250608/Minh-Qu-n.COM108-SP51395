#include <stdio.h>

void timMaxMin(int a[], int n);
void sapXepGiamDan(int a[], int n);
void maTranBinhPhuong(int row, int col);
void xuatSoLeMaTran(int row, int col);
void hienThiMenu(void);

int main() {
    int chon;

    do {
        hienThiMenu();
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                timMaxMin(NULL, 0);
                break;
            case 2:
                sapXepGiamDan(NULL, 0);
                break;
            case 3: {
                int row, col;
                printf("Nhap so hang: ");
                scanf("%d", &row);
                printf("Nhap so cot: ");
                scanf("%d", &col);

                if (row > 0 && col > 0 &&
                    row <= 100 && col <= 100) {
                    maTranBinhPhuong(row, col);
                } else {
                    printf("Kich thuoc ma tran khong hop le!\n");
                }
                break;
            }
            case 4: {
                int row, col;
                printf("Nhap so hang: ");
                scanf("%d", &row);
                printf("Nhap so cot: ");
                scanf("%d", &col);

                if (row > 0 && col > 0 &&
                    row <= 100 && col <= 100) {
                    xuatSoLeMaTran(row, col);
                } else {
                    printf("Kich thuoc ma tran khong hop le!\n");
                }
                break;
            }
            case 5:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 5);

    return 0;
}

void hienThiMenu(void) {
    printf("\n");
    printf("+------------------------------------------------+\n");
    printf("|            MENU CHUONG TRINH LAB 6             |\n");
    printf("+------------------------------------------------+\n");
    printf("| 1. Tim gia tri Lon nhat va Nho nhat trong Mang |\n");
    printf("| 2. Sap xep Mang theo thu tu Giam dan           |\n");
    printf("| 3. Ma tran binh phuong (Mang 2 chieu)          |\n");
    printf("| 4. Loc va xuat vi tri cac So le trong Ma tran  |\n");
    printf("| 5. Thoat chuong trinh                          |\n");
    printf("+------------------------------------------------+\n");
}

void timMaxMin(int a[], int n) {
    int arr[1000];

    printf("Nhap so phan tu n: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So phan tu khong hop le!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Gia tri lon nhat trong mang: %d\n", max);
    printf("Gia tri nho nhat trong mang: %d\n", min);
}

void sapXepGiamDan(int a[], int n) {
    int arr[1000], temp;

    printf("Nhap so phan tu n: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So phan tu khong hop le!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, arr[i]);
    }
}

void maTranBinhPhuong(int row, int col) {
    int a[100][100];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Ma tran binh phuong:\n");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", a[i][j] * a[i][j]);
        }
        printf("\n");
    }
}

void xuatSoLeMaTran(int row, int col) {
    int a[100][100];
    int timThay = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (a[i][j] % 2 != 0) {
                printf("Phan tu le tai a[%d][%d] = %d\n",
                       i, j, a[i][j]);
                timThay = 1;
            }
        }
    }

    if (!timThay) {
        printf("Ma tran khong co so le!\n");
    }
}
