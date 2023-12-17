#include <iostream>
#include <stack>
using namespace std;

// #1
void removeNonAlphaNum(stack<char>& s)
{
	stack<char> temp;
	while (!s.empty()) {
		char ch = s.top();
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
		{
			temp.push(ch);
		}
		s.pop();
	}
	while (!temp.empty()) {
		s.push(temp.top());
		temp.pop();
	}

}


// #2
stack<char> st;

// initializing a string to store
// result of reversed stack
string ns;

void insert_at_bottom(char x)
{

    if (st.size() == 0)
        st.push(x);

    else
    {
        // When the stack becomes empty, the
        // st.size() becomes 0, the above if
        // part is executed and the item is
        // inserted at the bottom

        char a = st.top();
        st.pop();
        insert_at_bottom(x);

        // pushes items held once item is inserted
        // at the bottom
        st.push(a);
    }
}

// reverses the stack
void reverse()
{
    if (st.size() > 0)
    {

        // Hold all items in function and
        // call stack until end of the stack
        char x = st.top();
        st.pop();
        reverse();

        // Insert all the items held
        //from the bottom to top
        insert_at_bottom(x);
    }
}


// #3
int balancedDelimeter(string str)
{
    stack<char> s; //stack using standard template library
    char s1, s2, s3;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') //if the value is any kind of bracket
        {
            s.push(str[i]);
        }
        else //if first bracket is closing bracket
        {
            switch (str[i])
            {
            case ']':
                s3 = s.top();
                s.pop();
                if (s3 == '(' || s3 == '{')
                    cout << "Braces, Parenthesis and Brackets are properly not Balanced\n";
                break;
            case '}':
                s2 = s.top();
                s.pop();
                if (s2 == '(' || s2 == '[')
                    cout << "Braces, Parenthesis and Brackets are properly not Balanced\n";
                break;
            case ')':
                s1 = s.top();
                s.pop();
                if (s1 == '{' || s1 == '[')
                    cout << "Braces, Parenthesis and Brackets are properly not Balanced\n";
                break;
            }
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}
int main()
{
    string str;
    cin >> str;
    if (balancedDelimeter(str))
        cout << "Braces, Parenthesis and Brackets are properly Balanced\n";
    else
        cout << "Braces, Parenthesis and Brackets are properly not Balanced\n";
    return 0;
}