/*
	一条公路的起点和终点之间有n个加油站，已知n个加油站到终点的距离，各个加油站可以加油的量
	起点到终点的距离，起始时刻油箱中的汽油量，假设1个单位的汽油走可以走一个单位的距离
	油箱没有加油上限，求最少加几次油可以从起点开到终点，如果无法达到终点则返回-1
	思想：
		类似45题，以在能不跳之前都不跳为基础构建贪心算法
		这题在能不加油前都不加油，区别是45题只要在一个位置选择跳跃就行，这题在不能继续向前走时，
		可能需要在前面多个加油站加油
	算法：
		1.设置一个最大堆，存储经过的加油站的汽油量
		2.按照从起点至终点的方向，遍历各个加油站之间的距离
		3.每次需要走两个加油站之间的距离d，如果发现汽油不够走距离d时，从最大堆中去除一个油量添加，直到可以走距离d
		4.如果把最大堆的汽油都添加仍然不够走d，则无法达到终点
		5.当前油量P减少d
		6.将当前加油站油量添加至最大堆
*/

#include <stdio.h>

#include <vector>
#include <algorithm>
#include <queue>

bool cmp(const std::pair<int, int> &a, const std::pair<int ,int> &b) {
    return a.first > b.first;
}

//L为起到到终点的距离，P为初始汽油量，pair<加油站到终点的距离，加油站汽油量>
int get_minimum_stop(int L, int P, std::vector<std::pair<int, int> > &stop){
	std::priority_queue<int> Q;
	int result = 0;
	stop.push_back(std::make_pair(0, 0));//需要把终点也作为一个停靠点，添加到stop数组
	std::sort(stop.begin(), stop.end(), cmp);
	for (int i = 0; i < stop.size(); i++){
		int dis = L - stop[i].first;
		while (!Q.empty() && P < dis){
			P += Q.top();
			Q.pop();
			result++;
		}
		if (Q.empty() && P < dis){
			return -1;
		}
		P = P - dis;
		L = stop[i].first;
		Q.push(stop[i].second);
	}
	return result;
}

int main(){
	std::vector<std::pair<int, int> > stop;
	int N;
	int L;
	int P;
	int distance;
	int fuel;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d %d", &distance, &fuel);
		stop.push_back(std::make_pair(distance, fuel));
	}
	scanf("%d %d", &L, &P);
	printf("%d\n", get_minimum_stop(L, P, stop));
	return 0;
}
