//Lagged fibonacci generator https://en.wikipedia.org/wiki/Lagged_Fibonacci_generator
#include <stdio.h>

#define MAX_SEQ_LEN 100 

int lagFib(int n, int lag)
{
	int seq[MAX_SEQ_LEN];
	int i;
  
		//initialize first two elements
	seq[0] = 0;
	seq[1] = 1;
  
		//generate remaining elements
	for (i =2; i < n; i++) {
		seq[i] = seq[i - lag] + seq[i - lag];
	}
		//return nth element
	return seq[n - 1];
}

int main()
{
	int n, lag, result;

	printf("Enter value of n: ");
	scanf("%d", &n);

	printf("Enter value of lag: ");
	scanf("%d", &lag);

	result = lagFib(n, lag);

	printf("The %dth element of the lagged fibonacci sequence: is %d\n", n, result);

	return 0;
}
