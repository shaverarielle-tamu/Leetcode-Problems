#include <iostream>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int max = 0;
        string already = "";
        for (int i=0;i<s.size();++i){
            length = 0;
            for(int j=i;j<s.size();++j){
                if(already.find(s[j])==string::npos){
                    length+=1;
                    already+=s[j];
                    if (length>max) {
                        max=length;
                    }
                }
                else {
                    if (length>max) {
                        max=length;
                    } 
                    already="";
                    break;
                }
            }
        }
        return max;
    }
};