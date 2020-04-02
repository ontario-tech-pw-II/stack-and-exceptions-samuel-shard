// RPN Calculator Exception Handling 
// Samuel Shard, 100745640

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

    string in;
    stack<string> st;   // stack definition

    cin >> in;
	try{
		while(in != "q"){

			if(is_str_digit(in)){
				// if digit it input, push it onto the stack
				st.push(in);
			}

			else if(is_str_operator(in)){
				// throw error if an operator is called and stack has less than 2 digits on it
				if(st.size() < 2){
					throw 2;
				}	
				
				value1 = stoi(st.top());
				st.pop();
				value2 = stoi(st.top());
				st.pop();

				switch(in[0]){
					case '+':
					//if plus operator, convert string values to integers and push sum to stack
						value3 = value2 + value1;
						break;

					case '-':
					//if minus operator, subtract and push to stack
						value3 = value2 - value1;
						break;

					case '*':
					//if multiply operator, multiply and push to stack
						value3 = value2 * value1;
						break;

					case '/':
					//if divide operator, divide and push to stack
						value3 = value2 / value1;
						break;
				}
				st.push(to_string(value3));
			}//end of else if
			
			//if not digit or operator, throw error 3
			else{
				throw 3;
			}

			cin >> in;
		}//end of while loop
		if(st.size()!=1){
			//After were  done, there should only be 1 answer on stack
			throw 1;
		}
		cout << "The answer is : " << st.top() << endl;

	}//end of try block
	catch(int e){
		switch(e){
			case 1:
				cout << "There should only be 1 answer left on stack.\n";
				return 1;
			case 2:
				cout <<"There are not 2 operands to perform operation on.\n";
				return 1;
			case 3:
				cout <<"Unexpected input. Please enter +,-, *, /, or an integer.\n";
				return 1;
		}

	}
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