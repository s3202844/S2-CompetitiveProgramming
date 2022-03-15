#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N)
    {
        int m, r, c;
        cin >> m >> r;
        vector<int> id, cmd, res;
        for (int i = m; i >= 1; i--)
            id.push_back(i);
        for (int i = 0; i < r; i++)
        {
            cin >> c;
            // cmd.push_back(c);
            auto it = find(id.begin(), id.end(), c);
            int index = it - id.begin();
            // res.push_back(index);
            id.erase(id.begin() + index);
            id.push_back(c);
            cout << m-1-index << " ";
        }
        cout << endl;
        N--;
    }
}