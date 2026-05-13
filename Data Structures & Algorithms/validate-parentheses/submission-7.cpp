class Solution {
public:
    bool isValid(string s) {

        stack<char> brackets;
        /*  from second element, add into stack if open bracket
            if there is a closed bracket -- check if top() is opposite -- true -- pop   */
        
        for(int i = 0; i < s.length(); i++)
        {
            if(isCB(s[i]) && brackets.empty())
                return false;
            // if open bracket, add to stack
            else if(isOB(s[i]))
                brackets.push(s[i]);

            // if closed -- appropriate, remove from stack, -- not app, false
            else if(s[i]==')')
            {
                if(brackets.top()=='(')
                    brackets.pop();
                else
                    return false;
            }

            // if closed and appropriate, remove from stack, -- not app, false
            else if(s[i]==']')
            {
                if(brackets.top()=='[')
                    brackets.pop();
                else
                    return false;
            }

            // if closed and appropriate, remove from stack, -- not app, false
            else if(s[i]=='}')
            {
                if(brackets.top()=='{')
                    brackets.pop();
                else
                    return false;
            }
        }

        // finally if stack empty return true
        return brackets.empty();     
    }

    bool isOB(char c){
        return (c == '(' || c == '{' || c == '[');
    }
    bool isCB(char c){
        return (c == ')' || c == '}' || c == ']');
    }
};
