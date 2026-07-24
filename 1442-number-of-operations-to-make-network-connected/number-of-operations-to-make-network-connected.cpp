class DisjointSet{
    vector<int> rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
        
    }
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        else{
            return parent[node]=findUpar(parent[node]);
        }
    }
    void UnionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cnt = 0;
        for(auto &it:connections){
            if (ds.findUpar(it[0]) == ds.findUpar(it[1])) cnt++;
            else ds.UnionByRank(it[0],it[1]);

        }
        //if no of edges less than no of nodes to connect
        int cc = 0;
        for (int i = 0; i < n; i++){
            int p = ds.findUpar(i);
            if (p == i) cc++;
        }
        if (cnt >= cc - 1) return cc - 1;
        return -1;
        //return no. of connected components -1
        
    }
};