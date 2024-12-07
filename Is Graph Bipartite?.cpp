class Solution {
    public:
    bool bfs(vector<vector<int>> &graph, vector<int> &col, int V){
        col[V] = 0;
        queue<int> q;
        q.push(V);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it:graph[front]){
                if(col[it]==-1){
                    col[it] = !col[front];
                    q.push(it);
                }
                if(col[it]==col[front]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> col(V,-1);
        for(int i=0;i<V;i++){
            if(col[i]==-1){
                if(bfs(graph,col,i)==false) return false;
            }
        }
        return true;
    }
};
