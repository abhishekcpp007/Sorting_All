#include<iostream>
#include<vector>
using namespace std;

void Merge(int arr[],int l,int mid,int r){
    int an=mid-l+1;
    int bn=r-mid;
    int An[an];

    int Bn[bn];
    for(int i=0;i<an;i++){
        An[i]=arr[l+i];
    }
    for(int j=0;j<bn;j++){
        Bn[j]=arr[mid+1+j];

    }
    int i=0;
    int j=0;
    int k=l;
    while(i<an && j<bn){
        if(An[i]<=Bn[j]){
            arr[k]=An[i];
            i++;
        }
        else{
            arr[k]=Bn[j];
            j++;
        }
        k++;
    }
    while(i<an){
        arr[k++]=An[i++];
    }
    while(j<bn){
        arr[k++]=Bn[j++];
    }
}
void MergeSort(int arr[], int l,int r){
    if(l>=r) {return;}
    int mid=(l+r)/2;
    MergeSort(arr,l,mid);
    MergeSort(arr,mid+1,r);
    Merge(arr,l,mid,r);  

}
void display(int arr[], int n)  
{  
    for (int i = 0; i < n; i++)  
        cout<<arr[i]<<" ";  
} 
int main(){
    int arr[] = {12,2,1,45,67,13,23,4,1,9};
    int n= sizeof(arr)/sizeof(arr[0]);
     cout<<"Before sorting array elements are - \n";  
     display(arr, n);  
    MergeSort(arr,0,n-1);
      cout<<"\nAfter sorting array elements are - \n"; 
      display(arr, n); 

return 0;
}