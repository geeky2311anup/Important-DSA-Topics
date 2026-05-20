class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();
        int n = A.length;
        int[] ans = new int[n];
        s1.add(A[0]);
            s2.add(B[0]);
            if(A[0]==B[0]){
                ans[0]=1;
            }

        for(int i=1;i<n;i++){
            int temp = ans[i-1];
            s1.add(A[i]);
            s2.add(B[i]);
            if(A[i]==B[i]){
                ans[i]=ans[i-1]+1;
            }
            else{

            if(s2.contains(A[i])){
                temp = temp+1;
            }
            if(s1.contains(B[i])){
                temp = temp+1;
            }
            ans[i]=temp;

            }

        }
        return ans;
    }
}
