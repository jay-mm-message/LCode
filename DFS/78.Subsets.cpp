
#include <iostream>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int>         vi;

void show_vd(vi current);
void show_v(vi current);
void show_vv(vvi result);

void dfs_subset(vi nums, int index, vi &current, vvi &result) {

    result.push_back(current);

    for (size_t i = index; i < nums.size(); i++)
    {
        /* code */
        current.push_back(nums[i]);
        show_v(current);
        dfs_subset(nums, i + 1, current, result);
        current.pop_back();
        show_vd(current);
    }
}

// 78.Subset
vector<vector<int>> subsets(vector<int>& nums) {

    vi current;
    vvi result;
    dfs_subset(nums, 0, current, result);

    return result;
}

int main() {

    vi nums = {1, 2, 3};

    vvi result = subsets(nums);

    show_vv(result);

}

void show_vd(vi current) {
    cout << "->{";
    for (int t : current) {
        cout << t << ' ';
    }
    cout << "}<-";
    cout << endl;
}

void show_v(vi current) {
    cout << "{";
    for (int t : current) {
        cout << t << ' ';
    }
    cout << "}";
    cout << endl;
}

void show_vv(vvi result) {

    for (const auto& r : result) {
        cout << "{";
        for (int t: r) {
            cout << t << ' ';
        }
        cout << "}, ";
    }
}