/*
	平面有一定数量的气球，弓箭手在x轴沿y轴方向射箭，给定气球宽度xstart<=x<=xend
	求至少需要多少弓箭手才能将全部气球打爆
	1.按左端点从小到大排序
	2.遍历气球数组，同时维护一个射击区间，在满足可以将当前气球射穿的情况下，尽可能设计更多的气球
	  每击穿一个新的气球，更新一次射击区间
	3.如果新的气球没法击穿，就增加一个弓箭手，即维护一个新的射击区间
*/

#include <stdio.h>

#include <algorithm>
#include <vector>

bool cmp(const std::pair<int, int> &a, const std::pair<int ,int> &b) {
    return a.first < b.first;
}

class Solution {
public:
    int findMinArrowShots(std::vector<std::pair<int, int> >& points) {
    	if (points.size() == 0){
	    	return 0;
	    }
    	std::sort(points.begin(), points.end(), cmp);
    	int shoot_num = 1;
    	int shoot_begin = points[0].first;
    	int shoot_end = points[0].second;
    	for (int i = 1; i < points.size(); i++){
	    	if (points[i].first <= shoot_end){
	    		shoot_begin = points[i].first;
    			if (shoot_end > points[i].second){
			    	shoot_end = points[i].second;
			    }
	    	}
	    	else{
	    		shoot_num++;
	    		shoot_begin = points[i].first;
	    		shoot_end = points[i].second;
	    	}
	    }
	    return shoot_num;
    }
};

int main(){
	std::vector<std::pair<int, int> > points;
	points.push_back(std::make_pair(10, 16));
	points.push_back(std::make_pair(2, 8));
	points.push_back(std::make_pair(1, 6));
	points.push_back(std::make_pair(7, 12));	
	Solution solve;
	printf("%d\n", solve.findMinArrowShots(points));
	return 0;
}
