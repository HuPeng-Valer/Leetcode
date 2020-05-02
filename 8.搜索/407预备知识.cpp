/*
    结构体的STL优先级队列
*/
#include <stdio.h>
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
int main(){
    std::priority_queue<Qitem, std::vector<Qitem>, cmp>Q;
    Q.push(Qitem(0,0,5));
    Q.push(Qitem(1,3,2));
    Q.push(Qitem(5,2,4));
    Q.push(Qitem(0,1,8));
    Q.push(Qitem(6,7,1));
    while(!Q.empty()){
        int x = Q.top().x;
        int y = Q.top().y;
        int h  =Q.top().h;
        printf("x=%d y=%d h=%d\n",x,y,h);
        Q.pop();
    }
    return 0;

}
