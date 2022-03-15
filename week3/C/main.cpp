#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int N;
    string line;
    char a = 'a';
    char A = 'A';
    char z = 'z';
    char Z = 'Z';
    char space = ' ';
    char dot = '.';
    while (true)
    {
        cin >> N;
        if (N == 0) {
            break;
        }
        vector<string> files;
        vector<int> v_hash;
        getline(cin, line);
        for (size_t i = 0; i < N; i++)
        {
            getline(cin, line);
            files.push_back(line);
            int v = int(line[0]);
            for (size_t j = 1; j < line.size(); j++)
            {
                char c = line[j];
                if ((int(c) <= int(z) && int(c) >= int(a)) || (int(c) <= int(Z) && int(c) >= int(A)) || int(c) == int(space) || int(c) == int(dot))
                {
                    v = v ^ int(c);
                }
            }
            v_hash.push_back(v);
        }
        int collisions = 0;
        for (size_t i = 0; i < N - 1; i++)
        {
            for (size_t j = i + 1; j < N; j++)
            {
                if (v_hash.at(i) == v_hash.at(j) && files.at(i) != files.at(j))
                {
                    collisions++;
                }
            }
        }
        set<string> s(files.begin(), files.end());
        cout << s.size() << " " << collisions << endl;
    }
}