/*
    1.使用位运算法，构造出所有和位target（总和/4）的子集，存储在向量ok_subset中，这些事候选的边组合
    2.遍历所有的ok_subset，两两进行对比，如果ok_subset[i]和subset[j]进行与运算的结果位0，则说明这两个集合无交集，即没有选择相同的火柴
      这两个集合可以代表两个可以同时存在的满足条件的边，将ok_subset[i]与ok_subset[j]求或，结果存储在ok_half中，它代表所有满足一半结果的情况
    3.遍历所有的ok_half,两两进行对比，如果ok_half[i]与ok_half[j]进行与运算的结果位0，则返回true，否则返回false
*/
#include <vector>
class Solution{
public:
    bool makesquare(std::vector<int>& nums){
        if(nums.size()<4){
            return false;
        }
        int sum = 0;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
        }
        if(sum%4){
            return false;
        }
        int target = sum/4;
        std::vector<int> ok_subset;
        std::vector<int> ok_half;
        int all = 1<<nums.size();//2^nums.size()种可能
        for(int i=0;i<all;++i){
            int sum = 0;
            for(int j=0;j<nums.size();++j){
                if(i&(1<<j)){
                    sum += nums[j];
                }
            }
            if(sum == target){
                ok_subset.push_back(i);
            }
        }
        for(int i=0;i<ok_subset.size();++i){
            for(int j=i+1;j<ok_subset.size();++j){
                if((ok_subset[i] & ok_subset[j]) == 0){
                    ok_half.push_back(ok_subset[i] | ok_subset[j]);
                }
            }
        }
        for(int i = 0;i<ok_half.size();++i){
            for(int j=i+1;j<ok_half.size();++j){
                if((ok_half[i] & ok_half[j]) == 0){
                    return true;
                }
            }
        }
        return false;

    }
};