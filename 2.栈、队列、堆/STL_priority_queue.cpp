//STL的优先级队列就是二叉堆
#include <stdio.h>
#include <queue> // 优先级队列要include queue
int main(){
	/*
		heap.empty() 判空
		heap.pop() 弹出堆顶元素
		heap.push(x) 将x添加至堆
		heap.top() 返回堆顶元素
		heap.size() 返回堆中元素个数
	*/
	std::priority_queue<int> big_heap; // 默认构造是最大堆
	std::priority_queue<int, std::vector<int>, // 最小堆构造
					std::greater<int> > small_heap;
	std::priority_queue<int, std::vector<int>, // 最大堆构造
					std::less<int> > big_heap2;
					
	if (big_heap.empty()){
		printf("big_heap is empty!\n");
	}	
	int test[] = {6, 10, 1, 7, 99, 4, 33};
	for (int i = 0; i < 7; i++){
		big_heap.push(test[i]);
	}
	printf("big_heap.top = %d\n", big_heap.top());
	big_heap.push(1000);
	printf("big_heap.top = %d\n", big_heap.top());
	for (int i = 0; i < 3; i++){
		big_heap.pop();
	}
	printf("big_heap.top = %d\n", big_heap.top());
	printf("big_heap.size = %d\n", big_heap.size());
	return 0;
}

