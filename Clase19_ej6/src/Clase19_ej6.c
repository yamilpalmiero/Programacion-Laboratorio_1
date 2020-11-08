#include <stdio.h>
#include <stdlib.h>

int main() {
	int *pnum = (int*) malloc(sizeof(int));

	int **pnum2 = (int**) malloc(sizeof(int*));

	*pnum2 = pnum;

	**pnum2 = 10;

	printf("%d\n", *pnum);
	printf("%d\n", **pnum2);

	return 0;
}
