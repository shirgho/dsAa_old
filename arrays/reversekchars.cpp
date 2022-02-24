#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    static string reverseStr(string s, int k) {
        // reverse k characters, then count to 2k characters, and then reverse next k characters, until string is at end
        
        int size = s.length();
        
        if(k > size) 
            k = size;

        int i = 0;
        while(i < size - 1){
            int j = i;
            int l = i + k - 1;
            for(; j < l; j++, l--){
                swap(s[j], s[l]);
            }
            i += 2*k;
        }
        
        return s;
    }
};

int main(int args, char ** argc)
{
    string r = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
    int k = 39;

    string s = Solution::reverseStr(r, k);
    cout << s << endl;



}

 