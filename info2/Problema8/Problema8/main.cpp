#include <iostream>
using namespace std;
int main()
{
    int n, a, b, c, as, bs, sumatoria, resta;
    cout<<"Ingrese el numero A: ";
    cin>>a;
    cout<<"Ingrese el numero B: ";
    cin>>b;
    cout<<"Ingrese el numero C: ";
    cin>>c;
    n=0;
    as=0;
    bs=0;
    resta=0;
    sumatoria=0;
    int numA[c];
    int numB[c];
    if(a>0)
    {
        while(n<c)
        {
            for(int i=1;i<c;i++)
            {
                n=a*i;
                if(n<c)
                {
                    numA[i-1]=n;
                    as++;
                }
                n=b*i;
                if(n<c)
                {
                    numB[i-1]=n;
                    bs++;
                }
            }
        }
        for(int i=0;i<as;i++)
        {
            cout<<numA[i]<<" + ";
            sumatoria=sumatoria+numA[i];
        }
        for(int i=0;i<bs;i++)
        {
            bool p=false;
            for(int j=0;j<as;j++)
            {
                if(numB[i]==numA[j])
                {
                    p=true;
                    resta=resta+numB[i];
                    break;
                }
            }
            if(!p)
            {
                cout<<numB[i];
                if(i!=bs-2)
                {
                    cout<<" + ";
                }
            }

            if(i==bs-1)
            {
                cout<<"= ";
            }



            sumatoria=sumatoria+numB[i];
            ;
        }
    }
    sumatoria=sumatoria-resta;
    cout<<sumatoria;
    return 0;
}
