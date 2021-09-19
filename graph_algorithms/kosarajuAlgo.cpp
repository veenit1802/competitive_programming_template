#include<bits/stdc++.h>
using namespace std;

/*
    Ques    Why we use kosaraju algorith?
    Ans     We use kosaraju algorithm for finding the strongly connected component
            in directed graph because we cannot use the connected component of 
            bidirected graph in directed graph.
    
    Ques    Procedure off solving the the problem with kosaraju?
    Ans     1) Do random dfs and fill the stack while backtracking?
            2) Reverse all the edges of the graph
            3) Do the dfs in the way the nodes pop up in the stack and count the
               connected component
*/

vector<int>vec1[10001];
vector<int>vec2[10001];

void dfs(int node,stack<int>&st,vector<bool>&visited)
{
    visited[node]=true;

    for(int i:vec1[node])
    {
        if(!visited[i])
        {
            dfs(i,st,visited);
        }
    }

    st.push(node);
}


void dfs2(int node,vector<bool>&visited)
{
    visited[node]=true;

    for(int i:vec2[node])
    {
        if(!visited[i])
        {
            dfs2(i,visited);
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
        u-=1;
        v-=1;
        vec1[u].push_back(v);
        vec2[v].push_back(u);
    }

    stack<int>st;
    
    vector<bool>visited(n,false);

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,st,visited);
        }
    }

    fill(visited.begin(),visited.end(),false);
    int cnt=0;

    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if(!visited[node])
        {
            dfs2(node,visited);
            cnt+=1;
        }
    }

    cout<<cnt<<"\n";

    return 0;
}