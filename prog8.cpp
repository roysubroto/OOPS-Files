#include <bits/stdc++.h>
using namespace std;

class Test
{
public:
    static int count;

    Test()
    {
        count++;
        cout << count << endl;
    }
    ~Test()
    {
        count--;
        cout << count << endl;
    }
};
int Test ::count = 0;

int main()
{
    cout << "HEllo bhaijaan";
    Test t1,t2,t3;
}
