/*
	已知一组字符串，将所有由颠倒字母顺序而构成的字放到一起输出
	eg:
		["eat","tea","ate"]是一组
	关键是将一组的单词映射到一个key下
	思路：
		哈希表以26个字母的字符数量为key，以字符串向量为value，存储各个字符数量相同的字符串
*/
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

void change_to_vector(std::string &str, std::vector<int> &vec){
	for (int i = 0; i < 26; i++){
		vec.push_back(0);
	}
	for (int i = 0; i < str.length(); i++){
		vec[str[i]-'a']++;
	}
}

class Solution {
public:
    std::vector<std::vector<std::string> > groupAnagrams(
			std::vector<std::string>& strs) {
		std::map<std::vector<int>, std::vector<std::string> > anagram;
		std::vector<std::vector<std::string> > result;		
		for (int i = 0; i < strs.size(); i++){
			std::vector<int> vec;
			change_to_vector(strs[i], vec);
			if (anagram.find(vec) == anagram.end()){
				std::vector<std::string> item;
				anagram[vec] = item;
			}
			anagram[vec].push_back(strs[i]);
		}
		std::map<std::vector<int>,
			std::vector<std::string> > ::iterator it;
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
	std::vector<std::vector<std::string> > result = solve.groupAnagrams(strs);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			printf("[%s]", result[i][j].c_str());
		}
		printf("\n");
	}	
	return 0;
}
