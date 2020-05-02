/*
	已知一个只包含大小写字符的字符串，求用该字符串中的字符可以生成的最长回文字符串长度
	回文：从左到右和从右到左相同
*/

#include <stdio.h>
#include <string>

class Solution {
public:
    int longestPalindrome(std::string s) {
    	int char_map[128] = {0};
    	int max_length = 0;
    	int flag = 0;
    	for (int i = 0; i < s.length(); i++){
	    	char_map[s[i]]++;
	    }
	    for (int i = 0; i < 128; i++){
    		if (char_map[i] % 2 == 0){
		    	max_length += char_map[i];
		    }
		    else{
    			max_length += char_map[i] - 1;
    			flag = 1;
    		}
    	}
    	return max_length + flag;
    }
};

int main(){
	std::string s = "abccccddaa";
	Solution solve;
	printf("%d\n", solve.longestPalindrome(s));
	return 0;
}
