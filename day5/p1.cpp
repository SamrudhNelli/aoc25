#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream fstr("input.txt", ios::in);
    string s;
    set<pair<long long, long long>> set;
    bool input = true;
    long long cnt = 0;
    while(getline(fstr, s))
    {
        if(!s.size())
        {
            input = false;
            continue;
        }
        if(input)
        {
            long long a, b;
            bool inserted = false;
            sscanf(s.c_str(), "%lld-%lld", &a, &b);
            for(auto it : set)
            {
                if(b < it.first)
                {
                    set.insert({a, b});
                    inserted = true; break;
                }
                else if(a < it.second)
                {
                    a = min(a, it.first);
                    b = max(b, it.second);
                    set.erase(it);
                    set.insert({a, b});
                    inserted = true; break;
                } 
            }
            if(!inserted)
                set.insert({a, b});
        }
        else 
        {
            long long x = stoll(s);
            for(auto it : set)
            {
                if(x >= it.first && x <= it.second)
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}