class Solution {
public:
    int digitSum(int a) {
        int sum = 0;
        while (a) {
            int ld = a % 10;
            sum += ld;
            a /= 10;
        }
        return sum;
    }

    long long squareSum(string a) {
        long long ans = 0;

        for (char ch : a) {
            int digit = ch - '0';
            ans += 1LL * digit * digit;
        }

        return ans;
    }

    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        map<string, long long> mapp;
        long long maxx = LLONG_MIN;
        string ans = "";

        string number = "";

        for (int i = 0; i < num; i++) {
            int digit = min(9, sum);
            number += to_string(digit);
            sum -= digit;
        }

        long long sqSum = squareSum(number);
        mapp[number] = sqSum;

        for (const auto &p : mapp) {
            if (p.second > maxx ||
                (p.second == maxx && p.first > ans)) {
                maxx = p.second;
                ans = p.first;
            }
        }

        return ans;
    }
};