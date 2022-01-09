#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2==1)
         return false;
        if(k==1)
            return true;

        int n=nums.size();
        int arr[k]={0};
        for(int i=0;i<nums.size();i++)
         {
             nums[i]=nums[i]%k;
             arr[nums[i]]++;
         }
        //  for(int i=0;i<k;i++)
        //   cout<<arr[i];
         int l=1,r=k-1;
         if(arr[0]%2!=0)
          return false;
         while(l<=r)
         {
             if(l==r)
             {
                 if((l+r)%k==0 || arr[l]==0)
                  {
                      if(arr[l]%2==0)
                       {
                          return true;
                       }
                      else
                       return false;
                  }
                  else
                   return false;
             }
             else if(arr[l]==0)
              l++;
             else if(arr[r]==0)
              r--;
             else
             {
                 if((l+r)%k==0)
                  {
                      if(arr[l]==arr[r])
                       {
                           l++;
                           r--;

                       }
                      else
                       return false;
                  }
                  else
                   return false;
             }
         }

         if(arr[l]==arr[r])
          return true;
         return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
