#include<iostream>
#include<vector>
using namespace std;
void Slection_sort(vector<int>&v){
    for(int i=0;i<v.size();i++ ){
        int min_index=i;
        for(int j=i+1;j<v.size();j++){
            if(v[j]<v[min_index]){
                min_index=j;
            }
            
        }
        if(i!= min_index){
            swap(v[i],v[min_index]);
        }
    }
}
int main(){
    vector<int>v={5,8,4,9,2};
    Slection_sort(v);
    for( int i=0;i<v.size();i++){
        cout<<v[i];
    }
    return 0;
}