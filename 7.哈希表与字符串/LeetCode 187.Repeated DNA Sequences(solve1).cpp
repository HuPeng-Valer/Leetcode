/*
	将DNA序列看作只包含A,C,G,T4个字符的字符串，给定一个DNA字符串，找到所有长度为10且出现超过1次的子串
	思路1：
		枚举所有长度为10的子串，将其插入到哈希map中，并记录子串数量，遍历哈希map，将所有出现超过1次的子串存储到结果中
		算法复杂度为O(n)
*/
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    	std::map<std::string, int> word_map;
    	std::vector<std::string> result;
    	for (int i = 0; i < s.length(); i++){
    		std::string word = s.substr(i, 10);
	    	if (word_map.find(word) != word_map.end()){
	    		word_map[word] += 1;
	    	}
	    	else{
	    		word_map[word] = 1;
	    	}
	    }
	    std::map<std::string, int> ::iterator it;
	    for (it = word_map.begin(); it != word_map.end(); it++){
    		if (it->second > 1){
		    	result.push_back(it->first);
		    }
    	}
    	return result;
    }
};

int main(){
	std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution solve;
	std::vector<std::string> result = solve.findRepeatedDnaSequences(s);
	for (int i = 0; i < result.size(); i++){
		printf("%s\n", result[i].c_str());
	}
	return 0;
}
