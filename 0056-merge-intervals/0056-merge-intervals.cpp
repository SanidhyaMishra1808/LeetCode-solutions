class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 1. Sort the matrix by 1st element
        sort(intervals.begin(), intervals.end());

        // 2. create additional list to append into
        vector<vector<int>> intervals2;

        // 3. adding in list
        int n = intervals.size();
        for(int i=0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(!intervals2.empty() && end <= intervals2.back()[1]){
                continue;
            }
            for(int j=0; j<n; j++){
                if(intervals[j][0] <= end){
                    end = max(end, intervals[j][1]);
                }else{
                    break;
                }
            }
            intervals2.push_back({start, end});
        }
        return intervals2;
    }
};