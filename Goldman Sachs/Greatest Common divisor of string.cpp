#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string gcdOfStrings(string s1, string s2) {

        while( (s1.size() >0) && (s2.size() >0 ) )
        {
            string temp=s1;
            s1=s1.size()>=s2.size()?s1:s2;
            if(s1!=temp)
                s2=temp;
            int i=0,j=0,n1=s1.size(),n2=s2.size();
            while(i<s1.size())
            {
                if(s1[i]==s2[j] && j==n2-1)
                {

                    s1.erase(0,n2);

                    i=-1;
                    j=-1;
                }
                else if(s1[i]!=s2[j])
                    break;
              i++;
              j++;
            }
            if(s1.size()==0)
                return s2;
            if(n1==s1.size())
                return "";

        }
        return "";
    }
};

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    Solution ob;
    cout<<ob.gcdOfStrings(s1,s2);
    return 0;
}
