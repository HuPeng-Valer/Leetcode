/*
	已知一组字符串，将所有由颠倒字母顺序而构成的字放到一起输出
	eg:
		["eat","tea","ate"]是一组
	关键是将一组的单词映射到一个key下

	思路：
		设置字符串到字符串向量的哈希表anagram，遍历字符串向量strs中的单词strs[i]
			1.设置临时变量str=strs[i]，对str进行排序
			2.若str未出现在anagram中，设置str到一个空字符串向量的映射
			3.将strs[i]添加到字符串向量anagram[str]中
		遍历哈希表anagram，将全部key对应的value push到最终结果中
*/

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string> > groupAnagrams(
			std::vector<std::string>& strs) {
		std::map<std::string, std::vector<std::string> > anagram;
		std::vector<std::vector<std::string> > result;		
		for (int i = 0; i < strs.size(); i++){
			std::string str = strs[i];
			std::sort(str.begin(), str.end());
			if (anagram.find(str) == anagram.end()){
				std::vector<std::string> item;//需要初始化
				anagram[str] = item;
			}
			anagram[str].push_back(strs[i]);
		}
		std::map<std::string, std::vector<std::string> > ::iterator it;
		for (it = anagram.begin(); it != anagram.end(); it++){
			result.push_back((*it).second);
		}
    	return result;
    }
};

int main(){
	std::vector<std::string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	Solution solve;
	std::vector<std::vector<std::string> > result 
		= solve.groupAnagrams(strs);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			printf("[%s]", result[i][j].c_str());
		}
		printf("\n");
	}	
	return 0;
}
