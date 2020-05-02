/*
	设计一个数据结构，支持如下两个操作：
		1.添加单词：addWord(word)
		2.搜索单词：bool search(word)
	搜索单词时，可以按照普通的方式搜索单词，或正则表达式的方式搜索单词，添加的单词只包含小写字符a-z，
	搜索时，只包含小写字符'a'-'z'或'.'
	'.'表示任意一个小写字符
*/

#include <stdio.h>
#include <vector>
#define TRIE_MAX_CHAR_NUM 26

struct TrieNode{
	TrieNode *child[TRIE_MAX_CHAR_NUM];
	bool is_end;
	TrieNode() : is_end(false){
		for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
			child[i] = 0;
		}
	}
};

class TrieTree{
public:
	TrieTree(){
	}
	~TrieTree(){
		for (int i = 0; i < _node_vec.size(); i++){
			delete _node_vec[i];
		}
	}
	void insert(const char *word) {
		TrieNode *ptr = &_root;
        while(*word){
        	int pos = *word - 'a';
        	if (!ptr->child[pos]){
	        	ptr->child[pos] = new_node();
	        }
	        ptr = ptr->child[pos];
        	word++;
        }
        ptr->is_end = true;
    }
    TrieNode *root(){
    	return &_root;
    }
private:
	TrieNode *new_node(){
		TrieNode *node = new TrieNode();
		_node_vec.push_back(node);
		return node;
	}
	std::vector<TrieNode *> _node_vec;
	TrieNode _root;
};
/*
	node为正在搜索的节点，word指向正在搜索的单词起始，查找成功返回真，否则返回假
	当遍历到单词结束时（word指向'\0'):
		如果node指向的节点标记为单词的结尾：
			返回真
		否则返回假
	如果word指向'.':
		遍历node的全部孩子指针：
			如果孩子指针为真，继续递归深搜该孩子子树，单词指针向前移动一个位置，
				如果递归深搜结果为真，则返回真
	否则'a'-'z':
		计算孩子位置pos=当前字符-'a'
		如果pos指向的孩子指针为真，继续递归深搜该孩子子树，单词指针向前移动一个位置，
			如果递归深搜结果为真，则返回真
	最终返回假
*/
bool search_trie(TrieNode *node, const char *word){
	if (*word == '\0'){
		if (node->is_end){//正是因为相等才会进入到这一层，所以只需要判断node->is_end即可，不再需要判断最后的字符是否相等
			return true;
		}
		return false;
	}
	if (*word == '.'){
		for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
			if (node->child[i] && 
				search_trie(node->child[i], word + 1)){
				return true;
			}
		}
	}
	else{
		int pos = *word - 'a';
		if (node->child[pos] && 
			search_trie(node->child[pos], word + 1)){
			return true;
		}
	}
	return false;
}

#include <string>

class WordDictionary {
public:
    WordDictionary() {
    }
    void addWord(std::string word) {
        _trie_tree.insert(word.c_str());
    }
    bool search(std::string word) {
        return search_trie(_trie_tree.root(), word.c_str());
    }
private:
	TrieTree _trie_tree;
};

int main(){
	WordDictionary word_dictionary;
	word_dictionary.addWord("bad");
	word_dictionary.addWord("dad");
	word_dictionary.addWord("mad");
	printf("%d\n", word_dictionary.search("pad"));
	printf("%d\n", word_dictionary.search("bad"));
	printf("%d\n", word_dictionary.search(".ad"));
	printf("%d\n", word_dictionary.search("b.."));
	return 0;
}
