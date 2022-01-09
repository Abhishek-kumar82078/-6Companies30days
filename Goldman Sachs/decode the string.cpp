#include<bits/stdc++.h>

using namespace std;

class Solution{
public:

     string next(string s,int l,int r,int n)
    {
        string ans="";
        bool f=true;
        for(int i=l;i<=r;i++)
         if(s[i]=='[')
          f=false;
        if(f)
        {
            string m=s.substr(l,r-l+1);
            return m;
        }

        int c=0;
        int num=0;
        int left;
        int right;
        bool flag=true;
        for(int i=l;i<=r;i++)
        {

            if(s[i]=='[')
            {
                if(c==0)
                 {
                     left=i+1;
                    //  num=s[i-1]-'0';
                     flag=false;
                 }
                c++;

            }
            else if(s[i]==']')
            {
                c--;
                string w="";
                if(c==0)
                 {

                    right=i-1;
                    flag=true;
                    w=next(s,left,right,num);
                    // cout<<"up"<<num<<w<<endl;
                    if(num>0 && w!="")
                    {
                    while(num--)
                       ans+=w;
                      num=0;
                    }
                 }

            }
            else if(!isdigit(s[i]) && flag)
             ans+=s[i];
            else if(isdigit(s[i]) && flag)
             {
                 int dig=s[i]-'0';
                 num=num*10+dig;
             }
        }
        return ans;
    }
    string decodedString(string s){

         string ans="";

        int c=0;
        int num=0;
        int left;
        int right;
        bool flag=true;
        for(int i=0;i<=s.size();i++)
        {

            if(s[i]=='[')
            {
                if(c==0)
                 {
                     left=i+1;
                    //  num=s[i-1]-'0';
                     flag=false;
                 }
                c++;

            }
            else if(s[i]==']')
            {
                c--;
                string w="";
                if(c==0)
                 {
                     right=i-1;
                     flag=true;
                     w=next(s,left,right,num);
                    //   cout<<w<<endl;
                     while(num--)
                      ans+=w;
                       num=0;
                 }

            }
            else if(!isdigit(s[i]) && flag)
             ans+=s[i];
              else if(isdigit(s[i]) && flag)
             {
                 int dig=s[i]-'0';
                 num=num*10+dig;
             }
        }
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
