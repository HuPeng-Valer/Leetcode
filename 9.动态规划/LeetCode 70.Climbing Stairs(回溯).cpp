/*
	在爬楼梯时，每次可向上走1阶或2阶，问n阶楼梯有多少种上楼方式
*/
#include <stdio.h>
class Solution {
public:
    int climbStairs(int n) {
    	if (n == 1 || n == 2){
			return n;
		}
	    return climbStairs(n-1) + climbStairs(n-2);//暴力递归会超时
    }
};

int main(){
	Solution solve;
	printf("%d\n", solve.climbStairs(3));	
	return 0;
}
