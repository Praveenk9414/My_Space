#include <stdio.h>

// Function to convert a decimal number to binary with a specified number of bits
void binaryConversion(int data, int bitSize) {
    int arr[bitSize]; // Array to store binary digits

    // Initialize array elements to 0
    for (int i = 0; i < bitSize; i++) {
        arr[i] = 0;
    }

    int i = bitSize - 1; // Start from the most significant bit

    // Convert decimal to binary
    while (data > 0 && i >= 0) {
        arr[i] = data % 2; // Store the remainder (binary digit)
        data = data / 2;   // Update the quotient
        i--;               // Move to the next bit
    }

    // Print the binary representation
    for (int j = 0; j < bitSize; j++) {
        printf("%d", arr[j]);
    }
    printf("\n");
}

int main() {
    int decimalValue;
    printf("Enter the decimal value: ");
    scanf("%d", &decimalValue);

    int numBits;
    printf("Enter the number of bits (8 or 16): ");
    scanf("%d", &numBits);

    printf("Decimal %d in binary: ", decimalValue);
    binaryConversion(decimalValue, numBits);

    return 0;
}
