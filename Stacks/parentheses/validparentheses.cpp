/*  VALID PARENTHESES IN AN EXPRESSION
- open brackets must be closed by the same type of brackets
- open brackets must be closed in the correct order

- since we need to keep track of the last opening bracket becuz of the sequence, so we use stack becuz LIFO
TC - O(N), a single for loop is used
SC - O(N), N being the stack space
*/

#include <bits/stdc++.h>

class Solution{
public:
    // function to check if the input string has valid parentheses
    bool isValid(std::string s){
        std::stack<char> st;    // stack to store opening brackets

        for(auto it: s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);    // push opening brackets to stack
            }
            else{
                if(st.empty()) return false;    // no matching opening brackets
                char ch = st.top();
                st.pop();

                // check for matching pair
                if((it == ')' && ch == '(') ||
                    (it == '}' && ch == '{') ||
                    (it == ']' && ch == '['))
                    {continue;}
                else{
                    return false;
                }
            }
        }
        return st.empty();  // true if all brackets matched
    }  
};

int main(){
    Solution obj;
    std::string s = "()[{()]";
    if(obj.isValid(s)){
        std::cout<<"True"<<std::endl;
    }
    else{
        std::cout<<"False"<<std::endl;
    }
    return 0;
}