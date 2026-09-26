#include <stdio.h>

int main() {
    char mssv[] = "PS51395";
    char hoTen[] = "Tran Minh Quan";

    float diemToan = 9.0;
    float diemLy = 8.5;
    float diemHoa = 6.5;

    float diemTB = (diemToan * 2 + diemLy + diemHoa) / 4;

    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho va ten: %s\n", hoTen);
    printf("Diem trung binh: %.2f\n", diemTB);

    return 0;
}
