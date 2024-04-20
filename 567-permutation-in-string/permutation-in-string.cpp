class Solution {
public:
    bool areAnagram(string &s1,string &s2){
        int count[256] = {0};
        for(int i=0; i<s1.size(); i++){
            count[s1[i]]++;
            count[s2[i]]--;
        }
        for(int i=0; i<256; i++){
            if(count[i]!=0){
                return false;
            }
        }return true;
    }
    bool checkInclusion(string s1, string s2) {
        int i=0;
        if(s1.size() > s2.size()){
            return false;
        }
        while(i <= s2.size()-s1.size()){
            string s = s2.substr(i,s1.size());
            if(areAnagram(s,s1)){
                return true;
            }
            i++;
        }
        return false;
    }
};