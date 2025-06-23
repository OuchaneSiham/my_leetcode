#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution 
{
public:
    string trimleadingzeros(const string &str)
    {
        size_t i;
        i = str.find('1');
        if(i == string::npos) return "0"; // nps means not found we mean here if we didnt found 1 we should return 0
        //else we will return from the position we have found 1 to the end 
        else return str.substr(i);
    }
    string addBinary(string a, string b)
    {
        a = trimleadingzeros(a);
        b = trimleadingzeros(b);
        // for(int i = 0; )
        if(a.size() > b.size())
            return addBinary(b, a);
        int k = b.size() - 1;
        int k2 = 
        
        
    }
};
int main()
{
    Solution s ;
     cout << s.trimleadingzeros("00000101") << endl;  // Output: 101
    cout << s.trimleadingzeros("00000000") << endl;  // Output: 0
    cout << s.trimleadingzeros("!!!!!00000!!!!!!!!!1010") << endl;      // Output: 1010
}