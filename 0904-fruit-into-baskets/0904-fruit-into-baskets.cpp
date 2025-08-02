class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // understand problem as to find the longest subarray with at most 2 distinct elements
        int i = 0, j = 0, maxL = 0;
        unordered_map<int , int>mp;

        while (j < fruits.size()){
            mp[fruits[j]]++;
            while(mp.size() > 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            if(mp.size() <= 2){
                maxL = max(maxL, j - i + 1);
            }
            j++;
        }
        return maxL;
    }
};