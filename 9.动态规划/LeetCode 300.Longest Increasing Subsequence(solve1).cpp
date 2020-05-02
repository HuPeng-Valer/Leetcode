/*
	已知一个未排序数组，求这个数组最长上升子序列的长度
	eg:[1,3,2,3,1,4]最长上升子序列为[1,2,3,4]
	注意区分子序列与子串，子序列可以不连续
	思考：
		1.若第i个状态代表前i个数字中最长上升子序列的长度，是否可找出dp[i]与dp[i-1]的关系
		2.若第i个状态代表以第i个数字为结尾的最长上升子序列的长度，是否可找出dp[i]与dp[i-1]的关系
		  再如何求出n各数字的最长上升子序列
		3.思考这题与最大子段和的相似之处
	最长上升子序列一定是以某一个元素为结尾
	算法：
		dp[i]代表以第i各元素结尾的最长上升子序列的长度，dp[0] = 1
		初始化最长上升子序列的长度LIS = 1
		从1到n-1，循环i，计算dp[i]：
			从0至i-1，循环j，若nums[i]>nums[j],说明nums[i]可放置再nums[j]得后面，组成最长上升子序列：
				若dp[i]<dp[j]+1:
					dp[i] = dp[j]+1
		LIS为dp[0]到dp[n-1]中最大者
*/
#include <stdio.h>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
    	if (nums.size() == 0){
	    	return 0;
	    }
        std::vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int LIS = 1;
        for (int i = 1; i < dp.size(); i++){
        	dp[i] = 1;
        	for (int j = 0; j < i; j++){
				/*
					一定要有这句dp[i]<dp[j]+1,因为nums[j]可能<num[i]但是也小于j之前的数
					eg:1,8,9,4,10
					如果只看nums[i]>nums[j]，那么10>4，而dp[3]只等于2，但是dp[2]等于3
				*/
	        	if (nums[i] > nums[j] && dp[i] < dp[j] + 1){
	        		dp[i] = dp[j] + 1;
	        	}
	        }
	        if (LIS < dp[i]){
        		LIS = dp[i];
        	}
        }
        return LIS;
    }
};

int main(){
	int test[] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
	std::vector<int> nums;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	Solution solve;
	printf("%d\n", solve.lengthOfLIS(nums));
	return 0;
}
