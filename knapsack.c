// #include <stdio.h>
// #include <stdlib.h>

// struct item
// {
// 	int profit;
// 	int weight;
// 	float PperW;
// };

// int compare (const void* a, const void* b)
// {
// 	float ratioA=((struct item*)a)->PperW;
// 	float ratioB=((struct item*)b)->PperW;
// 	return (ratioA>ratioB)?1:(ratioA?:0);
// }

// int main()
// {
// 	int n, capacity;
// 	float maxProfit=0.0;
// 	system("cls");
// 	printf("Enter the number of elements : ");
// 	scanf("%d", &n);
// 	printf("Enter the size of container : ");
// 	scanf("%d", &capacity);
// 	struct item items[n];
// 	printf("Enter the profit and the corresponding weight :\n");
// 	for (int i = 0; i < n; i++)
// 	{
// 		scanf("%d%d", &items[i].profit, &items[i].weight);
// 		items[i].PperW = (float) items[i].profit / items[i].weight;
// 	}
// 	qsort(items, n, sizeof(struct item), compare);
// 	int i = n - 1;    
// 	while (capacity > 0 && i >= 0)
// 	{
// 		if (items[i].weight <= capacity)
// 		{
// 			capacity = capacity - items[i].weight;
// 			maxProfit = maxProfit + items[i].profit;
// 			i--;
// 		}
// 		else
// 		{
// 			maxProfit = maxProfit + (capacity * items[i].PperW);
// 			capacity = 0;
// 		}
// 	}
// 	printf("Maximum Profit : %f\n", maxProfit);
// 	return 0;
// }
//2nd approach _greedy approach
#include <stdio.h>
#include <stdlib.h>
void knapsack(int n,float weight[],float profit[],float capacity){
	float x[20],tp=0;//total profit
	int i,j,k;
	k=capacity;
	for(i=0;i<n;i++)
		x[i]=0.0;
	for(i=0;i<n;i++)
	{
		if(weight[i]>k)
		break;
		else{
			x[i]=1.0;
			tp+=profit[i];
			k-=weight[i];
			}
	}
		if(i<n)
			x[i]=k/weight[i];
		
		tp=tp+ (x[i]*profit[i]);
		printf("The resultant vector is:\n");
		for(i=0;i<n;i++)
			printf("%f\t",x[i]);
		printf("Maximum profit is %f\n",tp);
}

int main(){
	float weight[20],profit[20],capacity;
	int num,i,j;
	float ratio[20],temp;
	printf("Enter number of objects\n");
	scanf("%d",&num);
	printf("Enter the weight and profit of objects\n");
	for(i=0;i<num;i++)
	{
		scanf("%f",&weight[i]);
		scanf("%f",&profit[i]);
		ratio[i]=profit[i]/weight[i];
	}
	printf("Enter the capacity of knapsack\n");
	scanf("%f",&capacity);
	for(i=0;i<num;i++){
		for(j=i+1;j<num;j++){
			if(ratio[i]<ratio[j]){
				temp=ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=temp;
				temp=weight[i];
				weight[i]=weight[j];
				weight[j]=temp;
				temp=profit[i];
				profit[i]=profit[j];
				profit[j]=temp;
			}
		}
	}
	knapsack(num,weight,profit,capacity);
	return 0;
}