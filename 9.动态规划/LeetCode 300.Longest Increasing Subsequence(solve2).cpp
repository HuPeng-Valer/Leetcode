/*
	最长上升子序列解法2：
	设置一个栈（vector实现）stack，stack[i]代表长度为i+1的上升子序列的最后一个元素的最小可能取值，即若要组成长度为i+2的上升子序列，需要
	一个大于stack[i]的元素，最终栈的大小，即为最长上升子序列长度
*/

#include <stdio.h>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
    	if (nums.size() == 0){
	    	return 0;
	    }
	    std::vector<int> stack;
	    stack.push_back(nums[0]);
	    for (int i = 1; i < nums.size(); i++){
	    	if (nums[i] > stack.back()){
	    		stack.push_back(nums[i]);
	    	}
	    	else{
	    		for (int j = 0; j < stack.size(); j++){
		    		if (stack[j] >= nums[i]){//思考这里等号的作用！！
		    			stack[j] = nums[i];
		    			break;
		    		}
		    	}
	    	}
    	}
        return stack.size();
    }
};

int main(){
	int test[] = {1, 3, 2, 3, 1, 4};
	std::vector<int> nums;
	for (int i = 0; i < 6; i++){
		nums.push_back(test[i]);
	}
	Solution solve;
	printf("%d\n", solve.lengthOfLIS(nums));
	return 0;
}
