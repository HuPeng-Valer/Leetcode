/*
    N皇后问题
    将N个皇后棋子摆在N*N棋盘，不能有摆在同行同列同对角线
    输出棋盘，每个棋盘均使用字符串向量表示



利用递归对棋盘每一行放置棋子，放置时，按列顺序寻找可以放置棋子的列，若可以放置棋子，则将棋子放在该位置，并更新mark标记数组，递归进行下一行棋子放置
当该次递归结束后，恢复mark数组，并尝试下一个可能放置棋子的列
*/
#include <vector>
#include <string>
class Solution{
public:
    std::vector<std::vector<std::string>> sloveNQueens(int n){
        std::vector<std::vector<std::string>> result;
        std::vector<std::vector<int>> mark;
        std::vector<std::string> location;//存储某一次拜访结果，当完成一次递归找到结果后，将location push进result
        for(int i=0;i<n;i++){
            mark.push_back((std::vector<int>()));
            for(int j=0;j<n;j++){
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n,'.');
        }
        generate(0,n,location,result,mark);
        return result;
    }
private:
    //在x,y位置放置棋子，更新棋盘，记录哪些位置不可再放棋子
    void put_down_the_queen(int x, int y, std::vector<std::vector<int>>& mark){
        static const int dx[] = {-1,1,0,0,-1,-1,1,1};
        static const int dy[] = {0,0,-1,1,-1,1,-1,1};
        mark[x][y] =1;//x,y放置棋子
        for(int i=1;i<mark.size();i++){
            for(int j=0;j<8;j++){
                int new_x = x+i*dx[j];
                int new_y = y+i*dy[j];
                if(new_x>=0 && new_x<mark.size() && new_y>=0 && new_y<mark.size()){
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }

    //k代表正在放第k行
    void generate(int k, int n,
                  std::vector<std::string>& location,
                  std::vector<std::vector<std::string>>& result,
                  std::vector<std::vector<int>>& mark){
        if(k==n){//从0开始的
            result.push_back(location);
            return;
        }
        for(int i=0;i<n;i++){//尝试0~n-1列
            if(mark[k][i]==0){
                std::vector<std::vector<int>> tmp_mark = mark;
                location[k][i]='Q';
                put_down_the_queen(k,i,mark);
                generate(k+1,n,location,result,mark);
                mark=tmp_mark;//执行到这表示已经回溯到这里，递归回溯问题要从中间过程开始思考
                location[k][i]='.';
            }
        }
    }
};