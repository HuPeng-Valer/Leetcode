/*
    用一个二维数组代表一张地图，这张地图由字符"0"与字符"1"组成，0字符代表水域，1字符代表小岛土地，小岛1被水域0包围，当小岛土地1在水平和垂直方向
    相连接时，认为时同一块土地，求这张地图中小岛的数量
    思考：
        给定二维数组地图grid与一个二维标记数组mark（初始化为0），mark数组的每个位置斗鱼grid对应，设计一个搜索算法，从该地图中的某个岛的某个位置
        出发，探索该岛的全部土地，将探索到的位置在mark数组中标记为1
        
        思路1：DFS
            1.标记当前搜索位置已被搜索（标记当前位置的mark数组为1）
            2.按照方向数组的4个方向，拓展4个新位置newx,newy
            3.若新位置不在地图范围内，则忽略
            4.如果新位置未曾到达过（mark[newx][newy]为0），且是陆地（grid[newx][newy]为1），继续DFS该位置
        
        思路2：BFS
            1.设置搜索队列Q，标记mark[x][y] = 1,并将待搜索的位置(x,y)push进入队列Q
            2.只要队列不空，即取队头元素，按照方向数组的4个方向，拓展4个新位置newx，newy
            3.若新位置不在地图范围内，则忽略
            4.如果新位置未曾到达过（mark[newx][newy]为0），且是陆地（gird[newx][newy]为'1'），将该新位置push进入队列，并标记mark[newx][newy]=1
    求地图中岛屿的数量：
        1.设置岛屿数量island_num = 0
        2.设置mark数组，并输出化
        3.遍历地图grid上的所有点，如果当前点是陆地，且未被访问过，调用搜索接口，搜索可以是DFS或BFS，完成搜索后island_num++

*/
#include <vector>
void DFS(std::vector<std::vector<int>>& mark, std::vector<std::vector<char>>& grid, int x ,int y){
    mark[x][y] = 1;//如果确定搜索(x,y)那这一点一定是可以搜索的！！
    static const int dx[] = {-1,1,0,0};
    static const int dy[] = {0,0,-1,1};
    for(int i = 0; i<4; ++i){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx<0 || newx >= mark.size() || newy <0 || newy >= mark[newx].size()){
            continue;
        }
        if(mark[newx][newy] != 1 && grid[newx][newy] =='1'){
            DFS(mark, grid, newx, newy);
        }
    }
}

#include <queue>
void BFS(std::vector<std::vector<int>>& mark, std::vector<std::vector<char>>& grid, int x ,int y){
    static const int dx[] = {-1,1,0,0};
    static const int dy[] = {0,0,-1,1};
    std::queue<std::pair<int,int>> Q;
    Q.push(std::make_pair(x,y));
    mark[x][y] = 1;
    while(!Q.empty()){
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        for(int i=0;i<4;++i){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx<0 || newx>=mark.size() || newy<0 || newy>=mark[newx].size()){
                continue;
            }
            if(mark[newx][newy] == 0 && grid[newx][newy]=='1'){
                Q.push(std::make_pair(newx,newy));
                mark[newx][newy] = 1;
            }
        }
    }
}

class Solution{
public:
    int numIslands(std::vector<std::vector<char>>& grid){
        int island_num = 0;
        std::vector<std::vector<int>> mark;
        for(int i=0;i<grid.size();++i){
            mark.push_back(std::vector<int>());//加了()说明是对象，直接vector<int> vec;，则vec只是声明了而已
            for(int j=0;j<grid[i].size();++j){
                mark[i].push_back(0);
            }
        }
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j] == '1' && mark[i][j]==0){
                    DFS(mark,grid,i,j);
                    island_num++;
                }
            }
        }
        return island_num;
    }
};