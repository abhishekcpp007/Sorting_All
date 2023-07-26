#include <iostream>
#include <vector>
using namespace std;

void CountSort(vector<int>& arr, int pos) {
    int n = arr.size();
    vector<int> freq(10, 0);
    for (int i = 0; i < n; i++) {
        freq[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++) { // Fix: loop condition should be i < 10
        freq[i] += freq[i - 1]; // Fix: freq[i] += freq[i - 1];
    }
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[(arr[i] / pos) % 10]] = arr[i]; // Fix: use 'pos' instead of 10
    }
    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

void RadixSort(vector<int>& arr) {
    int maxi = -1;
    for (auto x : arr) {
        maxi = max(x, maxi); // Fix: use 'x' instead of 'arr[x]'
    }

    for (int pos = 1; maxi / pos >= 1; pos *= 10) { // Fix: loop condition should be maxi / pos >= 1
        CountSort(arr, pos);
    }
}

void display(vector<int> arr) {
    for (auto x : arr) {
        cout << x << ",";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Elements of array before sorting" << endl;
    display(arr);
    cout << "Elements of array after sorting" << endl;
    RadixSort(arr);
    display(arr);

    return 0;
}
