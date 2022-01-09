#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
int find(int k,int *arr,int n)
{
    for(int i=0;i<n;i++)
     if(arr[i]==k)
      return i;
     return -1;
}
    int *findTwoElement(int *arr, int n) {
        int i=0;
        int *ans=new int[2];
        while(i<n)
        {

            if(arr[i]==i+1)
             {
                 i++;
                 continue;
             }
             else if(arr[abs(arr[i])-1]==arr[i])
              {//cout<<i<<arr[i]<<endl;
                  ans[0]=arr[i];
                  int k=find(i+1,arr,n);
                  if(k==-1)
                  {
                  ans[1]=i+1;
                  return ans;
                  }
                  else
                  {
                      arr[k]=arr[i];
                      arr[i]=i+1;
                      i++;

                  }
              }
              else
               {
                  int temp=abs(arr[i]);
                  arr[i]=arr[temp-1];
                  arr[temp-1]=temp;
               }
            //   i++;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
