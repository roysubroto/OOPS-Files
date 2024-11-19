#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Sample
{
    int a,b;
    friend void print(Sample);
};


void print(Sample S)
{
    S.a=10;
    S.b=20;
    cout << "a = " << S.a << endl;
    cout << "b = " << S.b << endl;
}

int main()
{
    Sample S;
    print(S);
}

    

