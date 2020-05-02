/*
    已知n组括号，生成这n组括号所有可能的合法的组合
*/
/*
预备知识：实现所有可能情况，括号不一定对称
#include <stdio.h>
#include <vector>
#include <string>

void generate(std::string item, int n, std::vector<std::string>& result){ //item为用来生成的括号字符串，n为组数，result为最终结果
    if(item.size()==2*n){
        result.push_back(item);
        return;
    }
    generate(item+'(', n, result);
    generate(item+')', n, result);
}

int main(){
    std::vector<std::string> result;
    generate("",2,result);
    for(int i=0;i<result.size();i++){
        printf("'%s'\n",result[i].c_str());
    }
    return 0;
}
在所有合法可能中，左右括号一定不超过n,右括号不可先于左括号放置
若左括号的数量<=右括号的数量，则不能放置右括号
*/

#include <string>
#include <vector>
class Solution{
public:
    std::vector<std::string> generateParenthesis(int n){
        std::vector<std::string> result;
        generate("", n, n, result);
        return result;
    }
private:
    void generate(std::string item, int left, int right, std::vector<std::string>& result){
        if(left==0 && right==0){
            result.push_back(item);
            return;
        }
        if(left>0){
            generate(item+'(', left-1, right, result);
        }
        if(left<right){
            generate(item+')', left, right-1, result);
        }
    }
};
/*
""-> ( -> ( -> ) -> )
       -> ) -> ( -> )
*/