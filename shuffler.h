#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A utility function to print an array
void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void randomize ( int arr[], int n ) {
    srand ( time(NULL) );
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

void shuffle(int arr[], int n) {
    randomize (arr, n);
}
