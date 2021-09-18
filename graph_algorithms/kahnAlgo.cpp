#include<bits/stdc++.h>
using namespace std;

/*
    Ques    What is topological sorting?
    Ans     Topological sorting is the linear ordering of graph in such a way the 
            parent should always comes first or before the children in the ordering.

    Ques    What is Kahn's algorithm?
    Ans     Kahn's algorithm is a topologicak sorting based sorting based algorithm.

    Ques    Kahn's algorithm is recursive or itarative method of topological sorting?
    Ans     Kahn's algorithm is itarative method of solving topological sorting there 
            is recursive sorting also using different algorithm.
    
    Ques    Other uses of topological sorting?
    Ans     We can use the topological sorting for finding the if the grapg DAG or not.

    Ques    Why the algorithm can be used on DAG only?
    Ans     If the graph is cyclic then there is will no node which will be  independent
            because of which it's topological sorting cannot be found.
*/


vector<int>ansarr;
vector<int>indeg;
vector<int>vec[10001];


void kahnAlg(int totNode)
{
    indeg.resize(totNode,0);

    for(int i=0;i<totNode;i++)
    {
        for(int j:vec[i])
        {
            indeg[j]++;
        }
    }

    queue<int>qu;

    for(int i=0;i<totNode;i++)
    {
        if(indeg[i]==0)
        {
            qu.push(i);
        }
    }

    
    while(!qu.empty())
    {
       
        int node = qu.front();
        qu.pop();

        ansarr.push_back(node);
        
        for(int i:vec[node])
        {
            indeg[i]-=1;
            if(indeg[i]==0)
            {
                qu.push(i);
            }
        }
    }


}

int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        vec[v].push_back(u);
    }

    kahnAlg(n);

    if(ansarr.size()==0)
    {
        cout<<-1;
        return 0;
    }
    for(int i:ansarr)
    {
        cout<<i<<" ";
    }
    
    return 0;
}