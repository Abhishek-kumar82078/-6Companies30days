#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, int nums[],int n) {
        int l=0,r=0;
        int mn=100001;
        long long sum=0;

        while(r<n)
        {
            sum+=nums[r];
            if(sum>=target)
            {
                while(l<=r)
                {
                    if(sum-nums[l]>=target)
                         sum-=nums[l++];
                    else
                         break;
                }
                mn=min(mn,r-l+1);
            }
            r++;
        }
         if(sum>=target)
            {
                while(l<=r)
                {
                    if(sum-nums[l]>=target)
                         sum-=nums[l++];
                    else
                         break;
                }
                mn=min(mn,r-l+1);
            }
        if(mn==100001)
            return 0;
         return mn;

    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        cin>>target;
        int n;
        cin>>n;
        int nums[n];
        for(int i=0;i<n;i++)
         cin>>nums[i];
        Solution ob;
        cout << ob.minSubArrayLen(target,nums,n) << endl;
    }
    return 0;
}
