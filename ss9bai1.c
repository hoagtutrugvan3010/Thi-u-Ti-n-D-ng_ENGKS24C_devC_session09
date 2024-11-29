#include <stdio.h>

int main() {
    int arr[100]; 
    int n, value, position;

    printf("Nhap so phan tu muon nhap (toi da 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("So phan tu khong hop le!\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);

    printf("Nhap vi tri muon them (tu 1 den %d): ", n + 1);
    scanf("%d", &position);

    if (position < 1 || position > n + 1) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }
    for (int i = n; i >= position - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position - 1] = value;
    n++; 

    printf("Mang sau khi them:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

