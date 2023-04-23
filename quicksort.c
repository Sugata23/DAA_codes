#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int comp=0;
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high,int n)
{
    int p=(rand() % (high - low)) + low;
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        comp++;       
        if (arr[j] <= pivot)
        {
                  i++;
                  swap(&arr[i], &arr[j]);
            }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
}
int pivot(int arr[], int low, int high, int n)

{
	int p = low + rand() % (high - low);
	int temp = arr[p];
	arr[p] = arr[low];
	arr[low] = temp;
    comp++;
	return partition(arr, low, high,n);

}

void qs(int arr[], int low, int high,int n)
{
    if (low < high)
    {
            int p = pivot(arr, low, high,n);
            qs(arr, low, p - 1,n);
            qs(arr, p + 1, high,n);
    }
}


int main()
{
    srand(time(NULL));
    long int n;
    printf("Enter the input size :");
    scanf("%ld",&n);
    int arr[n];
    for(int i = 0 ; i < n ; i++ )
    {
        arr[i]=rand() % n;
    }
    qs(arr, 0, n - 1,n);
    printf("Number of Comparisons :%d\n",comp);
    return 0;

}