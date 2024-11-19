#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); ++j)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}
//change1

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    selectionSort(arr);
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}