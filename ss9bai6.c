#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

int sumArray(int arr[MAX_SIZE][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int isOdd(int x) {
    return x % 2 != 0;
}

int productBorder(int arr[MAX_SIZE][MAX_SIZE], int n) {
    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= arr[0][i]; 
        product *= arr[n-1][i]; 
        product *= arr[i][0]; 
        product *= arr[i][n-1]; 
    }
    return product;
}

void printMainDiagonal(int arr[MAX_SIZE][MAX_SIZE], int n) {
    printf("Duong cheo chinh: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
}

void printSecondaryDiagonal(int arr[MAX_SIZE][MAX_SIZE], int n) {
    printf("Duong cheo phu: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][n-i-1]);
    }
    printf("\n");
}

void printMaxRow(int arr[MAX_SIZE][MAX_SIZE], int n) {
    int maxSum = -999999; 
    int rowIndex = -1;
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += arr[i][j];
        }
        if (rowSum > maxSum) {
            maxSum = rowSum;
            rowIndex = i;
        }
    }

    printf("Dong co tong gia tri lon nhat: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", arr[rowIndex][j]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE][MAX_SIZE];
    int n, choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu la le va tinh tong\n");
        printf("4. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("6. In ra cac phan tu nam tren duong cheo phu\n");
        printf("7. In ra dong co tong gia tri cac phan tu la lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap kich co mang vuong: ");
                scanf("%d", &n);
                if (n <= 0 || n > MAX_SIZE) {
                    printf("Kich co mang khong hop le!\n");
                    continue;
                }
                printf("Nhap gia tri cac phan tu cua mang:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("Nhap phan tu arr[%d][%d]: ", i, j);
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;

            case 2:
                printf("Gia tri cac phan tu cua mang theo ma tran:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                {
                    int sum = 0;
                    printf("Gia tri cac phan tu le: ");
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (isOdd(arr[i][j])) {
                                printf("%d ", arr[i][j]);
                                sum += arr[i][j];
                            }
                        }
                    }
                    printf("\nTong cac phan tu le: %d\n", sum);
                }
                break;

            case 4:
                {
                    int product = productBorder(arr, n);
                    printf("Tich cac phan tu tren duong bien: %d\n", product);
                }
                break;

            case 5:
                printMainDiagonal(arr, n);
                break;

            case 6:
                printSecondaryDiagonal(arr, n);
                break;

            case 7:
                printMaxRow(arr, n);
                break;

            case 8:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 8);

    return 0;
}

