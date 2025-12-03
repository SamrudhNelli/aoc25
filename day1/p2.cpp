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
        // cout << s << " " << pos << " ";
        if(flag == 'R')
        {
            cnt += (pos + num) / 100;
            // cout << ":" << (pos + num) / 100;
            pos = (pos + num) % 100;
            // cout << " p" << pos << endl;
        }
        else
        {
            if(!pos) cnt--;
            cnt += (num - pos + 100) / 100;
            // cout << ":" << (num - pos + 100) / 100;
            pos = pos - num % 100;
            if(pos < 0) pos = 100 + pos;
            // cout << " p" << pos << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}