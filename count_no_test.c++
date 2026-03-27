long long n = nums.size();

// Total possible pairs (i, j) where i < j
long long totalPairs = (n * (n - 1)) / 2; 

// Map to store frequency of (nums[i] - i)
unordered_map<int, long long> freq;

// Count of "good pairs"
long long goodPairs = 0;

for (int i = 0; i < n; i++) {
    
    // Compute transformed value
    // This helps identify pairs where nums[j] - nums[i] == j - i
    int value = nums[i] - i;

    // If this value has been seen before,
    // all previous occurrences form valid "good pairs" with current index
    goodPairs += freq[value]; 

    // Increase frequency of current value
    freq[value]++; 
}

// Bad pairs = total pairs - good pairs
return totalPairs - goodPairs;
