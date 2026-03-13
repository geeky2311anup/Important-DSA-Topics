class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        // If the maximum possible sum (9 * num digits) is still less than required sum,
        // then it's impossible to construct such a number
        if(9 * num < sum){
            return "";
        }

        // Create a string of length 'num' filled with '0'
        // This will store the resulting number
        string ans(num, '0');
     
        // Iterate through each digit position
        for(int i = 0; i < num; i++){

            // If the required sum is already satisfied, stop
            if(sum == 0){
                break;
            }

            // Try to place the largest possible digit (from 9 down to 0)
            for(int j = 9; j >= 0; j--){

                // If the current digit can be used without exceeding the remaining sum
                if(sum >= j){

                    // Convert digit to character and store in the result string
                    ans[i] = '0' + j;

                    // Reduce the remaining sum
                    sum = sum - j;

                    // Move to the next position
                    break;
                }
            }
        }

        // Return the constructed number as a string
        return ans;
    }   
};
