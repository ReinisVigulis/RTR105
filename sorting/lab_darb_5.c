#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void bubbleSort(char arr[], int length, char *min, char *max, char *middle, char *mode) {
    int i, j;
    char temp;
    bool swapped;

    do {
        swapped = false;
        for (i = 0; i < length - 1; i++) {
            for (j = 0; j < length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
        }
    } while (swapped);

    // Find the first non-blank character
    int start = 0;
    while (arr[start] == ' ' && start < length) {
        start++;
    }

    // Shift non-blank characters to the beginning
    for (i = start; i < length; i++) {
        arr[i - start] = arr[i];
    }

    // Update the length
    length -= start;

    // Update min and max pointers
    *min = arr[0];
    *max = arr[length - 1];

    // Calculate middle
    *middle = arr[length / 2];

    // Calculate mode
    if (length % 2 == 0) {
        // Even-length sentence, output two middle characters
        mode[0] = arr[length / 2 - 1];
        mode[1] = arr[length / 2];
    } else {
        // Odd-length sentence, output one middle character
        *mode = arr[length / 2];
    }
}

int main() {
    char sentence[1000]; // Maximum sentence length
    int length;

    // User input
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; // Remove newline

    // Sort and remove blanks
    length = strlen(sentence);
    char min, max, middle, mode[2];
    bubbleSort(sentence, length, &min, &max, &middle, mode);

    // Display sorted characters without blanks
    printf("Sorted characters (without blanks): %s\n", sentence);

    // Display min, max, middle, and mode
    printf("Min character: %c\n", min);
    printf("Max character: %c\n", max);
    printf("Middle character(s): %c\n", middle);
    printf("Mode character(s): %c%c\n", mode[0], mode[1]);

    return 0;
}
