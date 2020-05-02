/*
    已知一个数组，有n个数（n<=15），每个数表示一个火柴的长度，问是否可用这n个火柴摆正一个正方形
    思考：
        每个火柴数以正方形四条边的一条，暴力搜索有4^15种可能
        1.回溯算法如何设计，与第四节课求子集的问题有哪些相似的地方
        2.递归的回溯搜索DFS何时返回真，何时返回假
        3.普通的回溯搜索DFS能否解决问题，如何对深度搜索剪枝优化
        4.该题是否也可用位运算解决
    算法：
        想象正方形的四条边为四个桶，将每个火柴回溯的放置在每个桶中，在放完n个火柴后，检查4个桶中的火柴长度和是否相同，相同返回真，否则返回假
        在回溯过程中，如果当前所有可能向后的回溯，都无法满足条件，即递归函数最终返回假
    优化：
        1.n个火柴总和对4取余需要为0，否则返回假
        2.火柴按照从大到小的顺序排序，先尝试大的减少回溯的可能
        3.每次放置时，每条边上不可放置超过总和1/4长度的火柴
*/
#include <vector>
#include <algorithm>
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
        if(sum % 4 != 0){
            return false;
        }
        std::sort(nums.rbegin(),nums.rend());
        int bucket[4] = {0};
        return generate(0, nums, sum/4, bucket);
    }
private:
    bool generate(int i,std::vector<int>& nums, int target, int bucket[]){
        if(i == nums.size()){
            return bucket[0]==target && bucket[1] == target && bucket[2] == target && bucket[3] == target;
        }
        for(int j=0;j<4;++j){//每根火柴只能属于一个bucket，第j个不对就j+1，体会回溯的过程！！！
            if(bucket[j] + nums[i] > target){
                continue;
            }
            bucket[j] += nums[i];
            if(generate(i+1,nums,target,bucket)){
                return true;
            }
            bucket[j] -= nums[i];
        }
        return false;//i放在4个桶中任意一个都不行，说明前面的放错了

    }
};