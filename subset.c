#include <stdio.h>
#include <stdlib.h>

void sumOfSubsets(int set[], int subset[], int n, int subsetSize, int targetSum, int currentSum, int currentIndex) {
   
    if (currentSum == targetSum) {
        printf("{ ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }

  
    if (currentSum > targetSum || currentIndex >= n) {
        return;
    }

    
    subset[subsetSize] = set[currentIndex];
    sumOfSubsets(set, subset, n, subsetSize + 1, targetSum, currentSum + set[currentIndex], currentIndex + 1);


    sumOfSubsets(set, subset, n, subsetSize, targetSum, currentSum, currentIndex + 1);
}

int main() {
    int n, targetSum;
    int *set, *subset;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

  
    set = (int *)malloc(n * sizeof(int));
    subset = (int *)malloc(n * sizeof(int));

    if (set == NULL || subset == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("\nSubsets with sum equal to %d:\n", targetSum);
    sumOfSubsets(set, subset, n, 0, targetSum, 0, 0);

 
    free(set);
    free(subset);

    return 0;
}
