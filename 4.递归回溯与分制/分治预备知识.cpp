/*
分治算法是将一个规模为N的问题分解为K分规模较小的子问题，这些子问题相互独立且与原问题性质相同
求出子问题的解后进行合并，就得到原问题的解
以归并排序为例
*/
#include <vector>
void merge_sort_two_vec(std::vector<int>& sub_vec1,
                        std::vector<int>& sub_vec2,
                        std::vector<int>& vec){
    int i=0;
    int j=0;
    while(i<sub_vec1.size() && j<sub_vec2.size()){
        if(sub_vec1[i]<=sub_vec2[j]){
            vec.push_back(sub_vec1[i]);
            i++;
        }
        else{
            vec.push_back(sub_vec2[j]);
            j++;
        }
    }
    for(;i<sub_vec1.size();++i){
        vec.push_back(sub_vec1[i]);
    }
    for(;j<sub_vec2.size();++j){
        vec.push_back(sub_vec2[j]);
    }
}

void merge_sort(std::vector<int>& vec){
    if(vec.size()==1){
        return;
    }
    int mid = vec.size()/2;
    std::vector<int> sub_vec1;
    std::vector<int> sub_vec2;
    for(int i=0;i<mid;++i){
        sub_vec1.push_back(vec[i]);
    }
    for(int i=mid;i<vec.size();++i){
        sub_vec2.push_back(vec[i]);
    }
    merge_sort(sub_vec1);
    merge_sort(sub_vec2);
    vec.clear();
    merge_sort_two_vec(sub_vec1,sub_vec2,vec);
}