/*
	统计字符串中每个字符出现的次数
*/

#include <stdio.h>
#include <string>

int main(){
	int char_map[128] = {0};//ASCII码0-127
	std::string str = "abcdefgaaxxy";
	
	for (int i = 0; i < str.length(); i++){
		char_map[str[i]]++;
	}
	
	for (int i = 0; i < 128; i++){
		if (char_map[i] > 0){
			printf("[%c][%d] : %d\n", i, i, char_map[i]);
		}
	}
	return 0;
}

