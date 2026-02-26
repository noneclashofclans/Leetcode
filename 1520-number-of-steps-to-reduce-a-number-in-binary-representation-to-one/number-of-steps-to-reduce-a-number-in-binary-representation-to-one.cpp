class Solution {
public:
    int numSteps(string s) {
        int steps = 0;

        int n = s.size();


        // 13: "1101" -> odd -> add 1
        // 14: "1110" -> even -> /2
        // 7: "0111" -> odd -> add 1 
        // 8: "1000" -> even -> /2
        // 4: "0100" -> even -> /2 
        // 2: "0010" -> even -> /2 ans: 1

        int carry = 0;

        for (int i = n-1; i > 0; i--){
            if ((s[i] - '0' + carry) % 2 == 0){
                steps++;
            }
            else {
                steps += 2;
                carry = 1;
            }
        }

        return steps + carry;
    }
};