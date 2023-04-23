#include<stdio.h>
#include<stdlib.h>


int main()
{
	int **mA,**mB,**mC,rA,rB,cA,cB;
	int i,j,k;
	printf("Enter the number of rows for matrix A:\n");
	scanf("%d", &rA);
	printf("Enter the number of columns for matrix A:\n");
	scanf("%d", &cA);
	printf("Enter the number of rows for matrix B:\n");
	scanf("%d", &rB);
	printf("Enter the number of columns for matrix B:\n");
	scanf("%d", &cB);

	if (rA != cB)
	{
	        printf("Matrix multiplication is not possible\n");
		exit(1);
	}


	mA = (int **)malloc(rA * sizeof(int *));
	for (i = 0; i < rA; i++)
	        mA[i] = (int *)malloc(cA * sizeof(int));

	printf("Enter the elements matrix A:\n");
	for (i = 0; i < rA; i++)
		for (j = 0; j < cA; j++)
			scanf("%d", &mA[i][j]);


	mB = (int **)malloc(rB * sizeof(int *));
	for (i = 0; i < rB; i++)
	        mB[i] = (int *)malloc(cB * sizeof(int));

	printf("Enter the elements matrix B:\n");
	for (i = 0; i < rB; i++)
		for (j = 0; j < cB; j++)
			scanf("%d", &mB[i][j]);


	mC = (int **)malloc(rA * sizeof(int *));
	for (i = 0; i < rB; i++)
	        mC[i] = (int *)malloc(cB * sizeof(int));



	for (i = 0; i < rA; i++)
	{
		for (j = 0; j < cB; j++)
		{
			mC[i][j] = 0;
			for (k = 0; k < cA; k++)
			{
				mC[i][j] += mA[i][k] * mB[k][j];
			}
		}
	}

	
	printf("Required matrix:\n");
	for (i = 0; i < rA; i++)
	{
		for (j = 0; j < cB; j++)
		{
			printf("%d ", mC[i][j]);
		}

        	printf("\n");
    	}

	return 0;
}


