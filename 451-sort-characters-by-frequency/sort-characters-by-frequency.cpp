class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        vector<pair<int, char>> v;
        string ans = "";
        // Step 1: Count the frequency of each character
        for(auto ch: s) {
            mp[ch]++;
        }
        // Step 2: Transfer the frequency data to a vector of pairs
        for(auto i: mp) {
            v.push_back({i.second, i.first});
        }
        // Step 3: Sort the vector by frequency in descending order
        sort(v.begin(), v.end(), greater<pair<int, char>>());

        // Step 4: Build the output string based on sorted frequencies
        for(auto i: v) {
            while(i.first--) ans += i.second;
        }
        return ans;
    }
};
