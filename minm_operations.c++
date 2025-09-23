#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int count=0;
        vector<long long> v;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(pq.size()>1 && pq.top()<k){
            int f=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            long long ans=1LL*min(f, s) * 2 + max(f, s);
            pq.push(ans);
            count++;

        }
        
        return count;
    }
};