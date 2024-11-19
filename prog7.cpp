#include <bits/stdc++.h>
using namespace std;

class Test
{
public:
    static int a;

    void get()
    {
        cout << "a = " << a << endl;
    }
};
int Test ::a = 8;

int main()
{
    Test T;
    Test ::a = 100; //100 ab 8 pe override ho jaayegaa
    cout << "a = " << Test ::a << endl;
    T.get();
}