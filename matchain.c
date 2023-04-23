#include<stdio.h>
//#include<limits.h>
#define N 100
//#define inf 999999999

void mat_chain_order(int p[],int n,int m[][N],int s[][N])
{
    int i,j;
    int k,q,l;

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = 999999999;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {   m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_m(int s[][N],int i,int j)
{
    if(i==j)
    {
        printf("M%d",i);
    }
    else
    {
            printf("(");
            print_m(s, i, s[i][j]);
            print_m(s, s[i][j]+1, j);
            printf(")");
    }
}



int main()
{
    int n,i,j;
    int m[N][N];
    int s[N][N];
    int p[100];
    printf("Enter the number of elements : ");
    scanf("%d",&n );
    for(i=1;i<=n;i++)
    {
            for(j=i+1;j<=n;j++)
            {
                m[i][i]=0;
                m[i][j]=999999999;
                s[i][j]=0;
            }
    }

    printf("\nEnter the dimension of the matrices:\n");
    for(int k=0;k<=n;k++)
    {
            printf("p%d:",k);
            scanf("%d",&p[k]);
     }
    /*mat_chain_order(p,n,m,s);
    printf("Required matrix multiplication sequence\n");
    print_m(s, 1, n);
    printf("\nnMinimum number of multiplications: %ld\n",m[1][n]);
    return 0;
    int p[] = {13, 5, 89, 3, 34};
    int n = sizeof(p)/sizeof(p[0]) - 1;*/
    mat_chain_order(p,n,m,s);
    printf("Required matrix multiplication sequence\n");
    print_m(s, 1, n);
        printf("\nMinimum number of multiplications: %d\n", m[1][n]);
    return 0;
}

