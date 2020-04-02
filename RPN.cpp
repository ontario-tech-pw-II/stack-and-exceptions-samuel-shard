// RPN calculator

#include <iostream> 
#include <string>
#include <stack> 

using namespace std;
bool is_str_digit(string);  // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string); // returns true if the input parameter is an operator character (e.g., "+", "*")

int main() 
{	
	//for inside switch statement
	int value1, value2, value3;
	string output;

    string in;
    stack<string> st;   // stack definition

    cin >> in;

    while(in != "q")
    {
        if(is_str_digit(in)){
            // if digit it input, push it onto the stack
			st.push(in);
        }
        else if(is_str_operator(in))
        {
            // throw error if an operator is called and stack has less than 2 digits on it
			if(st.size() < 2){
				cerr << "Stack size is less than 2."
				 << " Stack size is: " << st.size() << endl;
				 return 1;
			}
            switch(in[0])
            {
                case '+':
				//if plus operator, convert string values to integers and push sum to stack
					value1 = stoi(st.top());
					st.pop();
					value2 = stoi(st.top());
					st.pop();
                    value3 = value2 + value1;
					output = to_string(value3);
					st.push(output);
                    break;

                case '-':
				//if minus operator, subtract and push to stack
					value1 = stoi(st.top());
					st.pop();
					value2 = stoi(st.top());
					st.pop();
                    value3 = value2 - value1;
					output = to_string(value3);
					st.push(output);
                    break;

                case '*':
				//if multiply operator, multiply and push to stack
					value1 = stoi(st.top());
					st.pop();
					value2 = stoi(st.top());
					st.pop();
                    value3 = value2 * value1;
					output = to_string(value3);
					st.push(output);
                    break;

                case '/':
				//if divide operator, divide and push to stack
					value1 = stoi(st.top());
					st.pop();
					value2 = stoi(st.top());
					st.pop();
                    value3 = value2 / value1;
					output = to_string(value3);
					st.push(output);
                    break;

            }

            // add your code here

        }
        cin >> in;
    }
    cout << "The answer is : " << st.top() << endl;

    return 0; 
}

bool is_str_digit(string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
            if(!isdigit(s[i]))
                return false;
    }
    return true;
}
bool is_str_operator(string s)
{
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0]== '/'));
}