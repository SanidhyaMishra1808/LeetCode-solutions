class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) {
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }
        string result = "";

        while (!pq.empty()) {
            auto [currCount, currChar] = pq.top();
            pq.pop();
            
            if (result.size() >= 2 && result[result.size() - 1] == currChar && result[result.size() - 2] == currChar) {
                if (pq.empty()) {
                    break;
                }
                auto [nextCount, nextChar] = pq.top();
                pq.pop();

                result.push_back(nextChar);
                nextCount--;
                if (nextCount > 0) {
                    pq.push({nextCount, nextChar});
                }

                pq.push({currCount, currChar});
            } else {
                result.push_back(currChar);
                currCount--;
                if (currCount > 0) {
                    pq.push({currCount, currChar});
                }
            }
        }
        return result;
    }
};