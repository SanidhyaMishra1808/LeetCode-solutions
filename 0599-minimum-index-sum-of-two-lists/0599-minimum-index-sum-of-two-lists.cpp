class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<int,vector<string>>mp;
        int m = list1.size();
        int n = list2.size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(list1[i] == list2[j]){
                    mp[i+j].push_back(list1[i]);
                }
            }
        }
        for(auto i : mp){
            return i.second;
        }
        return {""};
    }
};