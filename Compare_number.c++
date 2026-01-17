class Solution {
public:
    static int compareVersion(const std::string& version1, const std::string& version2) {

        // Pointers to traverse both version strings
        size_t i = 0, j = 0;

        // Lengths of both version strings
        const size_t n1 = version1.size(), n2 = version2.size();

        // Continue while any part of either version remains
        while (i < n1 || j < n2) {

            long v1 = 0;

            // Extract current numeric part from version1
            while (i < n1 && version1[i] != '.') {
                v1 = v1 * 10 + (version1[i] - '0');
                ++i;
            }

            long v2 = 0;

            // Extract current numeric part from version2
            while (j < n2 && version2[j] != '.') {
                v2 = v2 * 10 + (version2[j] - '0');
                ++j;
            }

            // Compare the extracted revision numbers
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;

            // Skip the dot character if present
            if (i < n1 && version1[i] == '.') ++i;
            if (j < n2 && version2[j] == '.') ++j;
        }

        // Versions are equal
        return 0;
    }
};
