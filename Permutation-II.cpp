/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/

#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define all(c) c.begin(), c.end()
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<vector<ll>>ans;


void permutation(vector<ll> &nums, int idx)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        permutation(nums, idx + 1);
        swap(nums[i], nums[idx]);
    }
    // return ans;
}
vector<vector<ll>> permuteUnique(vector<ll> &nums)
{
    permutation(nums, 0);
    set<vector<ll>> s;
    for (int i = 0; i < ans.size(); i++)
    {
        s.insert(ans[i]);
    }
    vector<vector<ll>> v;
    for (auto val : s)
    {
        v.push_back(val);
    }
    return v;
}

void Result()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<ll>> a = permuteUnique(v);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    FAST int test = 1;
    // cin>>test;
    while (test--)
    {
        Result();
    }
    return 0;
}
