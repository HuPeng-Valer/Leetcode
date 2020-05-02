/*
	已知字符串S和字符串T，求在S中的最小区间，使得这个区间中包含了字符串T中的所有字符
	eg:
		S="ADOBECODEBANC",T="ABC"
		包含T的子区间有 "ADOBEC","CODEBA","BANC",最小的是"BANC"
	思路：
		1.设置两个字符哈希数组，map_s与map_t，map_s代表当前处理的窗口区间中的字符数量，map_t代表子串T的字符数量
		2.设置两个指针i,begin，指向字符串第一个字符
		3.i指针向后逐个扫描字符串中的字符，在这个过程中，循环检查begin指针是否可以向前移动
		  如果当前begin指向的字符T中没有出现，直接前移begin
		  如果begin指向的字符T中出现了，但是当前区间窗口中的该字符数量足够，向前移动begin（因为要最短子串），并更新map_s
		  否则不能移动begin，跳出检查
		4.指针i每向前扫描一个字符，即检查一下是否可以更新最终结果（找到最小的包含T中各个字符的窗口）
		  在整个过程中，使用begin与i维护一个窗口，该窗口中的子串满足题目条件，窗口线性向前滑动，整体复杂度为O(n)
*/
#include <stdio.h>

#include <string>
#include <vector>

class Solution {
private:
	bool is_window_ok(int map_s[], int map_t[], std::vector<int> &vec_t){
    	for (int i = 0; i < vec_t.size(); i++){
    		if (map_s[vec_t[i]] < map_t[vec_t[i]]){
		    	return false;
		    }
	    }
	    return true;
    }
public:
    std::string minWindow(std::string s, std::string t) {
        const int MAX_ARRAY_LEN = 128;
        int map_t[MAX_ARRAY_LEN] = {0};
        int map_s[MAX_ARRAY_LEN] = {0};
        std::vector<int> vec_t;
        for (int i = 0; i < t.length(); i++){
        	map_t[t[i]]++;
        }
        for (int i = 0; i < MAX_ARRAY_LEN; i++){
        	if (map_t[i] > 0){
	        	vec_t.push_back(i);
	        }
        }
        
        int window_begin = 0;
        std::string result;
        for (int i = 0; i < s.length(); i++){
        	map_s[s[i]]++;
        	while(window_begin < i){
        		char begin_ch = s[window_begin];
	        	if (map_t[begin_ch] == 0){
	        		window_begin++;
	        	}
	        	else if	(map_s[begin_ch] > map_t[begin_ch]){
	        		map_s[begin_ch]--;
	        		window_begin++;
	        	}
	        	else{
	        		break;
	        	}
	        }
	        if (is_window_ok(map_s, map_t, vec_t)){
        		int new_window_len = i - window_begin + 1;
        		if (result == "" || result.length() > new_window_len){
		        	result = s.substr(window_begin, new_window_len);
				}
        	}
        }
        return result;
    }
};

int main(){
	
	Solution solve;
	std::string result = solve.minWindow("ADOBECODEBANC", "ABC");
	printf("%s\n", result.c_str());
	result = solve.minWindow("MADOBCCABEC", "ABCC");
	printf("%s\n", result.c_str());
	result = solve.minWindow("aa", "aa");
	printf("%s\n", result.c_str());
	
	return 0;	
}
