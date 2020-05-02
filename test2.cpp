#include<iostream>
#include<vector>
#include<list>
using namespace std;

void op1(int op1, int op2, vector<list<int>>& m_set){
    int X;
    int Y;
    int m;
    m=op1>op2?op1:op2;
    for(int i=1;i<=m;++i){
        for(list<int>::iterator it=m_set[i].begin();it!=m_set[i].end();++it){
            if(*it == op1){
                X = i;
            }
            if(*it == op2){
                Y = i;
            }
        }
    }
    if(X==Y){
        return;
    }
    else{
        int k = X>Y?X:Y;
        int m = X<Y?X:Y;
        while(m_set[k].size()>0){
            m_set[m].push_back(m_set[k].front());
            m_set[k].pop_front();
        }
    }
    return;
}
void op2(int op,vector<list<int>>& m_set){
    int X;
    for(int i=1;i<=op;++i){
        for(list<int>::iterator it = m_set[i].begin();it!=m_set[i].end();++it){
            if(*it == op){
                X=i;
            }
        }
    }
    if(m_set[X].size()==1){
        return;
    }
    else{
        if(X == op){
            int temp = *(++m_set[X].begin());
            list<int>::iterator it = ++m_set[X].begin();
            while(it!=m_set[X].end()){
                m_set[temp].push_back(*it);
                it = m_set[X].erase(it);
            }
            m_set[temp].sort();
        }
        else{
            m_set[X].remove(op);
            m_set[op].push_front(op);
        }
    }
    return;
}
void op3(int op,vector<list<int>>& m_set){
    int X;
    for(int i=1;i<=op;++i){
        for(list<int>::iterator it = m_set[i].begin();it!=m_set[i].end();++it){
            if(*it == op){
                X=i;
            }
        }
    }
    cout<<m_set[X].size()<<endl;
    return;
}
int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;++t){
        int N;//正整数个数
        int M;
        cin>>N>>M;
        vector<list<int>> m_set;
        list<int> a;
        a.push_back(0);
        m_set.push_back(a);
        for(int i=1;i<=N;++i){
            list<int> tmp;
            tmp.push_back(i);
            m_set.push_back(tmp);
        }
        for(int i=0;i<M;++i){
            int op;
            cin>>op;
            if(op==1){
                int num1;
                int num2;
                cin>>num1>>num2;
                op1(num1,num2,m_set);
            }
            else{
                int num;
                cin>>num;
                if(op==2){
                    op2(num,m_set);
                }
                else if(op==3){
                    op3(num,m_set);
                }
            }
        }
    }
}