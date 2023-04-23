#include <stdio.h>
 
int main()
{
	int x,n;
	
	printf("Enter X:\n");
	scanf("%d",&x);

	printf("Enter n\n");
	scanf("%d",&n);
	
	int r=x;
	while(n>1)
	{
		r=r*x;
		n--;
	}
	printf("Result: %d\n",r);
    return 0;

}
