/*
	并查集Union Find，又称不相交集合Disjiont Set,它应用于N个元素的集合求并与查询问题，在该应用场景中，我们通常是在开始时让每个元素构成一个
	单元素的集合，然后按一定顺序将属于同一组的元素所在的集合合并，其间要反复查找一个元素在哪个几何中，面对极大的数据量时，普通的数据结构往往无法
	解决，并查集是解决该种问题的最优算法
*/

#include <stdio.h>
#include <vector>

class DisjointSet{
public:
	// 设置表示集合数组id[i]，初始是每个元素构成一个单元素的集合，编号为i的元素数据集合i
	DisjointSet(int n){
		for (int i = 0; i < n; i++){
			_id.push_back(i);
		}
	}
	int find(int p){
		return _id[p];//数组下标是元素的值，数组的值表示集合
	}
	void union_(int p, int q){
		int pid = find(p);
		int qid = find(q);
		if (pid == qid){
			return;
		}
		for (int i = 0; i < _id.size(); i++){
			if (_id[i] == pid){
				_id[i] = qid;//将所有属于pid的集合全部改为qid对应的集合
			}
		}
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
private:
	std::vector<int> _id;
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
