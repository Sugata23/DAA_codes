#include <stdio.h>
 
int fastPower(int X,int n)
{
    int r=1;
    while(n)
    {
        if (n%2)
        {
            r=r*X;
        }
        X*=X;
        n/=2;
    }
    return r;
}
int main()
{
    int x,n;
    
	printf("Enter X and n:\n");
	scanf("%d %d",&x,&n);

    printf("Result: %d\n",fastPower(x,n));
    return 0;
}
	