/*  INFIX TO PREFIX (POLISHED) NOTATION

infix : operators between the operands
postfix: operators before the operands

APPROACH:
1. reverse the infix expression
2. use a stack to store operators
3. traverse the reversed infix expression:
    - if operand, append to result
    - if '(' -> push to stack
    - if ')' -> pop from stack until a '(' is encountered , then discard this '(' too

4. if the operator op1 is encountered:
    - while stack is not empty and
        precedence(op1) < precedence(stack.top()) OR
        precedence(op1) == precedence(stack.top()) AND op1 != '^'      i.e. pop on equal precedence only if the operator is not ^
        -> pop from stack and append to the result
    - Push op1 to stack

    (NOTE: '^' is right-associativem so do NOT pop on equal precedence)

5. After traversal, pop all remaining operators from stack to result
6. Reverse the result to get the prefix expression

TC - O(N)
SC - O(N)
*/

#include <bits/stdc++.h>

// func to check if a char is an operator
bool isOperator(char c){
    return (!isalnum(c) && !isdigit(c)); // if the char is neither alphabetic or digit, its an operator
}

// function to return the precedence of operator
int prec(char C) {
    if (C == '-' || C == '+')  // Addition and subtraction have lowest precedence
        return 1;
    else if (C == '*' || C == '/')  // Multiplication and division have higher precedence
        return 2;
    else if (C == '^')  // Exponent operator has highest precedence
        return 3;
    return 0;
}

// func to convert reversed infix expression to postfix expression
std::string infixtoPostfix(std::string s){
    s = '(' + s + ')';  // add parenthese to handle edge cases
    int l = s.size();
    std::stack<char> st;
    std::string output;

    for(int i=0; i<l; i++){
        // if the scanned char is an operand, add it to output
        if(isalpha(s[i]) || isdigit(s[i])){
            output += s[i];
        }

        // if the scanned char is '(', push it to the stack
        else if(s[i] == '('){
            st.push('(');
        }

        // if the scanned char is ')', pop and output form the stack until an '(' is encountered
        else if(s[i] == ')'){
            while(st.top() != '('){
                output += st.top();
                st.pop();
            }
            st.pop();   // remove the '(' from the stack too
        }

        // if an operator is found
        else{
            if(isOperator(st.top())){
                if(s[i] == '^'){
                    // pop only higher prec operators
                    while(prec(s[i]) < prec(st.top())){
                        output += st.top();
                        st.pop();
                    }
                }
                else{
                    // pop higher or equal prec operator
                    while(prec(s[i]) <= prec(st.top())){
                        output += st.top();
                        st.pop();
                    }
                }
                // push current operator on stack
                st.push(s[i]);
            }
        }
    }
    // pop all remaining elements from the stack
    while(!st.empty()){
        output += st.top();
        st.pop();
    }
    return output;
}

// func to convert infix to prefix expression
std::string infToPrefix(std::string s){
    int l = s.size();

    // reverse the infix expression
    std::reverse(s.begin(), s.end());

    // replace the '(' with ')' and vice versa
    for(int i=0; i<l; i++){
        if(s[i] == '('){
            s[i] = ')';
            i++;
        }
        else if(s[i] == ')'){
            s[i] = '(';
            i++;
        }
    }

    std::string prefix = infixtoPostfix(s); //convert the modified infix to postfix

    // reverse the postfix expression to get the prefix
    std::reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main(){
    std::string s = "(p+q)*(c-d)";
    std::cout<<"Infix expression: "<<s<<std::endl;
    std::cout<<"Prefix expression: "<<infToPrefix(s)<<std::endl;
    return 0;
}