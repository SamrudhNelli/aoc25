#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream fstr("input.txt", ios::in);
    string s, t;
    long long cnt = 0;
    while(getline(fstr, s, ','))
    {
        long long l, r, thalf, tfull;
        sscanf(s.c_str(), "%lld-%lld", &l, &r);
        string ls = to_string(l);
        t = ls.substr(0, max(1, int(ls.size() / 2)));
        thalf = stoll(t);
        while(l > stoll(t + t))
        {
            thalf++;
            t = to_string(thalf);
        }
        cout << "l - " << l << ", r - " << r << endl;
        while(stoll(t + t) < r)
        {
            cout << t + t << endl;
            cnt += stoll(t + t);
            thalf++;
            t = to_string(thalf);
        }
    }
    cout << cnt << endl;
    return 0;
}