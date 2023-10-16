#include<stdlib.h>
#include<stdio.h>

int howManyCalls = 0;

long long unsigned fibonacci(int n){
    howManyCalls++;

    if(n==0)
        return 0;
    if(n==1)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int tests,n;
    
    scanf("%d",&tests);

    while(tests > 0){

        scanf("%d",&n);

        printf("fib(%d) = %d calls = %llu\n",n,howManyCalls-1,fibonacci(n));

        howManyCalls=0;

        tests--;
    }

    return 0;
}