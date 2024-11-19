#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &c)
{
    for (int i = 0; i < c.size() - 1; ++i)
        for (int j = 0; j < c.size() - i - 1; ++j)
            if (c[j] > c[j + 1])
                swap(c[j], c[j + 1]);
}

int main()
{

    vector<int> c = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(c);
    for (int num : c)
        cout << num << " ";
    cout << endl;

    return 0;
}