/*
	求字符串的无重复字符的最长子串的长度
	先考虑枚举：
		eg: pwwkew
			p,pw,pww,pwwk,pwwke,pwwkew
			w,ww,wwk,wwke,wwkew
			w,wk,wke,wkew
			k,ke,kew
			e,ew
			w
			注意遇到pww,ww时已近没有必要再枚举下去，因为已经出现重复
			而e,ew,w也没必要枚举，因为前面已经出现长度大于2的符合条件的子串
	思路：双指针扫描字符串的方法非常常用！！！！begin指针一定不会超过i指针，所以复杂度是O(n)
		1.设置一个记录字符数量的字符哈希char_map
		2.设置一个记录当前满足条件的最长子串变量word
		3.设置两个指针i,begin，指向字符串第一个字符
		4.设置最长满足条件的子串的长度result
		5.i指针向后逐个扫描字符串中的字符，在这个过程中使用char_map记录肌肤数量
		  如果word中没有出现过该字符，对word尾部添加字符并检查result是否需要更新
		  否则，begin指针向前移动，更新char_map中字符数量，直到字符s[i]的数量为1，更新word，将word赋值为begin与i之间的子串
		  在整个过程中，使用begin与i维护一个窗口，该窗口中的子串满足题目条件，窗口线性向前滑动，整体时间复杂度为O(n)
	
	双指针扫描字符串：
		维护两个指针之间的子串，如果子串不满足条件则修改begin
*/
#include <stdio.h>
#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
    	int begin = 0;
    	int result = 0;
    	std::string word = "";
    	int char_map[128] = {0};
    	for (int i = 0; i < s.length(); i++){
    		char_map[s[i]]++;
    		if (char_map[s[i]] == 1){
		    	word += s[i];
		    	if (result < word.length()){
	    			result = word.length();
	    		}
		    }
		    else{
    			while(begin < i && char_map[s[i]] > 1){
    				char_map[s[begin]]--;
		    		begin++;
		    	}
		    	word = "";
		    	for (int j = begin; j <= i; j++){
	    			word += s[j];
	    		}
    		}
	    }
    	return result;
    }
};

int main(){
	std::string s = "abcbadab";
	Solution solve;
	printf("%d\n", solve.lengthOfLongestSubstring(s));	
	return 0;
}
