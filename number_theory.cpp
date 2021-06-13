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
//-------------------          END                      -------------------------------------


//-------------------   Finding all factors in logn for queries using seive  ---------------------------

template<typename T>
void createFactorBase(T *a,T n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }

    for(int i=2;i*i<n;i++)
    {
        if(a[i]==i)
        {
            for(int j=2*i;j<n;j+=i)
            {
                if(a[j]==j)
                {
                    a[j]=i;
                }
            }
        }
    }
}

template<typename T>
vector<T> findAllFactors(T a[],T k)
{
    vector<T>v;
    while(k>1)
    {
        v.push_back(a[k]);
        k=k/a[k];
    }

    return v;
}

//------------------                     END                    ---------------------------

int main()
{
    
    return 0;
}