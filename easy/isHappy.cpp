/*
* https://leetcode.com/problems/happy-number/
* Solution : Recrsive , can be solved using tortoise and hare
* Runtime : O(10*NumOfDigits)
*/
class Solution {
public:
    int sumSqDigits(int n)
    {
        int sum=0,dig;
        while(n)
        {
            dig = n%10;
            sum += dig*dig;
            n/=10;
        }
        return sum;
    }
    bool isHappyUtil(int n, unordered_set<int> &visited)
    {
        cout<<n<<endl;
        if(n==1)return true;
        if(visited.find(n)!=visited.end())return false;
        
        visited.insert(n);
        return isHappyUtil(sumSqDigits(n),visited);
    }
    bool isHappy(int n) {
        unordered_set<int> visited;
        return isHappyUtil(n, visited);
    }
};