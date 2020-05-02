#include <iostream>
#include <stack>
class BTree{
public:
    int val;
    BTree* lchild,* rchild;
    // BTree():val(0),lchild(NULL),rchild(NULL){}
    BTree(int val, BTree* lchild, BTree* rchild):val(val),lchild(NULL),rchild(NULL){}
};

void PreOrder(BTree* &T){
    std::stack<BTree*> s;
    BTree* p = T;
    while(p || !s.empty()){
        while(p){
            std::cout<<p->val<<std::endl;
            s.push(p);
            p = p->lchild;
        }
        if(!s.empty()){
            p = s.top()->rchild;
            s.pop();
        }
    }
}

void InOrder(BTree* &T){
    std::stack<BTree*> s;
    BTree* p = T;
    while(p || !s.empty()){
        while(p){
            s.push(p);
            p = p->lchild;
        }
        if(!s.empty()){
            std::cout<<s.top()->val<<std::endl;
            p = s.top()->rchild;
            s.pop();
        }
    }
}

class Flag_BTree{
public:
    BTree* T;
    int flag;
    Flag_BTree(){
        T=NULL;
        flag = 0;
    }
    Flag_BTree(BTree* T,int flag):T(T),flag(flag){}
};
void PostOrder(BTree* T){
    std::stack<Flag_BTree> s;
    BTree* p = T;
    while(p || !s.empty()){
        while(p){
            Flag_BTree temp = Flag_BTree(p,0);
            s.push(temp);
            p = p->lchild;
        }
        while(!s.empty() && s.top().flag==1){
            std::cout<<s.top().T->val<<std::endl;
            p = NULL;    //这里极其重要，无论这里p为多少都没关系，因为直到flag==0的点出现前都要弹栈，而一旦出现flag==0,p就会重新赋值，但是如果不设为NULL，栈空后最外层循环就不会停下来
            s.pop();
        }
        if(!s.empty()){
            s.top().flag=1;
            p = s.top().T->rchild;
        }
    }
}

int main(){
    BTree* t1 = new BTree(1,NULL,NULL);
    BTree* t2 = new BTree(2,NULL,NULL);
    BTree* t3 = new BTree(3,NULL,NULL);
    BTree* t4 = new BTree(4,NULL,NULL);
    BTree* t5 = new BTree(5,NULL,NULL);
    BTree* t6 = new BTree(6,NULL,NULL);
    BTree* t7 = new BTree(7,NULL,NULL);

    t1->lchild = t2;
    t1->rchild = t3;
    t2->lchild = t4;
    t2->rchild = t5;
    t5->lchild = t6;
    t5->rchild = t7;
    PostOrder(t1);

    return 0;
}