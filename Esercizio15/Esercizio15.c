#include <stdio.h>
#include <time.h>

#define SIZE 10

int main() {
	int arr[SIZE];
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		arr[i] = rand(100);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	getchar();
	return 0;
}