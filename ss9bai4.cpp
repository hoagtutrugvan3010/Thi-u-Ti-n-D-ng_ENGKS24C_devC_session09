#include <stdio.h>

#define MAX_SIZE 100 

void displayArray(int arr[], int n) {
    if (n == 0) {
        printf("Mang rong.\n");
        return;
    }
    printf("Mang hien tai:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void addElement(int arr[], int *n) {
    if (*n >= MAX_SIZE) {
        printf("Mang da day. Khong the them phan tu moi.\n");
        return;
    }
    int value, position;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri can them (tu 1 den %d): ", *n + 1);
    scanf("%d", &position);

    if (position < 1 || position > *n + 1) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = *n; i >= position - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position - 1] = value;
    (*n)++;
    printf("Them phan tu thanh cong.\n");
}

void editElement(int arr[], int n) {
    int position, newValue;
    if (n == 0) {
        printf("Mang rong. Khong co phan tu de sua.\n");
        return;
    }
    printf("Nhap vi tri can sua (tu 1 den %d): ", n);
    scanf("%d", &position);

    if (position < 1 || position > n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);
    arr[position - 1] = newValue;
    printf("Sua phan tu thanh cong.\n");
}

void deleteElement(int arr[], int *n) {
    int position;
    if (*n == 0) {
        printf("Mang rong. Khong co phan tu de xoa.\n");
        return;
    }
    printf("Nhap vi tri can xoa (tu 1 den %d): ", *n);
    scanf("%d", &position);

    if (position < 1 || position > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = position - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Xoa phan tu thanh cong.\n");
}

int main() {
    int arr[MAX_SIZE];
    int n = 0; 
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
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
                    printf("Nhap cac phan tu cua mang:\n");
                    for (int i = 0; i < n; i++) {
                        printf("Phan tu thu %d: ", i + 1);
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                addElement(arr, &n);
                break;
            case 4:
                editElement(arr, n);
                break;
            case 5:
                deleteElement(arr, &n);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 6);

    return 0;
}

