#include <iostream>
using namespace std;

int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first - 1;
    for (int j = first; j < last; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swapping the value of arr[i] and arr[j]
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return i + 1;
}

void Quick_Sort(int arr[], int first, int last) {
    // Base condition
    if (first >= last) {
        return;
    }
    int pi = partition(arr, first, last);
    Quick_Sort(arr, first, pi - 1);
    Quick_Sort(arr, pi + 1, last);
}

void display(int arr[], int last) {
    for (int i = 0; i < last; i++) {
        cout << arr[i] << " , ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 3, 7, 9, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before sorting" << endl;
    display(arr, n);
    Quick_Sort(arr, 0, n - 1);
    cout << "Array after sorting" << endl;
    display(arr, n);
    return 0;
}
