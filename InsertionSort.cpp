#include<iostream>
#include<vector>
using namespace std;
void  InsertionSort(vector<int>&v){
   int n=v.size();
   for(int i=1; i<n;i++){
    int curent_element=v[i];
    int j=i-1;
    while(j>=0 && v[j]>curent_element){
        v[j+1]=v[j];
        j--;
        
    }
    v[j+1]=curent_element;

   }
   return ;
}


int main(){
    vector<int>v={23,21,11,3,9,78,7,77};
    InsertionSort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<", ";
      
    }
    return 0;

}