class DSU{
    public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);

        unordered_map<string, int>emailToAccount;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];

                if(emailToAccount.find(email) == emailToAccount.end()){
                    emailToAccount[email] = i;
                }
                else{
                    dsu.unite(i, emailToAccount[email]);
                }
            }
        }
        unordered_map<int, vector<string>>mergedEmails;
        for(auto &it : emailToAccount){
            string email = it.first;
            int account = it.second;

            int parent = dsu.find(account);
            mergedEmails[parent].push_back(email);
        }
        vector<vector<string>> ans;
        for(auto &it: mergedEmails){
            int parent = it.first;
            vector<string> emails = it.second;

            sort(emails.begin(),emails.end());
            vector<string>temp;
            temp.push_back(accounts[parent][0]);

            for(string &email: emails)
            temp.push_back(email);
            
            ans.push_back(temp);
        }
        return ans;
    }
};