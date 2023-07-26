#include<iostream>
#include<vector>
using namespace std;

int CountSort(vector<int>& arr) {
    int n = arr.size();
    int maxi = -1;
    for (int i = 0; i < n; i++)
        maxi = max(arr[i], maxi);

    vector<int> freq(maxi + 1, 0);
    for (int j = 0; j < n; j++) { // Fix: loop should run from 0 to n
        freq[arr[j]]++;
    }
    for (int i = 1; i <= maxi; i++) { // Fix: loop condition should be <= maxi
        freq[i] += freq[i - 1];
    }
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

void display(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of your array" << endl;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "array before sorting" << endl;
    display(arr, n);
    CountSort(arr);
    cout << "array after sorting" << endl;
    display(arr, n);

    return 0;
}
