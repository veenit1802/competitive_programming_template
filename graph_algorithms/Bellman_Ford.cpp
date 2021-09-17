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
*/


int main()
{
    cout<<"hello";
}