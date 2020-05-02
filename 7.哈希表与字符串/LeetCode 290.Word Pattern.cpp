/*
	已知字符串pattern与字符串str，确认str是否与pattern匹配，str与pattern匹配表示字符串str中的单词与
	pattern中的字符一一对应，pattern中只包含小写字符，str中的单词只包含小写字符，使用空格分隔
	eg：
		pattern="abba", str=" dog cat cat dog"匹配
		pattern="abba", str="dog cat cat fish"不匹配
*/

#include <stdio.h>
#include <string>
#include <map>
class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
    	std::map<std::string, char> word_map;
    	char used[128] = {0};
    	std::string word;
    	int pos = 0;
    	str.push_back(' ');
    	for (int i = 0; i < str.length(); i++){
	    	if (str[i] == ' '){
	    		if (pos == pattern.length()){//分割出一个单词，pattern不够长
	    			return false;
		    	}
	    		if (word_map.find(word) == word_map.end()){
	    			if (used[pattern[pos]]){
			    		return false;
			    	}
		    		word_map[word] = pattern[pos];
		    		used[pattern[pos]] = 1;
		    	}
		    	else{
	    			if (word_map[word] != pattern[pos]){
			    		return false;
			    	}
	    		}
	    		word = "";
	    		pos++;
	    	}
	    	else{
	    		word += str[i];
	    	}
	    }
	    if (pos != pattern.length()){//有多余的pattern字符
    		return false;
    	}
        return true;
    }
};

int main(){
	std::string pattern = "abba";
	std::string str = "dog cat cat dog";
	Solution solve;
	printf("%d\n", solve.wordPattern(pattern, str));
	return 0;
}
