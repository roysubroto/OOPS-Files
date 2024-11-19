#include <bits/stdc++.h>
using namespace std;

class Test
{
    public:
    static void read(int x,int y)
    {
        if(x>y)
        cout << "x is bigger\n";
        else if(x<y)
        cout << "y is bigger\n";
        else
        cout << "x and y are equal\n";
    }
};
int main()
{
    Test t1;
    t1.read(20,30);
    Test::read(12,6);
    Test::read(5,5);
}