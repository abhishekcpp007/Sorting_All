
#include<iostream>
#include<vector>
using namespace std;
void bubbelsort(vector<int>&a){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
int main(){
   // int n;
   // cin>>n;
    vector<int>a={12,1,3,45,6,8,78};
    //cout<<"enter the element";
    //for(int i=0;i<n;i++){
     //   cin>>a[i];
  //  }
  //  }
   bubbelsort(a);
    for(int i=0;i<a.size();i++){
         cout<<a[i];
  
    }
   return 0;
}