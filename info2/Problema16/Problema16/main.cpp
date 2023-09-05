#include<iostream>
using namespace std;
int main()
{
    int c1, c, s, s1, semilla;
    cout<<"Ingrese un numero: ";
    cin>>semilla;
    s=semilla;
    c=0;
    c1=0;
    for(int i=0;i<=semilla;i++)
    {
        s1=i;
        while(s1>1)
        {
            if(s1%2==0)
            {
                s1=s1/2;
                c++;
            }
            if(s1%2!=0)
            {
                c++;
                if(s1!=1)
                {
                    s1=(3*s1)+1;
                }
                else
                    break;
            }
        }
        if(c1<c)
        {
            c1=c;
            s=i;
        }
        c=0;
    }
    s1=s;
    cout<<s<<", ";
    while(s1>1)
    {
        if(s1%2==0)
        {
            s1=s1/2;
            c++;
            if(s1==1)
            {
                cout<<s1<<".";
            }
            else
            {
                cout<<s1<<", ";
            }
        }
        if(s1%2!=0)
        {
            c++;
            if(s1!=1)
            {
                s1=(3*s1)+1;
                cout<<s1<<", ";
            }
            else
            {
                cout<<'\n';
                break;
            }
        }
    }
    cout<<"La serie mas larga es con la semilla "<<s<<" teniendo "<<c1<<" terminos.";
    return 0;
}

