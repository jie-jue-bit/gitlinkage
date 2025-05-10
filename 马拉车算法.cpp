#include <iostream>
#include <vector>
#include <string>
using namespace std;

string preprocess(const string& s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    return t;
}

string longestPalindrome(const string& s) {
    if (s.empty()) return "";
    
    string t = preprocess(s);
    int n = t.size();
    vector<int> p(n, 0);
    int c = 0, r = 0;
    int maxLen = 0, centerIndex = 0;
    
    for (int i = 0; i < n; ++i) {
        int mirror = 2 * c - i;
        if (i < r) p[i] = min(r - i, p[mirror]);
        
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
            ++p[i];
        }
        
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
        
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }
    
    return s.substr((centerIndex - maxLen) / 2, maxLen);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}
