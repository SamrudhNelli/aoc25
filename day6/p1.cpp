#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream fstr("input.txt", ios::in);
    string s[5], a[5];
    stringstream ss[5];
    int i = 0;
    long long cnt = 0;
    while(getline(fstr, s[i]))
    { 
        ss[i] = stringstream(s[i]);
        // cout << s[i] << endl;
        i++;
    }
    while(1)
    {
        bool quit = true;
        for(int i = 0; i < 4; i++)
        {
            quit &= (!getline(ss[i], a[i], ' '));
        }
        getline(ss[4], a[4], ' ');
        if(quit)
            break;
        for(int i = 0; i < 5; i++)
        {
            while(!a[i].size() && getline(ss[i], a[i], ' '));
            // cout << a[i] << ' ';
        } 
        if(a[4] == "+")
        {
            cnt += (stoll(a[0]) + stoll(a[1]) + stoll(a[2]) + stoll(a[3]));
        }
        else if(a[4] == "*")
        {
            cnt += (stoll(a[0]) * stoll(a[1]) * stoll(a[2]) * stoll(a[3]));
        }
        else {
            cout << "!!Unrecognized!!" << endl;
        }
        cout << cnt << endl;
    }
    fstr.close();
    return 0;
}