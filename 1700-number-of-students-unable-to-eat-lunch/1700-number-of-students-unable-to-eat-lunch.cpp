class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero = 0, one = 0;
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 0) {
                zero++;
            } else {
                one++;
            }
        }
        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 1 && one > 0) {
                one--;
                continue;
            } else if (sandwiches[i] == 0 && zero > 0) {
                zero--;
                continue;
            } else {
                return sandwiches.size() - i;
            }
        }
        return 0;
    }
};