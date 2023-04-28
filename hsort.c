#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int arr[], int n, int i, int *comp)
{
	int largest = i, left = 2 * i + 1, right = 2 * i + 2;
	(*comp)++;
	if (left < n)
	{
		if (arr[left] > arr[largest])
			largest = left;
	}
	if (right < n)
	{
		if (arr[right] > arr[largest])
			largest = right;
	}
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest, comp);
	}
}
void heapSort(int arr[], int n, int *comp)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i, comp);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0, comp);
	}
}
void file(int arr[], int *comp, char *input, char *output)
{
	FILE *inputRandom = fopen(input, "w");
	for (int i = 0; i < N; i++)
		fprintf(inputRandom, "%d ", rand() % 10000);
	fclose(inputRandom);

	FILE *infile = fopen(input, "r");
	FILE *outfile = fopen(output, "w");
	for (int i = 0; i < N; i++)
		fscanf(infile, "%d", &arr[i]);
	heapSort(arr, N, comp);

	for (int i = 0; i < N; i++)
		fprintf(outfile, "%d ", arr[i]);
	fclose(infile);
	fclose(outfile);
}
int main()
{
	srand(time(NULL));
	int arr[N], comp[5] = {0, 0, 0, 0, 0};

	file(arr, &comp[0], "input1.txt", "output1.txt");
	file(arr, &comp[1], "input2.txt", "output2.txt");
	file(arr, &comp[2], "input3.txt", "output3.txt");
	file(arr, &comp[3], "input4.txt", "output4.txt");
	file(arr, &comp[4], "input5.txt", "output5.txt");

	double avg_comp = 0;
	for (int i = 0; i < 5; i++)
		avg_comp += comp[i];
	avg_comp /= 5.0;
	printf("Average number of comparisons: %lf\n", avg_comp);
	return 0;
}