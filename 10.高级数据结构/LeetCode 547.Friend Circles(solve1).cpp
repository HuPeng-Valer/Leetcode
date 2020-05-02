/*
	有N个同学，他们之间有些是朋友，有些不是，友谊是可以传递的，A与B是朋友，B与C是朋友，则A与C也是朋友
	朋友圈就是完成友谊传递后的一组朋友
	给定N*N的矩阵代表同学间是否是朋友，如果M[i][j]=1代表第i个学生与第j个学生是朋友，否则不是，求朋友圈个数
	方法1：深搜
*/
#include <stdio.h>
#include <vector>

void DFS_graph(int u,
			   std::vector<std::vector<int> >& graph,
			   std::vector<int>& visit){
	visit[u] = 1;
	for (int i = 0; i < graph[u].size(); i++){
		if (visit[i] == 0 && graph[u][i] == 1){
			DFS_graph(i, graph, visit);
		}
	}
}

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int> >& M) {
    	std::vector<int> visit(M.size(), 0);
    	int count = 0;
    	for (int i = 0; i < M.size(); i++){
    		if (visit[i] == 0){
		    	DFS_graph(i, M, visit);
		    	count++;
		    }
	    }
    	return count;
    }
};

int main(){
	int test[][3] = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	std::vector<std::vector<int> > M(3, std::vector<int>(3, 0));
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			M[i][j] = test[i][j];
		}
	}
	Solution solve;
	printf("%d\n", solve.findCircleNum(M));
	return 0;
}
