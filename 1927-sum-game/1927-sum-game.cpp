class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int s1 = 0, s2 = 0;
        int q1 = 0, q2 = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                q1++;
            else
                s1 += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                q2++;
            else
                s2 += num[i] - '0';
        }
        if ((q1 + q2) % 2 == 1)
            return true;

        int diff = s1 - s2;
        int qdiff = q1 - q2;

     
        return diff + 9 * qdiff / 2 != 0;
    }
};