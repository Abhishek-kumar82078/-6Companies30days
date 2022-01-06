#include<bits/stdc++.h>
using namespace std;

 class Solution {
public:
    int numDecodings(string a) {
        long long int pro=1,xprev=1,prev=1,mod=10e9 +7;
		    int n=a.size();
		    if(n==1 && a[0]!='0')
		     return 1;
		    if(a[0]=='0')
		     return 0;
		    for(int i=1;i<a.size();i++)
		    {
		        if(a[i]=='0' )
		        {
		            if(a[i-1]=='0')
		             return 0;
		            else if(a[i-1]>'2')
		             return 0;
		            continue;
		        }

		        else if(i+1<n && (a[i]=='1' || a[i]=='2') && a[i+1]=='0')
		         {
		             pro=(pro*prev)%mod;

		             prev=1;
		             xprev=1;
		         }
		         else if(( a[i-1]=='1') || (a[i-1]=='2' && (a[i]>'0' && a[i]<'7')))
		          {
		              if(prev==xprev)
		               prev=2;
		              else
		              {
		              long long int temp=xprev;
		              xprev=prev;
		              prev=(xprev+temp)%mod;
		              }
		          }
		          else
		          {
		             pro=(pro*prev)%mod;

		             prev=1;
		             xprev=1;
		          }
		    }
		   pro=(pro*prev)%mod;

		    return (int)pro%mod;
    }
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.numDecodings(str);
		cout << ans << "\n";
	}
	return 0;
}
