#include<bits/stdc++.h>
using namespace std;


/*
    Ques    Why and when we use the 0-1BFS?
    Ans     0-1BFS is used for finding the shortest path from source to destination
            where there is restriction edge weight or they can either be 0 or 1.
    
    Ques    How many ways are there for solving these kind of problems?
    Ans     It can be solved using Dijkstra's algorithm with priority queue or
            using the 0-1 BFS with doubly ended queue.
    
    Ques    Time complexitiy of the algorithm?
    Ans     If using the Dijkstra's with priority queue then O(ElogV)
            Otherwise if using 0-1BFS then O(E+V)
*/

vector<pair<int,int>>vec[10001];

int BFS01(int source,int totNode)
{
    list<pair<int,int>>q;
    q.push_front({source,0});
    vector<bool>visited(totNode,false);
    while(!q.empty())
    {
        pair<int,int>qpa = q.front();
        q.pop_front();
        visited[qpa.first]=true;
        if(qpa.first==totNode-1)
        {
            return qpa.second;
        }

      
        for(pair<int,int>it:vec[qpa.first])
        {
            if(!visited[it.first]){
                if(it.second==1)
                {
                    q.push_back({it.first,it.second+qpa.second});
                }
                else if(it.second==0){
                    q.push_front({it.first,it.second+qpa.second});
                }
            }
        }
    }

    return INT_MAX;
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
        vec[u].push_back({v,0});
        vec[v].push_back({u,1});
    }
    int val=INT_MAX;
    val=BFS01(0,n);
    cout<<(val==INT_MAX?-1:val);
    return 0;
}