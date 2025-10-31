class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int> v(n,-1);
        for(int i=0;i<n;i++){
            if(v[nums[i]]==-1){
                v[nums[i]]=nums[i];
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
