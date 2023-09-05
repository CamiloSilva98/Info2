#include <iostream>
using namespace std;

int main()
{
    int N, con, num=2;
    cout<<"Ingrese n: ";
    cin>>N;
    con=0;
    while(con<N)
    {
        bool pri_o=true;
        for(int i=2;i*i<=num;i++)
        {
            if(num%i==0)
            {
                pri_o=false;
                break;
            }
        }
        if(pri_o)
        {
            con++;
        }
        num++;
    }
    cout<<"El primo numero "<<N<<" es: "<<num-1;
    return 0;
}

