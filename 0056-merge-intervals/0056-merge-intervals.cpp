class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // similar to previous soln but with O(N) instead of O(2N) Log(N)
        int n = intervals.size();

        // 1. Sort the matrix by 1st element
        sort(intervals.begin(), intervals.end());

        // 2. create additional list to append into
        vector<vector<int>> intervals2;

        // 3. adding in new list
        for(int i=0; i<n; i++){

        // if list is empty or the element we are pushing does not overlap
            if(intervals2.empty() || intervals[i][0] > intervals2.back()[1]){
                intervals2.push_back(intervals[i]);
            }else{
        // if it overlaps than just keep [(this),__] and replace with the max element at [x, _?_] here
                intervals2.back()[1] = max(intervals2.back()[1], intervals[i][1]);
            }
        }

        // 4. return the ans list
        return intervals2;
    }
};