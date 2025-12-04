#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream fstr("input.txt", ios::in);
    string s;
    long long cnt = 0;
    while(getline(fstr, s))
    {
        vector<int> jolt(12, 0);
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j < 12; j++)
            {
                if(s[i] > jolt[j] && i < s.size() + j - 11)
                {
                    jolt[j] = s[i];
                    fill(jolt.begin() + j + 1, jolt.end(), 0);
                    break;
                }
            }
        }
        long long temp = 0;
        for(int i = 0; i < 12; i++)
        {
            temp = temp * 10 + jolt[i] - 48;
        }
        cnt += temp;
        cout << temp << endl;
    }
    cout << cnt << endl;
    return 0;
}