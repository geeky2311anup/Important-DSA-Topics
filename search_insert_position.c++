#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        int l=0;
        int h=n-1;
        int ind=-1;
        if(n==1){
            if(nums[0]>=target){
                return 0;
            }
            else {
                return 1;
            }
        }
        
        while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]==target){
            ind=mid;
            break;
        }
        else if(nums[mid]>target){
            h=mid-1;
        }
        else if(nums[mid]<target){
            l=mid+1;
        }
        }
        if(ind!=-1){
            return ind;
        }
        else{
           return l;////in failed binary search l always give the future index of target if added later 
        }
    }
};