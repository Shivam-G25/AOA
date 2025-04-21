#include <stdio.h>
#include <string.h>


void naiveStringMatching(char text[], char pattern[]) {
    int n = strlen(text);    
    int m = strlen(pattern); 

    printf("Pattern found at indices: ");
    int found = 0;

    
    for (int i = 0; i <= n - m; i++) {
        int j;

        
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        
        if (j == m) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}


int main() {
    char text[1000], pattern[100];

   
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 

   
    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; 

    
    naiveStringMatching(text, pattern);

    return 0;
}
