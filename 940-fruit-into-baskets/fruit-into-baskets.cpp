class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>map;
        int low = 0, ans = 1;
        for(int high = 0; high < fruits.size(); high++){
            map[fruits[high]]++;
            while(map.size() > 2){
                map[fruits[low]]--;
                if(map[fruits[low]] == 0){
                    map.erase(fruits[low]);
                }
                low++;
            }
            ans = max(ans , high - low + 1);
        }
        return ans;
    }
};