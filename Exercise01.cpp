// Exercise 1 - Finds the absolute value of a number and the sum of two numbers.

#include <cstdio>

int absolute_value(int x) {
	int result = 0;
	if (x < 0) {
		result = x * -1;
	}
	else result = x;
	return result;
}

int sum(int x, int y) {
	int result;
	result = x + y;
	return result;
}

int main() {
	int my_num = -42;
	int sum1 = 5;
	int sum2 = 35;
	printf("The absolute value of %d is %d.\n", my_num, absolute_value(my_num));
	printf("The sum of %d and %d is %d.\n", sum1, sum2, sum(sum1, sum2));
}
