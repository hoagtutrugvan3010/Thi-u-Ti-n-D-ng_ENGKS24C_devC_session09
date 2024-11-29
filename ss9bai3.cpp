#include <stdio.h>

int main() {
    int arr[100]; 
    int n, position;

    printf("Nhap so phan tu cua mang (toi da 100): ");
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

    printf("Nhap vi tri can xoa (tu 1 den %d): ", n);
    scanf("%d", &position);

    if (position < 1 || position > n) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    for (int i = position - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1]; 
    }
    n--; 

    printf("Mang sau khi xoa:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

