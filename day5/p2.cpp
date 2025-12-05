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
            auto last = set.begin(), it = next(last);
            while(it != set.end())
            {
                if((*last).second >= (*it).first)
                {
                    set.erase(it);
                    set.erase(last);
                    last = set.insert({(*last).first, max((*last).second, (*it).second)}).first;
                    it = last;
                }
                else
                    last = it;
                it = next(it);
            }
            for(auto it : set)
            {
                cnt += (it.second - it.first + 1);
            }
            break;
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
        // else 
        // {
        //     long long x = stoll(s);
        //     for(auto it : set)
        //     {
        //         if(x >= it.first && x <= it.second)
        //         {
        //             cnt++;
        //             break;
        //         }
        //     }
        // }
    }
    cout << cnt << endl;
    return 0;
}