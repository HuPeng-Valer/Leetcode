/*使用位运算解决子集问题
    若一个集合有3个元素，则三个元素有8种组成方式，用0-7表示这些集合
    0-7用二进制表示只有三位，可以分别表示这三个元素在不在这个集合中
    第一个元素用100=4表示
*/
#include <vector>
class Solution{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums){
        std::vector<std::vector<int>> result;
        int all_set= 1<<nums.size();
        for(int i=0; i < all_set; i++){
            std::vector<int> item;
            for(int j=0; j < nums.size(); j++){
                if(i&(1<<j)){
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};