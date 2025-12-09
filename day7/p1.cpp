#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream fstr("input.txt", ios::in);
    string s;
    unordered_map<int, int> ump, tmp;
    int split = 0;
    getline(fstr, s);
    for(int i = 0; i < s.size(); i++)
        if(s[i] == 'S')
            ump[i]++;
    while(getline(fstr, s))
    {
        tmp = ump;
        for(auto it : tmp)
        {
            if(s[it.first] == '^')
            {
                ump.erase(it.first);
                ump[it.first + 1]++;
                ump[it.first - 1]++;
                split++;
            }
        }
    }
    cout << split << endl;
    return 0;
}