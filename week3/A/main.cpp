#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> ans;
    vector<int> time;
    int start = 0;
    for (size_t i=0; i<M; i++) {
        int n;
        cin >> n;
        start += n;
        time.push_back(start);
    }
    ans.push_back(time.back());
    while (N > 1) {
        int end = 0;
        vector<int> n_time;
        for (size_t i=0; i<M; i++) {
            int n;
            cin >> n;
            end = max(end, time.at(i));
            end += n;
            n_time.push_back(end);
        }
        ans.push_back(n_time.back());
        time = n_time;
        N--;
    }
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
}