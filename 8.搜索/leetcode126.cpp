/*
    已知两个单词beginWord和endWord，一个单词词典，根据转换规则计算所有的从起始单词到结束单词的最短转换路径
    转换规则如下：
        1.一次只能转换单词中的一个字符
        2.转换得到的新单词，必须在单词词典中
    若无法转换到endWord，返回0
    所有单词长度相等
    至包含小写字符
    wordList中无重复单词
    beginWord与endWord非空，且不相同
    
    思考：
        1.在宽度优先搜索时，如何保存宽度搜索时的路径
        2.如果起始点与终点间有多条路径，如何将多条路径全部搜索出
        3.在建立beginWord和wordList的连接时，若单词表中已包含beginWord，按照127题那样建立图，会出现什么问题
    思路：
        1.将普通队列更换为vector实现队列，保存所有的搜索节点，即在pop节点时不会丢弃对头元素，只是移动front指针
        2.在队列节点中增加该节点的前驱节点在队列中的下标信息，可通过该下标找到是队列中的哪个节点搜索到当前节点
        3.到达某一位置可能存在多条路径，使用映射记录到达每个位置的最短需要步数，新拓展到的位置只要未曾到达或到达步数与最短步数相同，即
          将该位置添加到队列中，从而存储了从不同前驱到达该位置的情况
        4.从所有结果endWord所在的队列位置end_word_pos，向前遍历直到起始单词，遍历过程中，保存路径上的单词，再反过来存储到最终结果即可
*/
#include <string>
#include <vector>
#include <map>
struct Qitem{
    std::string node;
    int parent_pos;
    int step;
    Qitem(std::string node,int parent_pos, int step):node(node),parent_pos(parent_pos),step(step){}
};

bool connect(const std::string& word1, const std::string& word2){
    int cnt = 0;//记录不相同字符的个数
    for(int i=0;i<word1.length();++i){
        if(word1[i] != word2[i]){
            cnt++;
        }
    }
    return cnt == 1;
}

void construct_graph(std::string& beginWord,std::vector<std::string>& wordList,std::map<std::string,std::vector<std::string>>&graph){
    int has_begin_word = 0;//wordList中可能回有beginWord，直接将beginWord放入wordList会出现重复结果
    for(int i=0;i<wordList.size();++i){
        if(wordList[i] == beginWord){
            has_begin_word = 1;
        }
        graph[wordList[i]] = std::vector<std::string>();
    }
    for(int i=0;i<wordList.size();++i){
        for(int j=i+1;j<wordList.size();++j){
            if(connect(wordList[i],wordList[j])){
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
        if(has_begin_word == 0 && connect(beginWord,wordList[i])){
            graph[beginWord].push_back(wordList[i]);
        }
    }
}

void BFS_graph(std::string& beginWord, std::string& endWord,
               std::map<std::string,std::vector<std::string>>& graph,
               std::vector<Qitem>& Q,
               std::vector<int>& end_word_pos){
    std::map<std::string, int> visit;
    int min_step = 0;//到达endWord的最小步数
    Q.push_back(Qitem(beginWord,-1,1));//起始单词前驱为-1
    visit[beginWord] = 1;//起始单词步数为1
    int front = 0;
    while(front<Q.size()){
        const std::string& node = Q[front].node;
        int step = Q[front].step;
        if(min_step != 0 && step>min_step){//step>min_step时，代表所有到终点的路径都搜索完成,因为只需要记录最短的转换路径 
            break;
        }
        if(node == endWord){
            min_step = step;
            end_word_pos.push_back(front);
        }
        const std::vector<std::string>& neighbors = graph[node];
        for(int i=0;i<neighbors.size();++i){
            if(visit.find(neighbors[i]) == visit.end() || visit[neighbors[i]] == step+1){
                Q.push_back(Qitem(neighbors[i], front, step+1));
                visit[neighbors[i]] = step + 1;
            }
        }
        front ++;
    }
}
class Solution{
public:
    std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string>& wordList){
        std::map<std::string, std::vector<std::string>> graph;
        construct_graph(beginWord,wordList,graph);
        std::vector<Qitem> Q;
        std::vector<int> end_word_pos;
        BFS_graph(beginWord,endWord,graph,Q,end_word_pos);
        std::vector<std::vector<std::string>> result;
        for(int i=0;i<end_word_pos.size();++i){
            int pos = end_word_pos[i];
            std::vector<std::string> path;
            while(pos != -1){
                path.push_back(Q[pos].node);
                pos = Q[pos].parent_pos;
            }
            result.push_back(std::vector<std::string>());
            for(int j=path.size()-1;j>=0;--j){
                result[i].push_back(path[j]);
            }
        }
        return result;
    }
};