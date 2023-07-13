//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool DFS(vector<int> adj[],vector<int>&visited,vector<int>&pathVisited, int V, int cur){
        visited[cur]=1;
        pathVisited[cur]=1;
        for(auto it: adj[cur]){
            if(!visited[it]){
                if(DFS(adj,visited,pathVisited,V,it)){
                    return true;
                }
            }
            else if(pathVisited[it]){
                return true;
            }
        }
        pathVisited[cur] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(DFS(adj,visited,pathVisited,V,i)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends