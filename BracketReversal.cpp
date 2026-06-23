#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReversalsToBalance(string expression) {

        int n = expression.length();

        // Odd length can never be balanced
        if (n % 2 != 0)
            return -1;

        int openBrackets = 0;
        int closeBrackets = 0;

        for (char ch : expression) {
            if (ch == '(') {
                openBrackets++;
            }
            else {
                if (openBrackets > 0) {
                    openBrackets--;
                } else {
                    closeBrackets++;
                }
            }
        }

        return (openBrackets + 1) / 2 +
               (closeBrackets + 1) / 2;
    }
};

int main() {

    string expression;
    cout << "Enter expression: ";
    cin >> expression;

    Solution solver;

    int result = solver.minReversalsToBalance(expression);

    if (result == -1)
        cout << "Cannot be balanced\n";
    else
        cout << "Minimum reversals required: " << result << endl;

    return 0;
}