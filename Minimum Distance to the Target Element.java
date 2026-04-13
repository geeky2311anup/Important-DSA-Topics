class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int n = nums.length;
        int minm = Integer.MAX_VALUE;   
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                minm=Math.min(minm,Math.abs(i-start));
            }
        }
        return minm;
    }
}
