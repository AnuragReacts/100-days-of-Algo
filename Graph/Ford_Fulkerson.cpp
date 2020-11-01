/*
A cpp program to calculate max flow between single source and sink. 
Ford_Fulkerson Algorithm
input format and example is given below

Usage - 
compile and run.
input will be taken via stdin.

input format -- 
first line contains two numbers, n and m
n is the number of nodes. numbered from 1,2,3....n
m is the number of edges. 

next m lines contains 3 numbers each, u,v,w  descibing an edge;
u is the first node of the edge.
v is the second node of the edge.
w is the flow possible through the edge.

-- By default, 1 is considered as source node, and N is the sink node.

an input example.

6 9
1 2 7
1 5 4
2 3 5
2 4 3
3 6 8
4 6 5
4 3 3
5 2 3
5 4 2

ans = 10
*/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

typedef vector<int> vi;


vector<vector<int>> g,cap;
int n;
vi par;

int bfs(int s,int t){
    vector<bool> visted(n+1,0);
    queue<pair<int,int>> q;
    q.push({s,INT_MAX});
    visted[s]=1;
    int src,flow,new_flow;
    while(!q.empty()){
        src = q.front().first;
        flow = q.front().second;
        q.pop();
        
        for(auto sib:g[src]){
        	new_flow = cap[src][sib];
            if(!visted[sib] && new_flow > 0){
                visted[sib]= true;
                par[sib] = src;
                
                new_flow = min(new_flow, flow);
                if(sib == t) return new_flow;

                q.push({sib, new_flow});
            }
        }
    }
    return 0;
}

int max_flow(int s,int t){
    int aug_flow,prev,cur;
    int flow=0;
    while(aug_flow = bfs(s,t)){
    	
    	
    	
    	
    	cur = t;
	    flow += aug_flow;
	    while( cur != s){
	        prev = par[cur];
	        cap[prev][cur] -= aug_flow;
	        
	        cap[cur][prev] += aug_flow;
	        //cout<<cap[prev][cur]<<" "<<cap[cur][prev]<<"\n";
	        cur = prev;
	    }
    }
    return flow;
}

int main(){
    int v;
    cin>>n>>v;
    g = vector<vector<int>>(n+1);
    cap = vector<vi>(n+1,vi(n+1,-1));
    par = vi(n+1,-1);
    int x,y,z;
    for(int i=1;i<=v;i++){
        cin>>x>>y>>z;
        g[x].push_back(y);
        cap[x][y] = z;
    }
    
    cout<<"The max flow between nodes 1 and "<<n<<" is "<<max_flow(1,6)<<"\n";
    
    // un-comment for printing residual graph
    /*
    for(int i=1;i<=n;i++){
    	for(auto dest:g[i]){
    		cout<<i<<" "<<dest<<" "<<cap[i][dest]<<"\n";
    	}
    }
    cout<<"\n";
    */
    
    // uncomment to print adjacent flow matrix.
    // it shows the flows between each node.
    // ( -1 means there is no link.)
    /* 
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		cout<<cap[i][j]<<" ";
    	}
    	cout<<"\n";
    }
    */
}
