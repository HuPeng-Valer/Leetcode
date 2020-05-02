/*
    Hard
    已知一个m*n的二维数组，数组存储正整数，代表一个个单元的高度（长方体），将这些长方体想象称水槽，问：
    如果下雨会有多少积水

    思路：
        1.搜索队列使用优先级队列，越低矮的点优先级越高（最小堆），越优先进行搜索，这样不用担心水会从其他地方流出去
        2.以矩形四周的点作为起始点进行广度优先搜索（要push进队列）
        3.使用一个二维数组对push进入队列的点进行标记，之后搜索到该点后，不再push到队列中
        4.只要优先级队列不空，即取出优先级队列队头元素进行搜索，按照上下左右四个方向进行拓展，拓展过程中忽略超出边界与已入队列的点
        5.当对某点（x,y,h)进行拓展时：
            得到的新点为（newx,newy），高度为heightMap[newx][newy]
            如果h大于heightMap[newx][newy]：
                最终结果+= h-heightMap[newx][newy]
                将heightMap[newx][newy]赋值为h
            将（newx,newxy,heightMap[newx][newy]）push进入优先级队列，并作标记
*/
#include <vector>
#include <queue>
struct Qitem{
    int x;
    int y;
    int h;
    Qitem(int x,int y, int h):x(x),y(y),h(h){}
};
struct cmp{
    bool operator()(const Qitem& a,const Qitem& b){
        return a.h>b.h;
    }
};
class Solution{
public:
    int trapRainWater(std::vector<std::vector<int>>& heightMap){
        std::priority_queue<Qitem,std::vector<Qitem>,cmp> Q;
        if(heightMap.size()<3 || heightMap[0].size()<3){
            return 0;
        }
        int row = heightMap.size();
        int column = heightMap[0].size();
        std::vector<std::vector<int>> mark;//思考mark的作用，一个被mark后的地方不可能再继续积水，因为搜索是从小到大的，如果再有积水过来一定会流出
        for(int i=0;i<row;++i){
            mark.push_back(std::vector<int>());
            for(int j=0; j<column; ++j){
                mark[i].push_back(0);
            }
        }
        for(int i=0;i<row;++i){
            Q.push(Qitem(i,0,heightMap[i][0]));
            mark[i][0] = 1;
            Q.push(Qitem(i,column-1,heightMap[i][column-1]));
            mark[i][column-1] = 1;
        }
        for(int i=1;i<column-1;++i){
            Q.push(Qitem(0,i,heightMap[0][i]));
            mark[0][i] = 1;
            Q.push(Qitem(row-1,i,heightMap[row-1][i]));
            mark[row-1][i] = 1;
        }

        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,-1,1};
        int result = 0;
        while(!Q.empty()){
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            for(int i=0;i<4;++i){
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx<0 || newx >=row || newy<0 || newy>=column || mark[newx][newy]){
                    continue;
                }
                if(h>heightMap[newx][newy]){
                    result += (h-heightMap[newx][newy]);
                    heightMap[newx][newy] = h;
                }
                Q.push(Qitem(newx,newy,heightMap[newx][newy]));
                mark[newx][newy] = 1;
            }

        }
        return result;
    }
};