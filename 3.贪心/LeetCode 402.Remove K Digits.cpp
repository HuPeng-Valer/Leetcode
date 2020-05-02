/*
	栈，队列等数据结构经常和贪心算法结合！
	一个大整数用字符串表示，去除其中k个字符，求可能得到的最小数字，用字符串输出
	思考路线：
		1.假设k=1，应该怎么去？
		2.如果k>1,应该按照什么顺序与策略删除数字
	使用栈存储最终结果，从高位向低位遍历，如果遍历的数字大于栈顶元素，则将该数字入栈，如果小于栈顶元素则弹栈
*/
#include <stdio.h>

#include <string>
#include <vector>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
    	std::vector<int> S;//用vector实现栈，因为vector可以遍历
    	std::string result = "";
    	for (int i = 0; i < num.length(); i++){
	    	int number = num[i] - '0';//将字符转换为整数
	    	while(S.size() != 0 && S[S.size()-1] > number && k > 0){ // 为什么必须是while？number不能只跟栈顶元素比较，要跟栈内所有元素比较！！ 
	    		S.pop_back();
	    		k--;
	    	}
	    	if (number != 0 || S.size() != 0){ // 注意这里添加0，栈不空也可以添加
	    		S.push_back(number);
	    	}
	    }
	    while(S.size() != 0 && k > 0){
    		S.pop_back();
    		k--;
    	}
	    for (int i = 0; i < S.size(); i++){
    		result.append(1, '0' + S[i]);//数字转字符
    	}
    	if (result == ""){
	    	result = "0";
	    }
    	return result;
    }
};

int main(){
	Solution solve;
	std::string result = solve.removeKdigits("1432219", 3);
	printf("%s\n", result.c_str());
	std::string result2 = solve.removeKdigits("100200", 1);
	printf("%s\n", result2.c_str());
	return 0;
}
