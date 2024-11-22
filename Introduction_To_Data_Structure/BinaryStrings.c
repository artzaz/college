#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; ++i) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}


void binaryAdd(const char* bin1, const char* bin2) {
    int len1 = strlen(bin1), len2 = strlen(bin2);
    int maxLen = len1 > len2 ? len1 : len2;
    char* result = (char*)malloc(maxLen + 2); 
    int carry = 0, k = 0;

    for (int i = 0; i < maxLen; ++i) {
        int bit1 = i < len1 ? bin1[len1 - i - 1] - '0' : 0;
        int bit2 = i < len2 ? bin2[len2 - i - 1] - '0' : 0;
        int sum = bit1 + bit2 + carry;
        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry) result[k++] = '1';
    result[k] = '\0';
    reverseString(result);
    printf("Sum: %s\n", result);
    free(result);
}


void binarySubtract(const char* bin1, const char* bin2) {
    int len1 = strlen(bin1), len2 = strlen(bin2);
    char* result = (char*)malloc(len1 + 1);
    int borrow = 0, k = 0;

    for (int i = 0; i < len1; ++i) {
        int bit1 = bin1[len1 - i - 1] - '0';
        int bit2 = i < len2 ? bin2[len2 - i - 1] - '0' : 0;
        int diff = bit1 - bit2 - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[k++] = diff + '0';
    }

    while (k > 1 && result[k - 1] == '0') --k; 
    result[k] = '\0';
    reverseString(result);
    printf("Difference: %s\n", result);
    free(result);
}


void binaryMultiply(const char* bin1, const char* bin2) {
    int len1 = strlen(bin1), len2 = strlen(bin2);
    int* temp = (int*)calloc(len1 + len2, sizeof(int));
    char* result;

    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int bit1 = bin1[i] - '0';
            int bit2 = bin2[j] - '0';
            temp[i + j + 1] += bit1 * bit2;
            if (temp[i + j + 1] >= 2) {
                temp[i + j] += temp[i + j + 1] / 2;
                temp[i + j + 1] %= 2;
            }
        }
    }

    result = (char*)malloc(len1 + len2 + 1); 
    int k = 0, start = 0;
    while (start < len1 + len2 && temp[start] == 0) ++start; 
    for (int i = start; i < len1 + len2; ++i) {
        result[k++] = temp[i] + '0';
    }

    if (k == 0) result[k++] = '0'; 
    result[k] = '\0';
    printf("Product: %s\n", result);
    free(result);
    free(temp);
}

int main() {
    const char* bin1 = "1101"; 
    const char* bin2 = "1011"; 

    binaryAdd(bin1, bin2);
    binarySubtract(bin1, bin2);
    binaryMultiply(bin1, bin2);

    return 0;
}
