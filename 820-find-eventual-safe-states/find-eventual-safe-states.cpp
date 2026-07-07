class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> inDegree(V,0);
        vector<vector<int>>revAdj(V);
        for(int i=0; i<V; i++){
            for(auto it: graph[i]){
                revAdj[it].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0; i<V; i++){
            if(inDegree[i]==0)
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: revAdj[node]){
                inDegree[it]--;

                if(inDegree[it]==0)
                q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};