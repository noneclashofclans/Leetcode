class Solution {
public:
    const int TARGET = 24;
    const double MOD = 1e-6;

    // double apply(double a, double b, char op) {
    //     if (op == '+') return a + b;
    //     if (op == '-') return a - b;
    //     if (op == '*') return a * b;
    //     if (op == '/') {
    //         if (fabs(b) < MOD) return 1e9; // invalid division
    //         return a / b;
    //     }
    //     return 0;
    // }

    bool solution (vector<double>& cardss){
        int n = cardss.size();
        if (n == 1) return (fabs(cardss[0] - TARGET)) < MOD;

        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                vector<double> rem;
                for (int k = 0; k < n; k++){
                    if (k != i && k != j){
                        rem.push_back(cardss[k]);
                    }
                }

                vector<double> candidates;
                candidates.push_back(cardss[i] + cardss[j]);
                candidates.push_back(cardss[i] - cardss[j]);
                candidates.push_back(cardss[j] - cardss[i]);
                candidates.push_back(cardss[i] * cardss[j]);

                if (fabs(cardss[j]) > MOD) candidates.push_back(cardss[i] / cardss[j]);
                if (fabs(cardss[i]) > MOD) candidates.push_back(cardss[j] / cardss[i]);

                for (double c : candidates){
                    rem.push_back(c);
                    if (solution(rem)) return true;
                    else rem.pop_back();
                }
            }
        }
        return false;
    }


    bool judgePoint24(vector<int>& cards) {
        // int n = cards.size();
        // vector<char> ops = {'+', '-', '*', '/'};

        // for (int i = 0; i < n; i++) {
        //     for (int j = i+1; j < n; j++) {
        //         // st1 = two chosen cards
        //         stack<double> st1;
        //         st1.push(cards[i]);
        //         st1.push(cards[j]);

        //         // st2 = remaining cards
        //         vector<double> st2;
        //         for (int k = 0; k < n; k++) {
        //             if (k != i && k != j) {
        //                 st2.push_back(cards[k]);
        //             }
        //         }

        //         // pop both from st1
        //         double a = st1.top(); st1.pop();
        //         double b = st1.top(); st1.pop();

        //         for (char op1 : ops) {
        //             double firstResult = apply(b, a, op1);

        //             // copy st2 for safety
        //             if (st2.size() < 2) continue;
        //             double c = st2[0];
        //             double d = st2[1];

        //             for (char op2 : ops) {
        //                 double secondResult = apply(c, d, op2);

        //                 for (char op3 : ops) {
        //                     double finalResult = apply(firstResult, secondResult, op3);
        //                     if (fabs(finalResult - TARGET) < MOD) {
        //                         return true;
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // return false;
        vector<double> cardss (cards.begin(), cards.end());
        return solution(cardss);
    }
};
