#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    string all;
    while (getline(cin, line)) {
        all += line;
        all.append(1, char(10));
    }
    if (all.size() == 0) return 0;

    vector<long long> nums;
    long long cur = 0;
    long long sign = 1;
    bool innum = false;
    auto flush = [&]() {
        if (innum) {
            nums.push_back(sign * cur);
            cur = 0;
            sign = 1;
            innum = false;
        }
    };

    for (size_t i = 0; i < all.size(); ++i) {
        unsigned char uc = (unsigned char)all[i];
        int k = (int)uc;
        if (k == 45 && i + 1 < all.size()) {
            int nk = (int)(unsigned char)all[i + 1];
            if (nk >= 48 && nk <= 57) {
                flush();
                sign = -1;
                cur = 0;
                innum = true;
                continue;
            }
        }
        if (k >= 48 && k <= 57) {
            if (innum == false) {
                innum = true;
                cur = 0;
                sign = 1;
            }
            cur = cur * 10 + (k - 48);
        } else {
            flush();
        }
    }
    flush();

    if (nums.size() < 2) return 0;

    long long cnt = nums.back();
    nums.pop_back();

    if (cnt <= 0 || cnt > (long long)nums.size()) return 0;

    nth_element(nums.begin(), nums.begin() + (cnt - 1), nums.end(), greater<long long>());
    cout << nums[cnt - 1] << endl;
    return 0;
}
