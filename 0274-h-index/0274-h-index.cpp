class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h = 0;
        sort(citations.begin(), citations.end(), greater<int>());   //sort in descendin order by greater<int>()
        for(int i=0; i<n; i++){
            if( i+1 <= citations[i]){
                h = i+1;       // for every citstion[i] if i+1 is smaller
            }else{
                break;
            }
        }
        return h;
    }
};