/*
	hard
	已知一个二维数组，左上角代表骑士的位置，右下角代表公主的位置，二维数组中存储整数，正数可以给骑士增加生命值，负数会减少骑士的生命值
	问起始初始时至少是多少生命值，才可保证骑士在行走过程中至少保持生命值为1（骑士只能向下或向右行走）
	思路：
		从右下向左上递推：dp[i][j]代表若要达到右下角，至少有多少血量，能在行走的过程中至少保持生命值为1
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int> >& dungeon) {
    	if (dungeon.size() == 0){
	    	return 0;
	    }
    	std::vector<std::vector<int> > 
			dp(dungeon.size(), std::vector<int>(dungeon[0].size(), 0));
    	int row = dungeon.size();
    	int column = dungeon[0].size();
    	dp[row-1][column-1] = std::max(1, 1-dungeon[row-1][column-1]);
    	for (int i = column-2; i>=0; i--){
	    	dp[row-1][i] = std::max(1,
									dp[row-1][i+1] - dungeon[row-1][i]);
	    }
	    for (int i = row-2; i>=0; i--){
	    	dp[i][column-1] = std::max(1,
								dp[i+1][column-1] - dungeon[i][column-1]);
	    }
	    for (int i = row-2; i>=0; i--){
    		for (int j = column-2; j>=0; j--){
    			int dp_min = std::min(dp[i+1][j], dp[i][j+1]);
		    	dp[i][j] = std::max(1, dp_min - dungeon[i][j]);
		    }
    	}
	    return dp[0][0];
    }
};

int main(){
	int test[][3] = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
	std::vector<std::vector<int> > dungeon;
	for (int i = 0; i < 3; i++){
		dungeon.push_back(std::vector<int>());
		for (int j = 0; j < 3; j++){
			dungeon[i].push_back(test[i][j]);
		}
	}
	Solution solve;
	printf("%d\n", solve.calculateMinimumHP(dungeon));
	return 0;
}
