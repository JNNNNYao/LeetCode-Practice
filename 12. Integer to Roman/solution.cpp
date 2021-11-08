class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int base[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int idx = 0;
        while(num != 0) {
            if (num >= base[idx]) {
                num -= base[idx];
                ans += roman[idx];
            }
            else {
                idx++;
            }
        }
        return ans;
    }
};