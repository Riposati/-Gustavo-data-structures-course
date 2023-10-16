#include <stdio.h>
#include <stdlib.h>

#define N 40
int count = 0;

int recursiveFibonacci(long long unsigned *cache, int n)
{
    count++;
	if (cache[n] == -1) {
		cache[n] = recursiveFibonacci(cache, n - 1) + recursiveFibonacci(cache, n - 2);
	}
	return cache[n];
}

void printArray(long long unsigned *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf(i == 0 ? "[ %llu" : ", %llu", arr[i]);
	}
	puts(" ]\n");
}

int main(void)
{	
    int tests,n;
    
    scanf("%d",&tests);

    // Initialise an array of N elements, each element set to -1
    // Note that this is a GNU extension to the GCC compiler
    long long unsigned cache[N] = { [0 ... N-1] = -1 };

    while(tests > 0){

        scanf("%d",&n);

        // Set the first two elements in the sequence, which are known
        cache[0] = 0;
        cache[1] = 1;

        printf("fib(%d) = %d calls = %llu\n",n,count,recursiveFibonacci(cache, n));

        printArray(cache, n);

        count = 0;
        tests--;
    }
	return 0;
}