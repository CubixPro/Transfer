#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string originalDigits(string s) {
        multiset<char> letter;
        for(int i = 0 ; i < s.length() ; i++){
            letter.insert(s[i]);
        }
        string str = "";
        if(letter.find('z') != letter.end()){
            str = str + "0";
            letter.erase(letter.lower_bound('z'));
            letter.erase(letter.lower_bound('e'));
            letter.erase(letter.lower_bound('r'));
            letter.erase(letter.lower_bound('o'));
        }
        if(letter.find('x') != letter.end()){
            str = str + "6";
            letter.erase(letter.lower_bound('s'));
            letter.erase(letter.lower_bound('i'));
            letter.erase(letter.lower_bound('x'));
        }
        if(letter.find('g') != letter.end()){
            str = str + "8";
            letter.erase(letter.lower_bound('e'));
            letter.erase(letter.lower_bound('i'));
            letter.erase(letter.lower_bound('g'));
            letter.erase(letter.lower_bound('h'));
            letter.erase(letter.lower_bound('t'));
        }
        if(letter.find('s') != letter.end() && letter.find('v') != letter.end()){
            str = str + "7";
            letter.erase(letter.lower_bound('s'));
            letter.erase(letter.lower_bound('e'));
            letter.erase(letter.lower_bound('v'));
            letter.erase(letter.lower_bound('e'));
            letter.erase(letter.lower_bound('n'));
        }
        if(letter.find('v') != letter.end()){
            str = str + "5";
            letter.erase(letter.lower_bound('f'));
            letter.erase(letter.lower_bound('i'));
            letter.erase(letter.lower_bound('v'));
            letter.erase(letter.lower_bound('e'));
        }
        if(letter.find('w') != letter.end()){
            str = str + "2";
            letter.erase(letter.lower_bound('t'));
            letter.erase(letter.lower_bound('w'));
            letter.erase(letter.lower_bound('o'));
        }
        if(letter.find('i') != letter.end()){
            str = str + "9";
            letter.erase(letter.lower_bound('n'));
            letter.erase(letter.lower_bound('i'));
            letter.erase(letter.lower_bound('n'));
            letter.erase(letter.lower_bound('e'));
        }
        if(letter.find('n') != letter.end()){
            str = str + "1";
            letter.erase(letter.lower_bound('o'));
            letter.erase(letter.lower_bound('n'));
            letter.erase(letter.lower_bound('e'));
        }
        if(letter.find('f') != letter.end()){
            str = str + "4";
            letter.erase(letter.lower_bound('f'));
            letter.erase(letter.lower_bound('o'));
            letter.erase(letter.lower_bound('u'));
            letter.erase(letter.lower_bound('r'));
        }
        if(!letter.empty()){
            str = str + "3";
        }
        sort(str.begin(), str.end());
        return str;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
 string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().originalDigits(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}