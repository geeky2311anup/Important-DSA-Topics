class Solution {
    unordered_set<string> exact;
    unordered_map<string, string> lower;
    unordered_map<string, string> vowel;
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (string word : wordlist) {
            exact.insert(word);
            string low = toLower(word);
            if (lower.find(low) == lower.end())
                lower[low] = word;
            string vow = devowel(low);
            if (vowel.find(vow) == vowel.end())
                vowel[vow] = word;
        }
        vector<string> res;
        for (string query : queries)
            res.push_back(solve(query));
        return res;
    }
private:
    string solve(string query) {
        if (exact.count(query))
            return query;
        string low = toLower(query);
        if (lower.count(low))
            return lower[low];
        string vow = devowel(low);
        if (vowel.count(vow))
            return vowel[vow];
        return "";
    }
    string devowel(string word) {
        string res = "";
        for (char c : word)
            res += isVowel(c) ? '*' : c;
        return res;
    }
    string toLower(string word) {
        string res = "";
        for (char c : word)
            res += tolower(c);
        return res;
    }
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};
