#include <bits/stdc++.h>
using namespace std;

class Test
{
    string a;
    public:
    void getdata()
    {
        cout << "Enter string : ";
        getline (cin,a);
    
    }
    Test operator+(Test t1)
    {
        a=a+t1.a;
        return *this;
    }

    void printdata()
    {
        cout << a << endl;
    }
};
int main()
{
    Test t1,t2,t3;
    t1.getdata();
    t2.getdata();
    t3=t1+t2;
    t3.printdata();
}