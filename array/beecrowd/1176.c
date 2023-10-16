#include<stdlib.h>
#include<stdio.h>

int main(){

    int n,tests;

    scanf("%d",&tests);

    while(tests > 0){

        scanf("%d",&n);

        long long unsigned fibonacci[n+2];
        fibonacci[0] = 0;
        fibonacci[1] = 1;

        for(int i=2;i<n+2;i++){
            long long unsigned sum = fibonacci[i-1] + fibonacci[i-2];
            fibonacci[i] = sum;
        }

        // for(int i=0;i<n+2;i++){
        //     printf("%llu ",fibonacci[i]);
        // }

        printf("Fib(%d) = %llu\n",n,fibonacci[n]);
        tests--;
    }
    return 0;
}