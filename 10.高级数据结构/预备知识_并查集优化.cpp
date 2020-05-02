/*
	前面的暴力实现复杂度太高
	使用森林存储集合之间的关系，属于同一个集合的不同元素，都有一个相同的根节点，代表着这个集合
	当进行查找某个元素属于哪个集合时，即遍历该元素到根节点，返回根节点所代表的集合，在遍历过程中使用路径压缩的优化算法，使整体树的形状更加扁平，从而
	优化查询的时间复杂度
	当进行合并时，即使两颗子树合并为一棵树，将一颗子树的根节点指向另一个子树的根节点，在合并时可按子树的大小，将规模较小的子树合并到
	规模较大的子树上，从而使树规模更加平衡，从而优化未来查询的时间复杂度
*/
#include <stdio.h>
#include <vector>

class DisjointSet{
public:
	DisjointSet(int n){		
		for (int i = 0; i < n; i++){
			_id.push_back(i);
			_size.push_back(1);
		}
		_count = n;
	}
	int find(int p){
		while(p != _id[p]){
			_id[p] = _id[_id[p]];//将p的父节点id[p]更新为id[p]的父节点id[id[p]]
			p = _id[p];
		}
		return p;
	}
	void union_(int p, int q){
		int i = find(p);
		int j = find(q);
		if (i == j){
			return;
		}
		if (_size[i] < _size[j]){
			_id[i] = j;//注意id[i]指向的是根节点
			_size[j] += _size[i];//之所以id[i]赋值为j而不是id[j]，就是为了方便维护size
		}
		else{
			_id[j] = i;
			_size[i] += _size[j];
		}
		_count--;
	}
	void print_set(){
		printf("元素: ");
		for (int i = 0; i < _id.size(); i++){
			printf("%d ", i);
		}
		printf("\n");
		printf("集合: ");
		for (int i = 0; i < _id.size(); i++){
			printf("%d ", _id[i]);
		}
		printf("\n");
	}
	int count(){
		return _count;
	}
private:
	std::vector<int> _id;//id的值表示父亲节点
	std::vector<int> _size;
	int _count;
};

int main(){
	DisjointSet disjoint_set(8);
	disjoint_set.print_set();
	printf("Union(0, 5)\n");
	disjoint_set.union_(0, 5);
	disjoint_set.print_set();
	printf("Find(0) = %d, Find(5) = %d\n",
						disjoint_set.find(0), disjoint_set.find(5));
	printf("Find(2) = %d, Find(5) = %d\n",
						disjoint_set.find(2), disjoint_set.find(5));
	disjoint_set.union_(2, 4);
	disjoint_set.print_set();
	disjoint_set.union_(0, 4);
	disjoint_set.print_set();
	printf("Find(2) = %d, Find(5) = %d\n",
						disjoint_set.find(2), disjoint_set.find(5));
	return 0;
}
