#include <bits/stdc++.h>
using namespace std;
//Example of composition
class Test2;
class Test1
{
    int a,b;

    public:
    friend class Test2;

    void getab()
    {
        cout << "Enter a,b values " << endl;
        cin >> a >> b;
    }
};

class Test2
{
    public:
    
    void putab(Test1 t1)
    {
        cout << "a = " << t1.a << endl;
        cout << "b = " << t1.b << endl;
    }
};


int main()
{
    Test1 t1;
    Test2 t2;
    t1.getab();
    t2.putab(t1);
}