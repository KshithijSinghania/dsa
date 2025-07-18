class Solution {
public:
    string largestPalindromic(string num) {
        map<char, int> freq;
        for (char c : num) {
            freq[c]++;
        }

        string left = "", center = "";

        // From '9' to '0' to build the largest possible number
        for (char digit = '9'; digit >= '0'; digit--) {
            if (freq[digit] % 2 == 1 && center == "")
                center = digit;  // pick the largest odd-count digit as center
            int pairs = freq[digit] / 2;
            left.append(pairs, digit);
        }

        // Remove leading zeros
        int non_zero = 0;
        while (non_zero < left.size() && left[non_zero] == '0') {
            non_zero++;
        }

        if (non_zero == left.size()) {
            // All zeros: only allow center if it exists or return "0"
            return center == "" ? "0" : center;
        }

        // Trim leading zeros from left half
        left = left.substr(non_zero);

        string right = left;
        reverse(right.begin(), right.end());

        return left + center + right;
    }
};
