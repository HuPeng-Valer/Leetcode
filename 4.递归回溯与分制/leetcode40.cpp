/*
    已知一个有重复元素的数组和一个整数target，求这组数的所有子集中满足子集元素和等于target的那些子集
    思路：
        递归到一定程度，可以确定一定不满足目标，需要剪枝
        递归调用时，计算已选择元素的和sum，如果sum>target，则不再进行更深的搜索，直接返回
*/
#include <vector>
#include <set>
#include <algorithm>
class Solution{
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target){
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        std::set<std::vector<int>> res_set;
        std::sort(candidates.begin(), candidates.end());
        generate(0, candidates, result, item, res_set, 0, target);
        return result;
    }
private:
    void generate(int i, std::vector<int>& nums, std::vector<std::vector<int>>& result,
                std::vector<int>& item,
                std::set<std::vector<int>>& res_set,
                int sum, int target){
        if(i>nums.size() || sum > target){
            return;
        }
        sum += nums[i];
        item.push_back(nums[i]);
        if(sum == target && res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, nums, result, item, res_set, sum, target);
        sum -= nums[i];
        item.pop_back();
        generate(i+1, nums, result, item, res_set, sum, target);
    }
};