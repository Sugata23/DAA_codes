
#include <stdio.h>
long fast_power(int x, unsigned n)
{
    
    long pow = 1L;
    if (n==0)
    {
	return 1;
    }
    else if (n%2 != 0)
    {
	pow= x* pow*(fast_power(x,n/2));
    }
    else
    {
	pow=pow*(fast_power(x,n/2));
    }
 
    return pow;
}
 
int main(void)
{
    int x;
    unsigned n;
    printf("ENTER x and n \n");
    scanf("%d",&x);
    scanf("%d",&n);
 
    printf("pow(%d, %d) = %ld", x, n, fast_power(x, n));
 
    return 0;
}
