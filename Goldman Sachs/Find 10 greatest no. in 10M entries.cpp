#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
  cin>>a[i];
 int ans[10]={0};
 for(int i=0;i<n;i++)
 {
  if(ans[0]<a[i])
  {
   int j=1;
   while(j<10)
   {
    if(ans[j]<a[i])
    {
     ans[j-1]=ans[j];
     if(j==9)
      ans[j]=a[i];
    }
    else
     {
         ans[j-1]=a[i];
         break;
     }
    j++;
   }

  }
 }
 for(int i=0;i<10;i++)
  cout<<ans[i]<<" ";
 return 0;
}
