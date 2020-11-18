#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

int eval(string str)
{
    char check = str[str.size()-1];
    stringstream ss(str);
    stack<string> s;
    string num;
    int a, b, result = 0;
    
    if( (check >= '1') && (check <= '9') ){
        return stoi(str);
    }

    do{
        ss >> num;
        if(num == "+"){
            a = stoi(s.top()); s.pop();
            b = stoi(s.top()); s.pop();
            result = a + b;
            s.push(to_string(result));
        }
        else if(num == "-"){
            a = stoi(s.top()); s.pop();
            b = stoi(s.top()); s.pop();
            result = a - b;
            s.push(to_string(result));
        }
        else if(num == "*"){
            a = stoi(s.top()); s.pop();
            b = stoi(s.top()); s.pop();
            result = a * b;
            s.push(to_string(result));
        }
        else if(num == "/"){
            a =stoi(s.top()); s.pop();
            b = stoi(s.top()); s.pop();
            result = a / b;
            s.push(to_string(result));
        }
        else s.push(num);

    }while(!ss.eof());

    return result;
} 

int main() {
    int i;
    string test_str[]={
        "1 2 *",
        "1 2 3 / +",
        "1 2 /",
    };

    for(i = 0; i < 3; i++){
        cout << eval(test_str[i]) << endl;
    }

    return 0;
}