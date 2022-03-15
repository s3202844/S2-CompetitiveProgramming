#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> events;
    while (N) {
        string state;
        cin >> state;
        if (state == "E") {
            string e;
            cin >> e;
            events.push_back(e);
        }
        else if (state == "D") {
            int n;
            cin >> n;
            while (n) {
                events.pop_back();
                n--;
            }
        }
        else {
            int n, l_pointer, r_pointer;
            l_pointer = 0;
            r_pointer = events.size();
            vector<string> s_events;
            cin >> n;
            bool solid = true;
            while (n) {
                string e;
                cin >> e;
                if (e[0] != '!') {
                    auto it = find(events.begin(), events.end(), e);
                    if (it == events.end()) {
                        cout << "Plot Error" << endl;
                        solid = false;
                        break;
                    }
                    else {
                        int index = it - events.begin();
                        l_pointer = max(l_pointer, index);
                        if (r_pointer <= l_pointer) {
                            cout << "Plot Error" << endl;
                            solid = false;
                            break;
                        }
                    }
                }
                else {
                    string p;
                    for (size_t i=1; i<e.size(); i++) {
                        p.push_back(e[i]);
                    }
                    auto it = find(events.begin(), events.end(), p);
                    if (it != events.end()) {
                        int index = it - events.begin();
                        r_pointer = min(r_pointer, index);
                        if (r_pointer <= l_pointer) {
                            cout << "Plot Error" << endl;
                            solid = false;
                            break;
                        }
                    }
                }
                n--;
            }
            if (solid) {
                if (r_pointer != events.size()) {
                    cout << events.size()-r_pointer << " Just A Dream" << endl;
                }
                else {
                    cout << "Yes" << endl;
                }
            }
        }
        N--;
    }
    return 0;
}