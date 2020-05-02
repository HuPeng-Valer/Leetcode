/*
	已知不同面值的钞票，求用最少数量的钞票组成某个金额的钞票数量，如果任意数量的已知面值钞票都无法组成该金额，返回-1
	算法思路：
		dp[i]代表金额i的最优解（最小使用张数）
		dp[]中存储金额1到金额amount的最优解
		eg:coins=[1,2,5,7,10], amount=14
		金额i可由：
			金额i-1与coins[0](1)组合
			金额i-2与coins[1](2)组合
			金额i-5与coins[2](5)组合
			金额i-7与coins[3](7)组合
			金额i-10与coins[4](10)组合
		dp[i] = min(dp[i-1],dp[i-2],dp[i-5],dp[i-7],dp[i-10])+1
*/

#include <stdio.h>
#include <vector>
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
		std::vector<int> dp;
		for (int i = 0; i <= amount; i++){
			dp.push_back(-1);
		}
		dp[0] = 0;
		for (int i = 1; i <= amount; i++){
			for (int j = 0; j < coins.size(); j++){
				if (i - coins[j] >= 0 && dp[i - coins[j]] != -1){//i-coins[j]>=0说明可以用coins[j]组成i
					if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1){//这里保证了min操作
						dp[i] = dp[i - coins[j]] + 1;
					}
				}
			}
		}
		return dp[amount];
    }
};

int main(){	
	Solution solve;
	std::vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	coins.push_back(7);
	coins.push_back(10);	
	for (int i = 1; i<= 14; i++){
		printf("dp[%d] = %d\n", i, solve.coinChange(coins, i));
	}
	return 0;
}
