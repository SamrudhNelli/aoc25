#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream fstr("input.txt", ios::in);
    string s;
    char flag;
    int num, pos = 50, cnt = 0;
    while(getline(fstr, s))
    {
        sscanf(s.c_str(), "%c%d", &flag, &num);
        if(flag == 'R')
            pos = (pos + num) % 100;
        else
        {
            pos = pos - num % 100;
            if(pos < 0) pos = 100 + pos;
        }
        if(pos == 0)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}