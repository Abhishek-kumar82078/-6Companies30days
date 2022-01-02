#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& s) {

        vector<vector<string>>ans;
        vector<string>inserted_vec;
        map<int,vector<string>>mp;
        int index=0;
        for(int i=0;i<s.size();i++)
        {
            string temp=s[i];
            sort(temp.begin(),temp.end());
            auto  it=find(inserted_vec.begin(),inserted_vec.end(),temp);
            if(it == inserted_vec.end())
            {
                mp[index]={};
                inserted_vec.push_back(temp);
                mp[index].push_back(s[i]);
                index++;
            }
            else
            {
                int x=it-inserted_vec.begin();
                mp[x].push_back(s[i]);
            }

        }
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i];
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
