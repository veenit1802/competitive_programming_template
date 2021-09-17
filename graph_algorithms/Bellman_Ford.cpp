#include<bits/stdc++.h>
using namespace std;


/*
    Ques    Why we use the bellman ford algorithm ?
    Ans     We use the bellman ford algorithm to find the shortest path from source 
            to other nodes in terms of edge weight (weight can be negative).

    Ques    Negative cycle have shortest path
    Ans     For negative cycle there no such thing as shortest path 

    Ques    Working of the Bellman ford algorithm
    Ans     1) Take any arrangement of the graph edges.
            2) Loop through the edges max(Nodes-1).
            3) If the previous node value is Infinity or INT_MAX then don't update otherwise update it.
            Note. (Works like BFS on each iteration the i distance node is reachble in minimum time from
            source node)

    Ques    Can we use Bellman Ford for finding the negative weight cycle in a graph?
    Ans     Yes, we can find negative weight cycle in graph by using vth iteration 
            because if any node is updated in vth cycle means there is a negative weight
            cycle
*/

vector<long int>dp;

void BellmanFord(int verticesCnt,int edgesCnt,vector<pair<int,pair<int,int>>>allEdges)
{
    for(int i=0;i<verticesCnt-1;i++)
    {
        for(int j=0;j<edgesCnt;j++)
        {
            int u = allEdges[j].first,v=allEdges[j].second.first,wt=allEdges[j].second.second;
            if(dp[u]!=INT_MAX and dp[u]+wt<dp[v])
            {
                dp[v]=dp[u]+wt;
            }

        }
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    dp.resize(n,INT_MAX);
    vector<pair<int,pair<int,int>>>vec;
    int u,v,wt;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> wt;
        vec.push_back({u-1,{v-1,wt}});
    }

    int source=1;
    source-=1;
    dp[source]=0;
    BellmanFord(n,m,vec);
    for(int i=1;i<n;i++)
    {
        if(dp[i]!=INT_MAX)
        {
            cout<<dp[i]<<" ";
        }
        else{
            cout<<"1000000000 ";
        }
    }
}