#include <stdio.h>
long power(int x, unsigned n)
{
    
    long pow = 1L;
 
    
    for (int i = 0; i < n; i++) 
    {
        pow = pow * x;
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
 
    printf("pow(%d, %d) = %ld", x, n, power(x, n));
 
    return 0;
}
