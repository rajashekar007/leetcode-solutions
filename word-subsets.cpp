/*
* https://leetcode.com/problems/word-subsets/
* Solution : Straight forward iteration across strings
* Runtime : O(max(sizeof(A)*maxLen(A),sizeof(B)*maxLen(B)))
*/
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int cnt[26]={};
        vector<string> ans;
        for(string &b:B)
        {
          int tmpcnt[26]={};
          for(char &c:b)
          {
            tmpcnt[c-'a']++;
            cnt[c-'a']=max(cnt[c-'a'],tmpcnt[c-'a']);
          }
        }
        for(string &a:A)
        {
          int tmpcnt[26]={};
          for(char &c:a)
          {
            tmpcnt[c-'a']++;
          }
          bool incl=true;
          for(int i=0;i<26;i++)
          {
            if(cnt[i] && cnt[i]>tmpcnt[i])
            {
              incl=false;
              break;
            }
          }
          if(incl)ans.push_back(a);
        }
        return ans;
    }
};