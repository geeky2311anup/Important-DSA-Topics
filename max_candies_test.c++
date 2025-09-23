#include <vector>

using namespace std;

class Solution {
    public:
        bool canDistribute(vector<int>& candies, long long k, int mid) {
            if (mid == 0) return true; 
            long long count = 0;
            for (int c : candies) {
                count += (c / mid); 
                if (count >= k) return true; 
            }
            return false;
        }
    
        int maximumCandies(vector<int>& candies, long long k) {
            long long left = 1, right = *max_element(candies.begin(), candies.end()), ans = 0;
            
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                
                if (canDistribute(candies, k, mid)) {
                    ans = mid; 
                    left = mid + 1;
                } else {
                    right = mid - 1; 
                }
            }
            
            return ans;
        }
    };