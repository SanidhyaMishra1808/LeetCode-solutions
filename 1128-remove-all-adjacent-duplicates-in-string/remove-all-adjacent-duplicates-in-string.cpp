class Solution {
public:
    string removeDuplicates(string s){
        int i = 0;
        int j = 1;
        while (j < s.length()){
            if (s[i] == s[j]){
                s.erase(i, 2);
                i = max(0, i - 1);
                j = max(1, j - 1);
            }else{
                i++;
                j++;
            }
        }
        return s;
    }
};