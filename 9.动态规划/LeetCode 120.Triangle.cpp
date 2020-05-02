/*
	给定一个二维数组，其保存了一个数字三角形(左端对齐)，求从数字三角形顶端到底端各数字和最小的路径之和
	每次可以向下走相邻的两个位置((i,j)可以走到(i+1,j)或(i+1,j+1))
	思考：
		1.从上到下或者从下到上的寻找路径的思考方式本质是一样的码
		2.假设dp[i][j]代表了数组三角形第i行，第j列的最优解，从上到下与从下到上哪种方式更容易递推？
		从下到上边界条件更容易写
	算法思路：
		1.设置一个二维数组，最优值三角形dp[][]，并初始化数组元素为0，dp[i][j]代表从底向上递推时，走到三角形第i行第j列的最优解
		2.从三角形的底面向三角形上方进行动态规划：
			a.动态规划边界条件：地面上的最优值即为数字三角形的最后一层
			b.利用i循环，从倒数第二层递推至第一层，对于每层的各列，进行动态规划递推：
			  第i行，第j列的最优解dp[i][j]，可到达(i,j)的两个位置的最优解dp[i+1][j],dp[i+1][j+1]
			  di[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j]
		3.返回dp[0][0]
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
class Solution {
public:
    int minimumTotal(std::vector<std::vector<int> >& triangle){
    	if (triangle.size() == 0){
	    	return 0;
	    }
    	std::vector<std::vector<int> > dp;
    	for (int i = 0; i < triangle.size(); i++){
	    	dp.push_back(std::vector<int>());
	    	for (int j = 0; j < triangle.size(); j++){
	    		dp[i].push_back(0);
	    	}
	    }
	    for (int i = 0; i < dp.size(); i++){
    		dp[dp.size()-1][i] = triangle[dp.size()-1][i];
    	}
	    for (int i = dp.size() - 2; i >= 0; i--){
	    	for (int j = 0; j < dp[i].size(); j++)
	    		dp[i][j] = std::min(dp[i+1][j], dp[i+1][j+1])
							 + triangle[i][j];
    	}
	    return dp[0][0];
    }
};

int main(){
	std::vector<std::vector<int> > triangle;
	int test[][10] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	for (int i = 0; i < 4; i++){
		triangle.push_back(std::vector<int>());
		for (int j = 0; j < i + 1; j++){
			triangle[i].push_back(test[i][j]);
		}
	}
	Solution solve;
	printf("%d\n", solve.minimumTotal(triangle));
	return 0;
}
