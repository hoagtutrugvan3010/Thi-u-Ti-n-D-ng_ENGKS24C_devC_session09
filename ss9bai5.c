#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100 

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int arr[MAX_SIZE];
    int n = 0; 
    int choice, value, position;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu cua mang (toi da %d): ", MAX_SIZE);
                scanf("%d", &n);
                if (n <= 0 || n > MAX_SIZE) {
                    printf("So phan tu khong hop le!\n");
                    n = 0;
                } else {
                    printf("Nhap gia tri cac phan tu cua mang:\n");
                    for (int i = 0; i < n; i++) {
                        printf("Phan tu thu %d: ", i + 1);
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            case 2:
                if (n == 0) {
                    printf("Mang rong.\n");
                } else {
                    printf("Gia tri cac phan tu trong mang: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                if (n == 0) {
                    printf("Mang rong.\n");
                } else {
                    int sum = 0;
                    printf("Gia tri cac phan tu chan: ");
                    for (int i = 0; i < n; i++) {
                        if (arr[i] % 2 == 0) {
                            printf("%d ", arr[i]);
                            sum += arr[i];
                        }
                    }
                    printf("\nTong cac phan tu chan: %d\n", sum);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("Mang rong.\n");
                } else {
                    int max = arr[0], min = arr[0];
                    for (int i = 1; i < n; i++) {
                        if (arr[i] > max) max = arr[i];
                        if (arr[i] < min) min = arr[i];
                    }
                    printf("Gia tri lon nhat trong mang: %d\n", max);
                    printf("Gia tri nho nhat trong mang: %d\n", min);
                }
                break;
            case 5:
                if (n == 0) {
                    printf("Mang rong.\n");
                } else {
                    int sum = 0;
                    printf("Gia tri cac phan tu la so nguyen to: ");
                    for (int i = 0; i < n; i++) {
                        if (isPrime(arr[i])) {
                            printf("%d ", arr[i]);
                            sum += arr[i];
                        }
                    }
                    printf("\nTong cac phan tu la so nguyen to: %d\n", sum);
                }
                break;
            case 6:
                if (n == 0) {
                    printf("Mang rong.\n");
                } else {
                    printf("Nhap gia tri can thong ke: ");
                    scanf("%d", &value);
                    int count = 0;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] == value) {
                            count++;
                        }
                    }
                    printf("Phan tu %d xuat hien %d lan trong mang.\n", value, count);
                }
                break;
            case 7:
                if (n == MAX_SIZE) {
                    printf("Mang da day. Khong the them phan tu.\n");
                } else {
                    printf("Nhap gia tri muon them: ");
                    scanf("%d", &value);
                    printf("Nhap vi tri can them (tu 1 den %d): ", n + 1);
                    scanf("%d", &position);
                    if (position < 1 || position > n + 1) {
                        printf("Vi tri khong hop le.\n");
                    } else {
                        for (int i = n; i >= position; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[position - 1] = value;
                        n++;
                        printf("Them phan tu thanh cong.\n");
                    }
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}


