/*
	N个节点的图，就用N*N的矩阵表示
	(i,j)表示第i个节点有没有和第j个节点相连
*/

#include <stdio.h>

int main(){
	const int MAX_N = 5;
	int Graph[MAX_N][MAX_N] = {0};
	Graph[0][2] = 1;
	Graph[0][4] = 1;
	Graph[1][0] = 1;
	Graph[1][2] = 1;
	Graph[2][3] = 1;
	Graph[3][4] = 1;
	Graph[4][3] = 1;
	printf("Graph:\n");
	for (int i = 0; i < MAX_N; i++){
		for (int j = 0; j < MAX_N; j++){
			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}


