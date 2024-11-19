#include <bits/stdc++.h>
using namespace std;

class Test
{
    static int a,b;
    public:
    static void getdata()
    {
        cout << "Enter a,b" << endl;
        cin >> a >> b;

        cout << "Entered value of a is : " << a << endl;
        cout << "Entered value of b is : " << b << endl;
    }
};
int Test ::a;
int Test ::b;
int main()
{
    Test::getdata();
    Test t1;
    t1.getdata();
}