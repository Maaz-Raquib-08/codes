// Fibonacci series using Dynamic Programming O(n)
#include <stdio.h>
int dp[3];

int fib(int n){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n]; // Memoization Technique
    return dp[n] = fib(n-1) + fib(n-2);
}

int main()
{
    int n=2 ,i;
    for(i = 0; i<=n; ++i)
       dp[i]=-1;
    printf("%d" , fib(n));

    return 0;
}
