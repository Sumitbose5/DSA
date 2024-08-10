#include <iostream>
#include <stack>
using namespace std;

// Function to reverse a string using a stack
string reverseString(string &str) {
    stack<char> st;     
    string reversed;      

    // Push all characters of the string onto the stack
    for (auto s : str) {
        st.push(s);
    }

    // Pop characters from the stack to form the reversed string
    while (!st.empty()) {
        reversed.push_back(st.top()); 
        st.pop();                    
    }

    return reversed;  
}

int main() {
    string s = "aeroplane";  
    string ans = reverseString(s);  
    cout << "Original String : " << s << endl;  
    cout << "Reversed String : " << ans << endl;
    return 0;
}
