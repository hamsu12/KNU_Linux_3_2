#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s num1 op num2\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[3]);
    char op = argv[2][0];
    int result;

    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case 'x': result = a * b; break;
        case '/':
            if (b == 0) {
                printf("Error: divide by zero\n");
                return 1;
            }
            result = a / b;
            break;
        default:
            printf("Unsupported operator: %c\n", op);
            return 1;
    }

    printf("%d\n", result);
    return 0;
}

