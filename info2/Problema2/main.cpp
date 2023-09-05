#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "Ingrese el numero A: ";
    cin >> a;
    for(int i=a;i--;i)
    {
        if(i>0)
        {
            a = a*i;
        }
    }
    return 0;
}
