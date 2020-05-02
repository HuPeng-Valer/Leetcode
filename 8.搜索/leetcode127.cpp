/*
    已知两个单词beginWord,endWord,一个单词词典，根据转换规则计算从beginWord到endWord的最短转换步数，转换规则如下：
        1.在转换时，只能转换单词中的一个字符
        2.转换得到的新单词，必须在单词词典中
    若无法转换，则返回0；所有单词长度相同；只包含小写字符；单词词典中无重复单词；befinWord与endWord非空，且不相同
    思路：
        单词与单词之间的转换可以理解为一张图，图的顶点为单词，若两单词之间可以互相转换，则这两单词所代表的顶点之间有一条边
        求图中节点到节点的所有路径中，最少包括多少个节点，即图的宽度优先搜索
    将beginWord加入词典，遍历词典，对任意两个单词，若只相差一个字符，则将其相连，使用map创建邻接表
    给定图的起点beginWord，终点endWord，图graph，从beginWord开始宽度优先搜索图graph，搜索过程中记录到达步数
        1.设置搜索队列Q，队列节点为pair<顶点，步数>，设置集合visit，记录搜索过的顶点，将<beginWord,1>添加至队列
        2.只要队列不空，取出队列头部元素
            a.若取出的队列头部元素为endWord，返回到达当前节点的步数
            b.否则拓展该节点，将与该节点相邻的且未添加到visit的节点与步数同时添加到Q，并将拓展节点加入visit
            c.若最终无法搜索到endWord，返回0
*/
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
bool connect(const std::string& word1, const std::string& word2){
    int cnt = 0;//记录不相同字符的个数
    for(int i=0;i<word1.length();++i){
        if(word1[i] != word2[i]){
            cnt++;
        }
    }
    return cnt == 1;
}

void construct_graph(std::string& beginWord, std::vector<std::string>& wordList,
                     std::map<std::string,std::vector<std::string>>& graph){
    wordList.push_back(beginWord);
    for(int i=0;i<wordList.size();++i){
        graph[wordList[i]] = std::vector<std::string>();
    }
    for(int i=0;i<wordList.size();++i){
        for(int j=i+1;j<wordList.size();++j){
            if(connect(wordList[i],wordList[j])){
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
    }
                
}

int BFS_graph(std::string& beginWord, std::string& endWord, std::map<std::string,std::vector<std::string>>& graph){
    std::queue<std::pair<std::string, int>> Q;
    std::set<std::string> visit;
    Q.push(std::make_pair(beginWord,1));
    visit.insert(beginWord);
    while(!Q.empty()){
        std::string node = Q.front().first;
        int step = Q.front().second;
        Q.pop();
        if(node == endWord){
            return step;
        }
        const std::vector<std::string>& neighbors = graph[node];
        for(int i=0;i<neighbors.size();++i){
            if(visit.find(neighbors[i]) == visit.end()){
                Q.push(std::make_pair(neighbors[i],step+1));
                visit.insert(neighbors[i]);
            }
        }
    }
}