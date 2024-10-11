class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int>chair(n,-1);
        int tfat = times[targetFriend][0];

        sort(times.begin(), times.end());

        for(vector<int>& time : times){
            int arrival = time[0];
            int depart = time[1];

            for(int i=0; i<n; i++){
                if(chair[i] <= arrival){
                    chair[i] = depart;
                    if(arrival == tfat){
                        return i;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};