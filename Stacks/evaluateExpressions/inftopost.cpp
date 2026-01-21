/*  INFIX TO POSTFIX (REVERSE POLISHED) NOTATION

infix : operators between the operands
postfix: operators after the operands

APPROACH:
- if the scanned char is an operand, print it immediately
- if the scanned char is operator:
    - if the priority of operator is greater than the operator in the stack, or the 
    stack is empty, or the stack contains '(', push the operator into the stack

    - otherwise, pop all operators from the stack with higher or equal priority than the 
    scanned operator, then push the scanned operator onto the stack

- if the scanned char is '(', push to the stack
- if the scanned char is ')', pop the stack and output the operators until a '(' is encountered,
    and discard both the parentheses
- repeat steps until the expression has been scanned
- print the output
- finally, pop and print all the remaining operators in the stack until it is empty

TC - O(N)
SC - O(N)
*/

#include <bits/stdc++.h>

// func to return priority or precedence of operators
int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '/' || c == '*'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

// the main function to convert the infix to postfix expression
void infixToPostfix(std::string s){
    std::stack<char> st;
    std::string result;

    for(int i=0; i<s.size(); i++){
        char c = s[i];

        // if the scanned char is operand, add it to the result string
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result += c;
        }

        // if the scanned operator is an '(', push it to the stack
        else if(c == '('){
            st.push('(');
        }

        // if the scanned char is ')' , pop from stack until '(' is encountered
        else if(c == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();   //pop the '(' from the stack
        }
        // if an operator is scanned
        else{
            while(!st.empty() && prec(s[i]) <= prec(st.top())){
                result += st.top();
                st.pop();
            }
            st.push(c); // push the current operator to the stack
        }
    }
    // pop all the remaining elements from the stack
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    std::cout<<"Postfix expression for "<<s << " is: "<< result<<std::endl;
}

int main(){
    std::string exp = "(p+q)*(m-n)";
    infixToPostfix(exp);
    return 0;
}