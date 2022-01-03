#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n,m,k;
 cin>>n>>m>>k;

 m=m%n;
 if(m==0)
  cout<<(k==1?n:k-1);
 else
  cout<<(n+k+m-1)%n;
 return 0;
}
