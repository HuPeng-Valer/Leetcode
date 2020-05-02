/*
	哈希表排序，使用数组的下标对正整数排序，哈希表的长度需要超过最大待排序数字
	这种方法只能用于正整数
	如果元素为负数，浮点数，字符串，甚至对象，就需要用哈希函数将key转换为整数再对表长取余
*/

#include <stdio.h>

int main(){
	int random[10] = {999, 1, 444, 7, 20, 9, 1, 3, 7, 7};
	int hash_map[1000] = {0};
	for (int i = 0; i < 10; i++){
		hash_map[random[i]]++;
	}	
	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < hash_map[i]; j++){
			printf("%d\n", i);
		}
	}	
	return 0;
}

