class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, ai = 0, j = i+1;
        while(i < chars.size()){
            while(j < chars.size() && chars[i] == chars[j]){
                j++;
            }
            chars[ai++] = chars[i];
            int count = j - i;
            if(count > 1){
                // convrting int to string (12 = "1","2")
                string ct = to_string(count);
                for(char ch : ct){
                    chars[ai++] = ch;
                }
            }
            i = j;
        }
        return ai;
    }
};