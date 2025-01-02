class Solution {
public:
    string findLine(int i, int j, int eachSpace, int extraSpace, vector<string>& words, int maxWidth) {
        string line;
        for (int k = i; k < j; k++) {
            line += words[k];
            if (k == j - 1) { // last word of the line
                continue;
            }
            for (int z = 0; z < eachSpace; z++) {
                line += " ";
            }
            if (extraSpace > 0) {
                line += " ";
                extraSpace--;
            }
        }
        while (line.length() < maxWidth) {
            line += " ";
        }
        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLength = 0;
            int j = i;
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            int gaps = j - i - 1;
            int remainingSpace = maxWidth - lineLength;
            int eachSpace = (gaps > 0) ? remainingSpace / gaps : 0;
            int extraSpace = (gaps > 0) ? remainingSpace % gaps : 0;

            if (j == n || gaps == 0) { // last line or single word line
                eachSpace = 1;
                extraSpace = 0;
            }

            result.push_back(findLine(i, j, eachSpace, extraSpace, words, maxWidth));
            i = j;
        }

        return result;
    }
};
