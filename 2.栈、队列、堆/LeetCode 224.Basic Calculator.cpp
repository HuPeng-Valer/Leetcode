/*
	实现计算器，输入字符串的数学表达式，计算包括(,),+,-四种符号的数学表达式
	输入的数学表达式可能有空格
	使用数字栈和操作符栈
	使用变量compute_flag记录是否可以计算
	当遇到+-就可以计算，compute_flag=1
	当遇到(就不可以计算，compute_flag=1
	字符串处理思路：状态机
		初始状态为STATE_BEGIN,遇到数字则转为NUMBER_STATE,遇到操作符则转为OPERATION_STATE
	在NUMBER_STATE：
		如果遇到数字：
			number = number*10 + ch -'0'
		否则：
			number入数字栈，根据computer_flag进行计算，并切换值OPERATION_STATE,并将字符指针退i格
	在OPERATION_STATE:
		如果+-：
			操作符入栈，compute_flag=1
		如果(:
			compute_flag=0
			切换到NUMBER_STATE
		如果):
			计算
		如果数字：
			切换到NUMBER_STATE
			字符指针退格

*/
#include <stdio.h>

#include <string>
#include <stack>

class Solution {
public:
    int calculate(std::string s) {
    	static const int STATE_BEGIN = 0;
    	static const int NUMBER_STATE = 1;
    	static const int OPERATION_STATE = 2;
        std::stack<int> number_stack;
        std::stack<char> operation_stack;
        int number = 0;
        int STATE = STATE_BEGIN;
        int compuate_flag = 0;
        for (int i = 0; i < s.length(); i++){
        	if (s[i] == ' '){
	        	continue;
	        }
	        switch(STATE){
        	case STATE_BEGIN:
        		if (s[i] >= '0' && s[i] <= '9'){
        			STATE = NUMBER_STATE;
				}
				else{
					STATE = OPERATION_STATE;
				}
				i--;
				break;
       		case NUMBER_STATE:
			  	if (s[i] >= '0' && s[i] <= '9'){
	  				number = number * 10 + s[i] - '0';
	    		}
	    		else{
	    			number_stack.push(number);
	    			if (compuate_flag == 1){
			    		compute(number_stack, operation_stack);
			    	}
	    			number = 0;
	    			i--;
	    			STATE = OPERATION_STATE;
	       		}
      			break;
  			case OPERATION_STATE:
  				if (s[i] == '+' || s[i] == '-'){
  					operation_stack.push(s[i]);
  					compuate_flag = 1;
			  	}
			  	else if (s[i] == '('){
	  				STATE = NUMBER_STATE;
	  				compuate_flag = 0;
	  			}
	  			else if (s[i] >= '0' && s[i] <= '9'){
			  		STATE = NUMBER_STATE;			  		
			  		i--;
			  	}
			  	else if (s[i] == ')'){
			  		compute(number_stack, operation_stack);
	  			}
  				break;
        	}
        }
        if (number != 0){
        	number_stack.push(number);
       		compute(number_stack, operation_stack);
        }
        if (number == 0 && number_stack.empty()){
        	return 0;
        }
        return number_stack.top();
    }
private:
	void compute(std::stack<int> &number_stack,
				 std::stack<char> &operation_stack){
		if (number_stack.size() < 2){
			return;
		}
		int num2 = number_stack.top();
		number_stack.pop();
		int num1 = number_stack.top();
		number_stack.pop();
		if (operation_stack.top() == '+'){
			number_stack.push(num1 + num2);
		}
		else if(operation_stack.top() == '-'){
			number_stack.push(num1 - num2);
		}
		operation_stack.pop();
	}
};

int main(){	
	std::string s = "1+121 - (14+(5-6) )";
	Solution solve;
	printf("%d\n", solve.calculate(s));
	return 0;
}
