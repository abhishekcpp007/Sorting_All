#include<iostream>
#include<vector>
using namespace std;
void BucketSort(float arr[],int n){
    vector<vector<float>>bucket(n,vector<float>());
    // step2
    for(int i=0;i<n;i++){
        int idx=arr[i]*n;
        bucket[idx].push_back(arr[i]);
    }
    // step 3
    for(int  i=0;i<n;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());

        }

    }
}
int main(){
    float arr[]={0.12,0.23,0.14,0.18,0.6,0.97,0.11};
    int n=sizeof(arr)/sizeof(arr[0]);
    BucketSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    return 0;
}