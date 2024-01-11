#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void bubbleSort(char arr[], int length, char *min, char *max, int *middle, char median[], char modes[], int counts[], int *modeCount) {
    int i, j;
    char temp;
    int sum = 0;
    int maxCount = 0;
    int currentCount = 1;
    bool swapped; 

    
    do {
        swapped = false;
        for (i = 0; i < length - 1; i++) {
            for (j = 0; j < length - 1 - i; j++) {
                if (arr[j] != ' ' && arr[j] > arr[j + 1]) {
                    
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true; 
                }
            }
        }
    } while (swapped); 

    
    int start = 0;
    while (arr[start] == ' ' && start < length) {
        start++;
    }

    
    *min = (start < length) ? arr[start] : '\0';
    *max = (length > 0) ? arr[length - 1] : '\0';

    
    for (i = start; i < length; i++) {
        if (arr[i] != ' ') {
            sum += (int)arr[i];
        }
    }
    int nonSpaceCount = length - start;
    *middle = (nonSpaceCount > 0) ? sum / nonSpaceCount : '\0';

    
     *modeCount = 0;

    for (i = start; i < length; i++) {
        if (arr[i] != ' ') {
            if (i > start && arr[i] == arr[i - 1]) {
                currentCount++;
            } else {
                currentCount = 1;
            }

            if (currentCount > maxCount) {
                maxCount = currentCount;
                *modeCount = 1; 
                modes[0] = arr[i];
                counts[0] = currentCount;
            } else if (currentCount == maxCount) {
                
                modes[*modeCount] = arr[i];
                counts[*modeCount] = currentCount;
                (*modeCount)++;
            }
        }
    }

   
    if (nonSpaceCount % 2 == 0) {
        
        median[0] = (nonSpaceCount > 0) ? arr[start + nonSpaceCount / 2 - 1] : '\0';
        median[1] = (nonSpaceCount > 1) ? arr[start + nonSpaceCount / 2] : '\0';
    } else {
        
        median[0] = (nonSpaceCount > 0) ? arr[start + nonSpaceCount / 2] : '\0';
        median[1] = '\0'; 
    }
}

int main() {
    char sentence[1000];
    int count = 0;
    int length;

    
    printf("Ievadiet teikumu: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    
    length = strlen(sentence);
    char min, max, median[2];
    int middle, modeCount;
    char modes[length]; 
    int counts[length];
    bubbleSort(sentence, length, &min, &max, &middle, median, modes, counts, &modeCount);

    
    printf("Sākartota simbolu rinda (atstarpes neņemot vērā): %s\n", sentence);

    
    printf("Simbolu ASCII vērtības: ");
    for (int i = 0; i < length; i++) {
        if (sentence[i] != ' ') {
            printf("%d ", (int)sentence[i]);
        }
    }
    printf("\n");

    
    printf("Mazākā vērtība: %c (%d)\n", min, min);
    printf("Lielākā vērtība: %c (%d)\n", max, max);
    printf("Vidējā vērtība (saskaņā ar ASCII skaitļiem): %c (%d)\n", middle, middle);
    printf("Moda: ");
    for (int i = 0; i < modeCount; i++) {
        printf("%c - biežums: %d, ", modes[i], counts[i]);
    }
    printf("\n");



    printf("Mediāna: %c%c\n", median[0], median[1]);

    return 0;
}
