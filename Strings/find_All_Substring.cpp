#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Method 1 --->
vector<string> method1(string s){
    int n = s.length();
    vector<string> ans;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            ans.push_back(s.substr(i, j-i+1));
        }
    }
    return ans;
}

// Method 2 --->
vector<string> method2(string s){
    int n = s.length(); 
    vector<string> ans;

    for(int i=0; i<n; i++){
        string temp = "";
        for(int j=i; j<n; j++){
            temp += s[j];
            ans.push_back(temp);
        }
    }
    return ans;
}

int main(){

  string s;
    cout << "Enter String : ";
    getline(cin, s);
    vector<string> ans = method2(s);

    cout << "All Possible Substrings for " << s << " : \n";
    for(auto i : ans){
        cout << i << endl;
    }
  
  return 0;
}
