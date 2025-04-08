class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        while(i < intervals.size()) {

            // Agar current interval ka end newInterval ke start se chhota hai
            // to iska matlab overlap nahi hai, aage badho
            if(intervals[i][1] < newInterval[0]) {
                i++;
            }

            // Agar current interval ka start newInterval ke end se bada hai
            // to iska matlab is position par hum newInterval insert kar sakte hai
            else if(intervals[i][0] > newInterval[1]) {
                intervals.insert(intervals.begin() + i, newInterval); // insert karo
                return intervals; // aur return kar do result
            }

            // Agar intervals overlap karte hain
            else {
                // newInterval ka start aur end update karo minimum aur maximum ke according
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);

                // current interval ko hata do kyunki ab wo merge ho chuka hai
                intervals.erase(intervals.begin() + i);
                // i ko increase mat karo kyunki naye updated newInterval ko dubara isi position par check karna hai
            }
        }

        // Agar newInterval ab tak insert nahi hua, to end mein push kar do
        intervals.push_back(newInterval);
        return intervals;
    }
};
