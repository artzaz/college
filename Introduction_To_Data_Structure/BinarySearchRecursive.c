#include <stdio.h>

int binarySearch(int a[], int x, int low, int high) {
    if (low > high) {
        return -1;;
    }
    
    int mid = (low + high) / 2;
    
    if (a[mid] == x) {
        return mid;
    } else if (x < a[mid]) {
        return binarySearch(a, x, low, mid -1);
    } else {
        return binarySearch(a, x, mid + 1, high);
    }
    }
    
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int result = binarySearch(arr, x, 0, n - 1);
    
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }    
    
    return 0;
}
