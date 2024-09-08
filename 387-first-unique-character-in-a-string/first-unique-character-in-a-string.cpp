class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        if(n==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==n-1&&j==n-1){
                    return i;
                }
                if(i==j){
                    continue;
                }
                if(s[i]==s[j]){
                    break;
                }
                if(j==n-1){
                    return i;
                }
            }
        }
        return -1;
    }
};