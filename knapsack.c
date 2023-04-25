#include <stdio.h>
#include <stdlib.h>

struct item
{
	int profit;
	int weight;
	float PperW;
};

int compare (const void* a, const void* b)
{
	float ratioA=((struct item*)a)->PperW;
	float ratioB=((struct item*)b)->PperW;
	return (ratioA>ratioB)?1:(ratioA?:0);
}

int main()
{
	int n, capacity;
	float maxProfit=0.0;
	system("cls");
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	printf("Enter the size of container : ");
	scanf("%d", &capacity);
	struct item items[n];
	printf("Enter the profit and the corresponding weight :\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &items[i].profit, &items[i].weight);
		items[i].PperW = (float) items[i].profit / items[i].weight;
	}
	qsort(items, n, sizeof(struct item), compare);
	int i = n - 1;    
	while (capacity > 0 && i >= 0)
	{
		if (items[i].weight <= capacity)
		{
			capacity = capacity - items[i].weight;
			maxProfit = maxProfit + items[i].profit;
			i--;
		}
		else
		{
			maxProfit = maxProfit + (capacity * items[i].PperW);
			capacity = 0;
		}
	}
	printf("Maximum Profit : %f\n", maxProfit);
	return 0;
}