/*
	给定非负数组，nums[i]代表可以从第i个位置最多向前跳跃nums[i]步，已知确定可以跳到最后一个位置，
	求最少需要跳跃几次
	1.current_max_index当前可达最远位置
	2.pre_max_max_index在遍历各个位置过程中，各个位置可达最远位置
	3.jump_min最少跳跃次数
	4.利用i遍历nums数组，若i超过current_max_index,jump_min+1,current_max_index = pre_max_max_index
	5.遍历过程中，若index[i]更大，则更新pre_max_max_index
*/
#include <stdio.h>

#include <vector>
class Solution {
public:
    int jump(std::vector<int>& nums) {
    	if (nums.size() < 2){
	    	return 0;
	    }
        int current_max_index = nums[0];
        int pre_max_max_index = nums[0];
        int jump_min = 1;
        for (int i = 1; i < nums.size(); i++){
        	if (i > current_max_index){
        		jump_min++;
	        	current_max_index = pre_max_max_index;
	        }
        	if (pre_max_max_index < nums[i] + i){
       			pre_max_max_index = nums[i] + i;
        	}
        }
        return jump_min;
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	Solution solve;
	printf("%d\n", solve.jump(nums));
	return 0;
}
