#include <iostream>
#include <list>
using namespace std;

int main(void)
{
    // list<int> m;
    vector<int> m; // same as list
    for (int i = 1; i <= 3; i++)
    {
        m.push_back(i);
    }
    for (auto i = m.begin(); i != m.end(); ++i)
    {
        cout << *i << endl;
    }
}