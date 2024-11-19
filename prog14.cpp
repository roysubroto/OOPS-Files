#include <bits/stdc++.h>
using namespace std;

class Test
{
    int a;
    public:
    Test(){
        a=0;
    }
    
    void operator++(int x)
    {
        a++;
    }
    void operator--(int x)
    {
        a--;
    }
    void printdata()
    {
        cout << a << endl;
    }
};
int main()
{
    Test t1;
    t1++;
    t1.printdata();
    t1--;
    t1.printdata(); 

}