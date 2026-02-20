class Solution {
public:
    
    // Function to calculate the sum of digits of a number
    // Example: 123 -> 1 + 2 + 3 = 6
    int digitSum(int n) {
        int sum = 0;
        
        // Extract digits one by one
        while (n > 0) {
            sum += n % 10;   // Add last digit
            n /= 10;        // Remove last digit
        }
        
        return sum;
    }

    int maximumSum(std::vector<int>& nums) {
        
        /*
            Map to group numbers by their digit sum.
            Key   -> digit sum
            Value -> list of numbers having that digit sum
            
            Example:
            nums = {18, 27, 36}
            digitSum(18) = 9
            digitSum(27) = 9
            digitSum(36) = 9
            
            sums[9] = {18, 27, 36}
        */
        std::map<int, std::vector<int>> sums;

        // Step 1: Group numbers based on digit sum
        for (int num : nums) {
            int sum = digitSum(num);
            sums[sum].push_back(num);
        }

        int maxSum = -1;  // Stores final maximum pair sum

        /*
            Step 2: For each digit-sum group:
            - If at least 2 numbers exist,
            - Find the two largest numbers,
            - Update maxSum
        */
        for (auto& [sum, numbers] : sums) { 
            
            // We need at least two numbers to form a pair
            if (numbers.size() >= 2) {
                
                // Sort numbers in ascending order
                std::sort(numbers.begin(), numbers.end());
                
                // Take last two (largest two numbers)
                int largest = numbers[numbers.size() - 1];
                int secondLargest = numbers[numbers.size() - 2];
                
                // Update global maximum
                maxSum = std::max(maxSum, largest + secondLargest);
            }
        }

        // If no valid pair found, returns -1
        return maxSum;
    }
};
