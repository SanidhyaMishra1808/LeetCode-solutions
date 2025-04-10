class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sabhi intervals ko unke start time ke hisaab se sort kar rahe hain
        sort(intervals.begin(), intervals.end());

        // Pehla interval ka end time ko store kar liya
        int endingTime = intervals[0][1];
        int cnt = 0;

        for (int i = 1; i < intervals.size(); i++) {
            // Agar current interval ka start time pehle wale ke end time se chhota hai,
            // toh overlap ho raha hai
            if (intervals[i][0] < endingTime) {
                cnt++;
                // Dono me se jis ka end time chhota hai usko rakhna better hai
                // taaki aage ke intervals se kam overlap ho
                endingTime = min(endingTime, intervals[i][1]);
            } else {
                // Agar koi overlap nahi hai, toh endingTime ko update kar do
                endingTime = intervals[i][1];
            }
        }
        return cnt;
    }
};
