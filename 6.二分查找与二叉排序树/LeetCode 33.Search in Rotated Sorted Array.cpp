/*
	给定一个无重复元素的排序数组，且nums可能以某个未知的下标旋转（左右移位），给定目标值target，若target在nums中出现则返回下标，否则返回-1
	无论怎么旋转，nums[begin]>nums[end]
*/

#include <stdio.h>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
    	int begin = 0;
		int end = nums.size() - 1;
		while(begin <= end){
			int mid = (begin + end) / 2;
			if (target == nums[mid]){
				return mid;
			}
			else if (target < nums[mid]){
				if (nums[begin] < nums[mid]){//说明begin到mid是递增的，只要target>nums[begin]就说明target只可能在begin到mid区间
					if (target >= nums[begin]){
						end = mid - 1;
					}
					else{
						begin = mid + 1;
					}
				}
				else if (nums[begin] > nums[mid]){//因为nums[begin]>nums[end]，mid+1到end一定是递增的，所以继续在旋转区间begin到mid-1里找
					end = mid -1;
				}
				else if (nums[begin] == nums[mid]){//begin和mid重合了，显然应该在mid后面的区间找
					begin = mid + 1;
				}
			}
			else if (target > nums[mid]){
				if (nums[begin] < nums[mid]){
					begin = mid + 1;
				}
				else if (nums[begin] > nums[mid]){
					if (target >= nums[begin]){
						end = mid - 1;
					}
					else{
						begin = mid + 1;
					}
				}
				else if (nums[begin] == nums[mid]){
					begin = mid + 1;
				}
			}
		}
		return -1;
    }
};

int main(){
	int test[] = {9, 12, 15, 20, 1, 3, 6, 7};
	std::vector<int> nums;
	Solution solve;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 22; i++){//随便写一个数组，然后从0开始到比数组中最大值大一点的数每一个都测一下，看看程序有没有问题
		printf("%d : %d\n", i, solve.search(nums, i));
	}
	return 0;
}
