class Solution {
    public List<Integer> separator(int n){
        List<Integer> list = new ArrayList<>();
        while(n>0){
            list.add(n%10);
            n=n/10;
        }
        // System.out.println(list);
        return list;
    }

    public int[] separateDigits(int[] nums) {
        int n =nums.length;
        List<Integer> temp = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        for(int i=0;i<n;i++){
            temp = separator(nums[i]);
            Collections.reverse(temp);
            ans.addAll(temp);
        }
        // separator(1234);
        int[] arr = ans.stream().mapToInt(Integer::intValue).toArray();
        return arr;
        
    }
}
