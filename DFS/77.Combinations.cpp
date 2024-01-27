#include <iostream>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int>         vi;


void dfs_combination(int n, int k, int index, vi &current, vvi &pakg);

// vector<vector<int>> combine(int n, int k) {
    
// }
void show_vv(vvi pakg);


int main(void) {

    vvi pakg;
    int n = 4, k = 2;
    vi current_vi;
    dfs_combination(n, k, 1, current_vi, pakg);
    show_vv(pakg);
    return 0;
}

void show_vv(vvi pakg) {
    cout << "[";
    for (const auto& p : pakg) {
        cout << "[";
        for (int pi : p) {
            cout << pi << ' ';
        }
        cout << "]";
    }
    cout << "]";
    cout << endl;
}

void dfs_combination(int n, int k, int index, vi &current, vvi &pakg) {
    if (current.size() == k) {
        pakg.push_back(current);
        return;
    }

    for(int i = index ; i <= n ; ++i) {
        current.push_back(i);
        dfs_combination(n, k, i+1, current, pakg);
        current.pop_back();
    }
}