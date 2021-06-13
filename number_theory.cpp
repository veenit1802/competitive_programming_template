#include<bits/stdc++.h>
using namespace std;


//----------------------   Extended Euclidean  Algorithm  Start -------------------------------

template<typename T> 
pair<T,T> extended_euclidean(T a,T b,T &c )
{
    if(b==0)
    {
        c=a;
        return {1,0};
    }
    pair<T,T> pp = extended_euclidean(b,a%b,c);
    pair<T,T>pa;
    pa.first=pp.second;
    pa.second = pp.first-(a/b)*pp.second;
    return pa;
}

//---------------------   END  ---------------------------------------------------------------




//---------------------   Linear Diophantine Equation   --------------------------------------

template<typename T>
vector<pair<T,T>> linear_diophantine_equation(T a,T b,T k,T times)
{
    T gcd=0;
    pair<T,T> pp = extended_euclidean(a,b,gcd);
    int x=pp.first*k,y=pp.second*k;
    int cnt=0;
    vector<pair<T,T>>v;
    while(times--)
    {
        int lx,ly;
        lx=x-(cnt*(b/gcd));
        ly=y+(cnt*(a/gcd));
        v.push_back({lx,ly});
    }

    return v;
}

//---------------------  END  ---------------------------------------------------------------



//-------------------  Euer totient Function            -------------------------------------





int main()
{
    
    return 0;
}