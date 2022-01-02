#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long pro=1,ans=0;
        int l=0,r=0;
        while(r<n)
        {
            pro*=a[r];
            if(pro<k)
             {
                 ans+=r-l+1;
                 r++;
             }
             else
             {
                 while(pro>=k && l<=r)
                  {
                      pro/=a[l];
                      l++;
                  }

                   ans+=(r++)-l+1;
             }

        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
