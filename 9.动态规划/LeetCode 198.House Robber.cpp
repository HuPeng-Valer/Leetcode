/*
	在一条直线上有n个房屋，每个房屋种有数量不等的财宝，有一个盗贼希望从房屋中盗取财宝，
	由于房屋中有报警器，如果同时从相邻的两个房屋中盗取财宝就会触发报警器，问在不触发报警器的前提下
	最多可获取多少财宝
	思考：
		1.n个房屋，每个房屋都有盗取/不盗取两种可能，类似求子集的方法，在不触发警报的情况下
		  选择总和最大的子集，最多有2^n种可能，时间复杂度为O(2^n)
		2.贪心算法是否可行？
		  在满足不处罚警报的同时，每次选择财宝最多的房间
		3.若考虑dp，如何确认dp原问题与子问题，状态，边界状态，状态转移方程
	分析：
		若选择第i个房间盗取财宝，就一定不能选择第i-1个房间盗取财宝
		若不选择第i个房间盗取财宝，则相当于只考虑前i-1个房间盗取财宝
	算法：
		1.原问题：n个房间的最优解
		  子问题：前1个房间，前2个房间，...前n-1锋房间的最优解
		2.确认状态
		  第i个状态即为前i个房间能够获得的最大财宝（最优解）
		3.确认边界状态的值
		  前1个房间的最优解，第1个房间的财宝
		  前2个房间的最优解，第1，2个房间中较大财宝的
		4.确定状态转移方程
		  a.选择第i个房间：第i个房间+前i-2个房间的最优解
		  b.不选择第i个房间:前i-1个房间的最优解
		  动态转移方程：
		  dp[i] = max(dp[i-1],dp[i-2]+nums[i]);(i>=3)
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
class Solution {
public:
    int rob(std::vector<int>& nums) {
    	if (nums.size() == 0){
	    	return 0;
	    }
	    if (nums.size() == 1){
    		return nums[0];
    	}
    	std::vector<int> dp(nums.size(), 0);
    	dp[0] = nums[0];
    	dp[1] = std::max(nums[0], nums[1]);
    	for (int i = 2; i < nums.size(); i++){
	    	dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
	    }
	    return dp[nums.size() - 1];
    }
};

int main(){
	Solution solve;
	std::vector<int> nums;
	nums.push_back(5);
	nums.push_back(2);
	nums.push_back(6);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(7);	
	printf("%d\n", solve.rob(nums));
	return 0;
}
