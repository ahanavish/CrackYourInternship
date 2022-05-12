class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int, int> m;
        m[0] = 1; // because initial cumulative sum = 0 and that sum%k will be equal to 0 always
        int prefix_sum = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            prefix_sum += nums[i];
            int rem = prefix_sum % k;
            if (rem < 0)
                rem += k;

            ans += m[rem];
            m[rem]++;
        }

        return ans;
    }
};