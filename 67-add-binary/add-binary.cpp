#include <string>
#include <algorithm>

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        // Loop until all digits and any leftover carry are processed
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // Append the bit (0 or 1) to result
            ans += to_string(sum % 2);

            // Update carry for next position (0 or 1)
            carry = sum / 2;
        }

        // Reverse to get the correct most-to-least significant order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};