class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int i = 0, j = skill.size() - 1;
        int s = skill[i] + skill[j];
        long long chem = 0;
        while (i < j) {
            int currSkill = skill[i] + skill[j];
            if (currSkill != s) {
                return -1;
            }
            chem += (long long)(skill[i]) * (long long)(skill[j]);
            i++;
            j--;
        }
        return chem;
    }
};