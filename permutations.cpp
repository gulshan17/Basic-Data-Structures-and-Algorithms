#include <bits/stdc++.h>
using namespace std;

void generate_permutations(vector<vector<int>> &result, vector<int> &taken, vector<int> &curr, int n) {
    if(curr.size() == n) {
        result.push_back(curr);
    } else {
        for(int i = 1; i <= n; ++i) {
            if(!taken[i]) {
                taken[i] = 1;
                curr.push_back(i);
                generate_permutations(result, taken, curr, n);
                curr.pop_back();
                taken[i] = 0;
            }
        }
    }
}

void generate_permutations_v2(vector<vector<int>> &result, int index, vector<int> nums) {
    if(index == nums.size()) {
        result.push_back(nums);
    } else {
        generate_permutations_v2(result, index + 1, nums);
        for(int i = index + 1; i < nums.size(); ++i) {
            vector<int> temp = nums;
            temp[i] ^= temp[index] ^= temp[i] ^= temp[index];
            generate_permutations_v2(result, index + 1, temp);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> result;

    // vector<int> taken(n + 1, 0);
    // vector<int> curr;
    // generate_permutations(result, taken, curr, n);

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }

    generate_permutations_v2(result, 0, nums);

    for(auto r : result) {
        for(auto a : r) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}