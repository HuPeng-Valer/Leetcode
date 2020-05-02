/*一组数有重复元素，求所有子集
注意这题允许元素重复，但是元素相同顺序不同的算一个集合
有两种可能，一种子集完全相同顺序相同，第二种元素顺序不同
对原始数组排序后再求子集，只会出现第一种重复子集的情况
所以先对数组排序再用set去重
*/
#include <vector>
#include <set>
#include <algorithm>
class Solution{
public:
   std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums){
       std::vector<std::vector<int>> result;
       std::vector<int> item;
       std::set<std::vector<int>> res_set;
       std::sort(nums.begin(),nums.end()); //注意sort使用方法，不能sort(nums)
       result.push_back(item);
       generate(0, nums, result, item, res_set);
       return result;
   }
private:
    void generate(int i, std::vector<int>& nums,
                    std::vector<std::vector<int>> &result,
                    std::vector<int>& item,
                    std::set<std::vector<int>>& res_set){
        if(i>=nums.size()){
            return;
        }
        item.push_back(nums[i]);
        if(res_set.find(item) == res_set.end()){ //找不到返回end(),不能res_set.find(item) == nullptr;
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, nums, result, item, res_set);
        item.pop_back();
        generate(i+1, nums, result, item, res_set);
    }
};