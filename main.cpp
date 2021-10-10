#include <iostream>
#include <stack>
using namespace std ;

bool Pair(char open , char close ){
    if (open == '(' && close == ')' )
        return true ;
    else if (open == '{' && close == '}')
        return true ;
    else if(open == '[' && close == ']')
        return true ;
    else
        return false ;
}

bool Balanced(string expression){
    stack<char> brackets ;

    for (int i = 0; i <expression.length(); ++i) {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            brackets.push(expression[i]) ;
        } else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if(brackets.empty()){
                return false ;
            }
            else if(Pair(brackets.top() , expression[i]) == false)
            {
                return false ;
            }
            else{
                brackets.pop() ;
            }
        }
    }

    if (brackets.empty()){
        return true ;
    } else
        return false ;

}

int main() {
    string expression ;
    cout << "enter your expression :  " ;
    cin >> expression ;

    if (Balanced(expression))
        cout << "is balanced " ;
     else
        cout << "not balanced" ;


    return 0;
}