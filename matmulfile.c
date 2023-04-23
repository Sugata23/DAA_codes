#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *in,*out;
	int **mA,**mB,**mC,rA,rB,cA,cB;
	int i,j,k;
	printf("Enter the number of rows & columns for matrix A:");
	scanf("%d %d", &rA,&cA );
	printf("Enter the number of rows & columns for matrix B:");
	scanf("%d %d",&rB,&cB);
	in= fopen("input.txt", "r");

	if (rA != cB)
	{
	        printf("Matrix multiplication is not possible\n");
		exit(1);
	}

	mA = (int **)malloc(rA * sizeof(int *));
	for (i = 0; i < rA; i++)
	        mA[i] = (int *)malloc(cA * sizeof(int));
	mB = (int **)malloc(rB * sizeof(int *));
	for (i = 0; i < rB; i++)
	        mB[i] = (int *)malloc(cB * sizeof(int));
	mC = (int **)malloc(rA * sizeof(int *));
	for (i = 0; i < rB; i++)
	        mC[i] = (int *)malloc(cB * sizeof(int));

	//printf("Enter the elements matrix A:\n");
	for (i = 0; i < rA; i++)
		for (j = 0; j < cA; j++)
			fscanf(in,"%d", &mA[i][j]);
	
	//printf("Enter the elements matrix B:\n");
	for (i = 0; i < rB; i++)
		for (j = 0; j < cB; j++)
			fscanf(in,"%d", &mB[i][j]);

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


	printf("open output file to see the result\n");
	out=fopen("output.txt","w");
	for (i = 0; i < rA; i++)
	{
		for (j = 0; j < cB; j++)
		{
			fprintf(out,"%d ", mC[i][j]);
		}

        	fprintf(out,"\n");
    }

	fclose(in);
	fclose(out);

	return 0;

}
