class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int > pos(26,-1);
            for(int i=0;i<s.length();i++){
                pos[s[i]-'a']=i;
            }
            int end=-1;
            int start=0;
            vector<int>result;
            for(int i=0;i<s.length();i++){
                end=max(end,pos[s[i]-'a']);
                    if(end==i){
                        result.push_back(end-start+1);
                        start=end+1;
                    }
            }
            return result;
    
        }
    };