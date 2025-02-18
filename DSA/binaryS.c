#include <stdio.h>

int binarySearch(int a[], int lb, int ub, int num, int *flag) {
    if (lb > ub) {
        *flag = 0; // Element not found
        return -1;
    }
    int mid = (lb + ub) / 2;
    if (a[mid] == num) {
        *flag = 1; // Element found
        return mid;
    } else if (a[mid] > num) {
        return binarySearch(a, lb, mid - 1, num, flag); // Search in the left half
    } else {
        return binarySearch(a, mid + 1, ub, num, flag); // Search in the right half
    }
}

int main() {
    int n, i, num, flag = 0;
    printf("enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("enter the element that you want to search: ");
    scanf("%d", &num);
    
    int result = binarySearch(a, 0, n - 1, num, &flag);
    if (flag) {
        printf("element found at position %d\n", result + 1);
    } else {
        printf("element not found!!\n");
    }
    return 0;
}