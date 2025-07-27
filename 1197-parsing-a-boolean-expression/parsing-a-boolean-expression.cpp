class Solution {
public:
    bool parseBoolExpr(string expression) {
        int len = expression.size();
        stack<char> stk;

        for(int i = 0 ; i < len ; i++) {
            char ch = expression[i];

            if(ch != ')' && ch != ',') {
                stk.push(ch);
                continue;
            }

            if(ch == ')') {
                vector<bool> bool_vals;

                while(stk.top() != '(') {
                    char symbol = stk.top(); stk.pop();
                    if(symbol == 't') bool_vals.push_back(true);
                    else bool_vals.push_back(false);
                }

                stk.pop();

                char operator_char = stk.top(); stk.pop();

                bool eval = bool_vals[0];

                if(operator_char == '&') {
                    for(int j = 1 ; j < bool_vals.size() ; j++)
                        eval = eval & bool_vals[j];
                }
                else if(operator_char == '|') {
                    for(int j = 1; j < bool_vals.size(); j++)
                        eval = eval | bool_vals[j];
                }
                else {
                    eval = !eval;
                }

                stk.push(eval ? 't' : 'f');
            }
        }

        return stk.top() == 't';
    }
};