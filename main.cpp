/**Se citesc doua numere, n si x,
 n natural si x real pozitiv.
 Fara a folosi functia pow, extrageti cu 3 zecimale
 exacte radicalul de ordinul n din x.*/

#include<iostream>
#include<cmath>
using namespace std;
int n;
float x;
float f ( int n, float y, float x)
{
    float p=1;
    for(int i=1; i<=n; i++)
        p=p*y;
    return p-x;
}
float d_i(float s, float d, int n, float x)///s-stanga,d-dreapta
{
    if(d-s<=0.0001)
        return s;
    else
    {
        float mij=(s+d)/2;
        if( f(n,mij,x)==0)
            return mij;
        else
            if(f(n,mij,x)<0)
                return d_i(mij,d,n,x);
        else
            return d_i(s,mij,n,x);
    }
}
int main ()
{
    cin>>n>>x;
    cout<<d_i(0,sqrt(x),n,x);
    return 0;
}
