#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
void get_num(int i,vector<vector<int>>& graph,vector<int>& visit, int& max){
    if(visit[i] == 1){
        return;
    }
    queue<int> Q;
    Q.push(i);
    visit[i] =1;
    int num =1;
    while(!Q.empty()){
        Q.pop();
        for(int j=0;j<graph[i].size();++j){
            if(visit[graph[i][j]] == 0){
                Q.push(graph[i][j]);
                num ++;
                visit[graph[i][j]] =1;
            }
        }
    }
    if(max<num){
        max = num;
    }
    

}
int main(){
    int T;
    cin>>T;
    while(T){
        vector<vector<int>> graph(10,vector<int>());
        vector<int> visit(10,0);
        int n;
        cin>>n;
        while(n){
            int x,y;
            cin>>x>>y;
            graph[x-1].push_back(y-1);
            graph[y-1].push_back(x-1);
            --n;
        }
        int max=1;
        for(int i=0;i<10;++i){
            get_num(i,graph,visit,max);
        }
        cout<<max<<endl;
        --T;
    }

    return 0;
}