/*
	给定一个数组，求这个数组的连续子数组中，最大的那一段的和
	思考：
		能否用dp[i]表示前i个数的最大子段和，进而推导出dp[i]与dp[i-1]之间的关系？
		不能！因为第i-1个数可能是负数，这样前i个数的最大字段在0~i-2之间，这与第i个数无法产生关系，即使第i个数是整数，也要考虑到第i个数是负数的影响
	分析：
		为了让第i个状态的最优解与第i-1个状态的最优解产生直接联系，思考：
			如果第i个状态dp[i]代表以第i个数字结尾的最大字段和，那么dp[i]与dp[i-1]之间的关系是什么？
			如何根据dp[i-1]推导出dp[i]？
		将求n个数的数组的最大字段和转换为分别求出以第1个，第2个，...第i个，...第n个数字结尾的最大子段和，再找出这n个结果中最大的，即为结果
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
    	std::vector<int> dp(nums.size(), 0);
    	dp[0] = nums[0];
    	int max_res = dp[0];
    	for (int i = 1; i < nums.size(); i++){
	    	dp[i] = std::max(dp[i-1] + nums[i], nums[i]);//注意一定要以第i个数字结尾
	    	if (max_res < dp[i]){
	    		max_res = dp[i];
	    	}
	    }
        return max_res;
    }
};

int main(){
	Solution solve;
	std::vector<int> nums;
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);
	printf("%d\n", solve.maxSubArray(nums));
	return 0;
}
