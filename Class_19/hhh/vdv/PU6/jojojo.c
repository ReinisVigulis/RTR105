#include <stdio.h>

// Function without arguments and without return
void without_arguments_without_return() {
    printf("Function without arguments and without return\n");
}

// Function with arguments and without return
void with_arguments_without_return(int arg1, int arg2) {
    printf("Function with arguments %d and %d, without return\n", arg1, arg2);
}

// Function without arguments and with return
int without_arguments_with_return() {
    printf("Function without arguments, with return\n");
    return 42; // Returning an arbitrary value
}

// Function with arguments and with return
int with_arguments_with_return(int arg1, int arg2) {
    printf("Function with arguments %d and %d, with return\n", arg1, arg2);
    return arg1 + arg2; // Returning the sum of arguments
}

int main() {
    // Call each function and demonstrate their behavior
    without_arguments_without_return();

    with_arguments_without_return(10, 20);

    int result1 = without_arguments_with_return();
    printf("Result from without_arguments_with_return: %d\n", result1);

    int result2 = with_arguments_with_return(5, 7);
    printf("Result from with_arguments_with_return: %d\n", result2);

    return 0;
}
