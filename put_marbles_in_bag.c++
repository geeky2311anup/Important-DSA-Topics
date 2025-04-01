class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
        vector<long long> adj;
        int n=weights.size();
        for(int i=0;i<weights.size()-1;i++){
               adj.push_back((1ll*weights[i]+weights[i+1]));
        }
        sort(adj.begin(),adj.end());
        long long maxm=weights[0]+weights[n-1];
        long long minm=weights[0]+weights[n-1];
        int p=k-1;
        
        for(int i=adj.size()-1;p>0 && i>=0;i--,p--){
            maxm=maxm+adj[i];
        }
        p=k-1;
        for(int i=0;i<adj.size() && p>0;p--,i++){
            minm=minm+adj[i];
        }
        return maxm-minm;
        }
        
    };