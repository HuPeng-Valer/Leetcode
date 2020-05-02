/*
	爬楼梯动态规划法
	思路：
		1.设置递推数组dp[0...n],dp[i]代表到达第i阶有多少种走法，初始化数组元素为0
		2.设置dp[1] = 1, dp[2] = 2
		3.利用i循环递推从第三阶至第n阶结果：
			dp[i] = dp[i-1] + dp[i-2]
*/
#include <stdio.h>
#include <vector>
class Solution {
public:
    int climbStairs(int n) {
    	std::vector<int> dp(n + 3, 0);//防止给的n是0
    	dp[1] = 1;
    	dp[2] = 2;
    	for (int i = 3; i <= n; i++){
	    	dp[i] = dp[i-1] + dp[i-2];
	    }
	    return dp[n];
    }
};

int main(){
	Solution solve;
	printf("%d\n", solve.climbStairs(3));	
	return 0;
}
