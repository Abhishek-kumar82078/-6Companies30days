#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string printMinNumberForPattern(string s){
        int n=s.size();
        int i=0,l=0,mn=0;
        string ans="";
        bool f=true;
        if(s[0]=='I')
         {
             ans+=to_string(++mn);
             f=false;
         }
        while(i<n-1)
        {
            if(s[i]=='D')
            {
                if(s[i+1]=='I')
                {
                    int j=i;
                    if(f)
                    {
                        j++;
                        f=false;
                    }
                    string a="";
                    while(j>=l)
                    {
                        ++mn;
                        a=to_string(mn)+a;

                        j--;
                    }
                    ans+=a;
                    l=i+1;

                }
            }
            else
            {
                if(s[i+1]=='I')
                 {
                     ans+=to_string(++mn);
                 }
                 else
                  l=i;
            }
            i++;
        }
        if(s[i]=='D')
        {
             int j=i;
             if(f)
              j++;
                    string a="";
                    while(j>=l)
                    {
                        ++mn;
                        a=to_string(mn)+a;
                        j--;
                    }
                    ans+=a;
        }
        else
         ans+=to_string(++mn);
         return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0;
}
