//https://leetcode.com/problems/string-to-integer-atoi/

    int myAtoi(string s) {

        int i = 0;
        int sign = 1;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        while (s[i] == '0') {
            i++;
        }
        long long res = 0;
        for (int j = i; j < s.size(); ++j) {
            if (s[j] > '9' || s[j] < '0') {
                break;
            }
            int no = s[j] - '0';
            res = res * 10 + no;
            if (res * sign > INT_MAX) {
                return INT_MAX;
                break;
            }
            if (res * sign < INT_MIN) {
                return INT_MIN;
                break;
            }
        }
        return res * sign;
    }
