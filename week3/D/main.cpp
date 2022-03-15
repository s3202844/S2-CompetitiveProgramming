#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    while (N != 0)
    {
        int pile1 = 0, pile2 = 0;
        for (unsigned int i = 0; i < N; i++)
        {
            string cmd;
            int num;
            cin >> cmd >> num;
            if (cmd == "DROP")
            {
                cout << "DROP 2 " << num << endl;
                pile2 += num;
            }
            else
            {
                if (pile1 < num)
                {
                    if (pile1 != 0)
                    {
                        cout << "TAKE 1 " << pile1 << endl;
                    }
                    num -= pile1;
                    cout << "MOVE 2->1 " << pile2 << endl;
                    pile1 = pile2;
                    pile2 = 0;
                }
                cout << "TAKE 1 " << num << endl;
                pile1 -= num;
            }
        }
        cout << endl;
        cin >> N;
    }
    return 0;
}