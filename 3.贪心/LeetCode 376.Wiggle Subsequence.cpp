/*
	一个整数序列，如果两个相邻元素的差恰好正负（负正）交替出现，则称该序列为摇摆序列，一个小于两个元素的序列也为摇摆序列
	给一个随机序列，求这个序列满足摇摆序列定义的最长子序列的长度
*/

#include <stdio.h>

#include <vector>
class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
    	if (nums.size() < 2){
	    	return nums.size();
	    }
	    static const int BEGIN = 0;
	    static const int UP = 1;
	    static const int DOWN = 2;
	    int STATE = BEGIN;//state是第i个元素相对i-1个元素的状态
	    int max_length = 1;
    	for (int i = 1; i < nums.size(); i++){
    		switch(STATE){
	    	case BEGIN:
	    		if (nums[i-1] < nums[i]){
	    			STATE = UP;
		    		max_length++;
		    	}
		    	else if (nums[i-1] > nums[i]){
	    			STATE = DOWN;
	    			max_length++;
	    		}
	    		break;
	    	case UP:
	    		if (nums[i-1] > nums[i]){
	    			STATE = DOWN;
		    		max_length++;
		    	}
		    	break;
	    	case DOWN:
	    		if (nums[i-1] < nums[i]){
	    			STATE = UP;
		    		max_length++;
		    	}
		    	break;
		    }
	    }
    	return max_length;
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(17);
	nums.push_back(5);
	nums.push_back(10);
	nums.push_back(13);
	nums.push_back(15);
	nums.push_back(10);
	nums.push_back(5);
	nums.push_back(16);
	nums.push_back(8);
	Solution solve;
	printf("%d\n", solve.wiggleMaxLength(nums));
	return 0;
}
