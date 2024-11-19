#include <bits/stdc++.h>
using namespace std;
class Test2;
class Test1
{
    int a;
    public:
    Test1()
    {
        a = 10;
    }
    friend void compare(Test1,Test2);
};

class Test2
{
    int b;
    public:
    Test2()
    {
        b = 20;
    }
    friend void compare(Test1,Test2);
};

void compare(Test1 t1,Test2 t2)
{
    if(t1.a >t2.b)
    {
        cout<<t1.a << " is greater"<<endl;
    } 
    else
    {
        cout<<t2.b << " is greater"<<endl;
    }
}

int main()
{
    Test1 t1;
    Test2 t2;
    compare(t1,t2);
}