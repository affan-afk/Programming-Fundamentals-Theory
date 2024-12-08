#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int binarytodecimal(int number) {
    int decimal = 0, base = 1, rem;
    while (number > 0) {
        rem = number % 10;
        decimal += rem * base;
        number /= 10;
        base *= 2;
    }
    return decimal;
}

int decimaltobinary(int number) {
    int binary = 0, remainder, factor = 1;
    while (number > 0) {
        remainder = number % 2;
        binary += remainder * factor;
        number /= 2;
        factor *= 10;
    }
    return binary;
}

void decimaltohexadecimal(int number) {
    if (number == 0) {
        printf("0x0\n");
        return;
    }

    char hex[20];
    int i = 0;
    while (number != 0) {
        int temp = number % 16;
        if (temp < 10)
            hex[i] = temp + '0';
        else
            hex[i] = temp - 10 + 'A';
        i++;
        number /= 16;
    }

    printf("0x");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
    printf("\n");
}


void hexadecimaltodecimal(char hexNumber[]) {
    int len = strlen(hexNumber);
    int base = 1, decimal = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9')
            decimal += (hexNumber[i] - '0') * base;
        else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F')
            decimal += (hexNumber[i] - 'A' + 10) * base;
        base *= 16;
    }

    printf("Decimal: %d\n", decimal);
}

void binarytohexadecimal(int number) {
    int decimal = binarytodecimal(number);
    decimaltohexadecimal(decimal);
}

void hexadecimaltobinary(char hexNumber[]) {
    int decimal = 0, base = 1, len = strlen(hexNumber);
    for (int i = len - 1; i >= 0; i--) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9')
            decimal += (hexNumber[i] - '0') * base;
        else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F')
            decimal += (hexNumber[i] - 'A' + 10) * base;
        base *= 16;
    }

    if (decimal == 0) {
        printf("0\n");
        return;
    }

    int binary[32], i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
    printf("\n");
}

void menu() {
    printf("Select an option:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("7. Exit\n");
}

int main() {
    int choice, number;
    char hexNumber[20];

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Decimal: %d\n", binarytodecimal(number));
                break;

            case 2: 
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Binary: %d\n", decimaltobinary(number));
                break;

            case 3: 
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                decimaltohexadecimal(number);
                break;

            case 4: // Hexadecimal to Decimal
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                hexadecimaltodecimal(hexNumber);
                break;

            case 5: 
                printf("Enter a binary number: ");
                scanf("%d", &number);
                binarytohexadecimal(number);
                break;

            case 6: 
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                hexadecimaltobinary(hexNumber);
                break;

            case 7: 
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
