/*
	Trie树，也称字典树或前缀树，是一种有序的，用于统计排序和存储字符串的数据结构，它与二叉查找树不同，关键字不是直接保存在节点中，而是由
	节点在树中的位置决定。
	一个节点的所有子孙都有相同的前缀，也就是这个节点对应的字符串，而根节点对应空字符串。一般情况下，不是所有的节点都有对应的值，只有叶子节点和
	部分内部节点所对应的键才有相关的值。
	trie树利用字符串的公共前缀来减少存储空间和查询时间，从而最大限度减少字符串比较，是非常高效的字符串查找数据结构
*/

#include <stdio.h>
#include <string>
#include <vector>

#define TRIE_MAX_CHAR_NUM 26 //26个字母

struct TrieNode{
	TrieNode *child[TRIE_MAX_CHAR_NUM];
	bool is_end;
	TrieNode() : is_end(false){
		for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
			child[i] = 0;
		}
	}
};

class TrieTree{//注意TrieTree与TrieNode的区别！！
public:
	TrieTree(){
	}
	~TrieTree(){
		for (int i = 0; i < _node_vec.size(); i++){
			delete _node_vec[i];
		}
	}
	/*
		使用ptr指针指向root
		逐个遍历待插入的字符串中的各个字符：
			计算下标pos=正在遍历的字符-'a'
			如果ptr指向的节点的第pos个孩子为假：
				创建该节点的第pos个孩子
			ptr指向该节点的第pos个孩子
		标记ptr指向的节点的is_end为true
	*/
	void insert(const char *word) {//注意字符串与字符指针
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
    bool search(const char *word){
    	TrieNode *ptr = &_root;
        while(*word){
        	int pos = *word - 'a';
        	if (!ptr->child[pos]){
	        	return false;
	        }
	        ptr = ptr->child[pos];
        	word++;
        }
        return ptr->is_end;
    }
	//前缀查询，主要用于查询以某个字符串为前缀的单词一共有多少
    bool startsWith(const char *prefix){
    	TrieNode *ptr = &_root;
        while(*prefix){
        	int pos = *prefix - 'a';
        	if (!ptr->child[pos]){
	        	return false;
	        }
	        ptr = ptr->child[pos];
        	prefix++;
        }
        return true;
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
	std::vector<TrieNode *> _node_vec;//这样在析构的时候只需要遍历这个vector就可以方便的析构
	TrieNode _root;
};

void preorder_trie(TrieNode *node, int layer){//树的前序遍历！！！有了最外层for循环，不再需要显示递归调用right_child
	for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
		if (node->child[i]){
			for (int j = 0; j < layer; j++){
				printf("---");
			}
			printf("%c", i + 'a');
			if (node->child[i]->is_end){
				printf("(end)");
			}
			printf("\n");
			preorder_trie(node->child[i], layer + 1);
		}
	}
}
/*
	深度搜索trie树，对于正在搜索的节点node：
		遍历该节点的26个孩子指针child[i]('a'-'z')，如果指针不空：
			将该child[i]对应的字符(i+'a')push进栈中
			如果该孩子指针标记的is_end为真：
				从栈底到栈顶对栈进行遍历，生成字符串，将它保存到结果数组中
			深度搜索child[i]
			弹出栈顶字符
*/
void get_all_word_from_trie(TrieNode *node, std::string &word,
				   std::vector<std::string> &word_list){
	for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
		if (node->child[i]){
			word.push_back(i + 'a');
			if (node->child[i]->is_end){
				word_list.push_back(word);
			}
			get_all_word_from_trie(node->child[i], word, word_list);
			word.erase(word.length()-1, 1);
		}
	}
}

int main(){
	TrieTree trie_tree;
	trie_tree.insert("abcd");//注意字符串最后一个字符对应的节点的is_end属性都是true
	trie_tree.insert("abc");
	trie_tree.insert("abd");
	trie_tree.insert("b");
	trie_tree.insert("bcd");
	trie_tree.insert("efg");
	printf("preorder_trie:\n");
	preorder_trie(trie_tree.root(), 0);
	printf("\n");	
	std::vector<std::string> word_list;
	std::string word;
	printf("All words:\n");
	get_all_word_from_trie(trie_tree.root(), word, word_list);
	for (int i = 0; i < word_list.size(); i++){
		printf("%s\n", word_list[i].c_str());
	}
	printf("\n");
	printf("Search:\n");
	printf("abc : %d\n", trie_tree.search("abc"));
	printf("abcd : %d\n", trie_tree.search("abcd"));
	printf("bc : %d\n", trie_tree.search("bc"));
	printf("b : %d\n", trie_tree.search("b"));
	printf("\n");
	printf("ab : %d\n", trie_tree.startsWith("ab"));
	printf("abc : %d\n", trie_tree.startsWith("abc"));
	printf("bc : %d\n", trie_tree.startsWith("bc"));
	printf("fg : %d\n", trie_tree.startsWith("fg"));
	return 0;
}
