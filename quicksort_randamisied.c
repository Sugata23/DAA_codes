#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int randomized_partition(int arr[], int low, int high) {
    srand(time(NULL));
    int i = low + rand() % (high - low + 1);
    swap(&arr[i], &arr[high]);
    return partition(arr, low, high);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomized_partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generate_permutation(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        swap(&arr[i], &arr[j]);
    }
}

int main() {
    int arr[10];
    generate_permutation(arr, 10);
    printf("Random Permutation: ");
    print_array(arr, 10);
    quicksort(arr, 0, 9);
    printf("Sorted Array: ");
    print_array(arr, 10);
    return 0;
}
