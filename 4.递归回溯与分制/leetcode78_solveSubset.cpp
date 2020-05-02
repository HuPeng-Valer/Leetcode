/* 已知一组数无重复元素，求其所有子集*/
// 使用回溯法
# include <vector>
class Solution{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums){
        std::vector<std::vector<int>> result; //存储最终结果的result
        std::vector<int> item;//回溯时产生各个子集的数组
        result.push_back(item);//将空集push进result
        generate(0, nums, item, result);//计算各个子集
        return result;
    }
private:
    void generate(int i, std::vector<int>& nums,
                    std::vector<int> &item,
                    std::vector<std::vector<int>>&result){
        if(i >nums.size()){
            return;
        }
        /*
        对于给出数组中的每一个元素，首先加入item，加入result后继续后面的子集生成，
        然后在考虑不加入这个元素后的子集生成，所以result的push_back操作只在item的push_back操作之后才有
        */
        item.push_back(nums[i]);
        result.push_back(item);
        generate(i+1, nums, item, result);
        item.pop_back();
        generate(i+1, nums, item, result);
    }
};