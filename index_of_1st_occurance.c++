class Solution {
public:
    int strStr(string haystack, string needle) {
        /////////
     
   
    size_t pos = haystack.find(needle);

    if (pos != string::npos) {
        return static_cast<int>(pos);
    } else {
        return -1;
    }

   
}

        /////////////////////
    
};