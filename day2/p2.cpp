#include <bits/stdc++.h>

using namespace std;

long long full(string t, int size, string &tsfull, long long &tfull)
{
    int repeat = ceil(float(size / float(t.size()))) - 1;
    tsfull = t;
    while(repeat--) tsfull = t + tsfull;
    tfull = stoll(tsfull);
    return tfull;
}

long long func(int size, long long l, long long r)
{
    set<long long> st;
    long long tpart, tfull, tsize, cnt = 0;
    string tsfull, t, s = to_string(l);
    for(int i = 1; i <= size / 2; i++)
    {
        t = s.substr(0, i);
        tsize = t.size();
        tpart = stoll(t);
        if(l > full(t, size, tsfull, tfull))
        {
            tpart++;
            t = to_string(tpart);
        }
        // cout << "l - " << l << ", r - " << r << endl;
        while(full(t, size, tsfull, tfull) <= r && t.size() == tsize)
        {
            // cout << tsfull << endl;
            st.insert(tfull);
            tpart++;
            t = to_string(tpart);
        }
    }
    auto it = st.begin();
    while(it != st.end())
    {
        // cout << *it << ",";
        cnt += *it;
        it = next(it);
    }
    return cnt;
    // return accumulate(st.begin(), st.end(), 0LL);
}

int main()
{
    fstream fstr("input.txt", ios::in);
    string s, t;
    long long cnt = 0;
    while(getline(fstr, s, ','))
    {
        long long l, r;
        sscanf(s.c_str(), "%lld-%lld", &l, &r);
        string ls = to_string(l), tsfull, rs = to_string(r);
        if(ls.size() != rs.size())
        {
            cnt += func(ls.size(), l, pow(10, ls.size()) - 1);
            cnt += func(rs.size(), pow(10, ls.size()), r);
        }
        else 
        {
            cnt += func(ls.size(), l, r);
        }  
    }
    cout << cnt << endl;
    return 0;
}