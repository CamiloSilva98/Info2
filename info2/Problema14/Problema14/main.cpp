#include <iostream>
using namespace std;
int main()
{
    int n, a1, a2;
    long int x, a, b, maxPal=0;

    for(int i=101;i<=999;i++)
   {
        for(int j=i;j<=999;j++)
        {
            x=0;
            if(i%10!=0||j%10!=0)
            {
                a=i*j;
                b=a;
            }
            else
            {
                a=0;
            }
            while(a!=0)
            {
                n=a%10;
                a=a/10;
                x=10*x+n;
            }
            if (x==b)
            {
                if(maxPal<b)
                {
                    a1=i;
                    a2=j;
                }
                maxPal=max(maxPal,b);
            }

        }
    }

    cout<<a1<<" * "<<a2<<" = "<<maxPal<<" Es el palindromo mas grande. ";
    return 0;
}
