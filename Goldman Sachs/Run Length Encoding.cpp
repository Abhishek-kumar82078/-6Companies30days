#include <bits/stdc++.h>
using namespace std;

string encode(string src);

int main() {

	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;

		cout<<encode(str)<<endl;
	}
	return 0;
}




string encode(string src)
{
  int i=1;
  int cnt=1;
  string ans="";
  while(i<src.size())
  {
      if(src[i]==src[i-1])
       cnt++;
      else
      {
          ans+=src[i-1];
          ans+=to_string(cnt);
          cnt=1;
      }
      i++;
  }
  ans+=src[i-1];
  ans+=to_string(cnt);
  return ans;
}

