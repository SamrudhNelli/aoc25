#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream fstr("input.txt", ios::in);
    string s;
    long long max = INT_MIN, a, b, t;
    map<long long, long long> top;
    map<long long, vector<long long>> col;
    set<long long> set_a;
    while(getline(fstr, s))
    {
        sscanf(s.c_str(), "%lld,%lld", &a, &b);
        if(!top[a])
        {
            top[a] = b;
        }
        else
        {
            if(b < top[a])
            {
                swap(b, top[a]);
            }
            col[top[a]].push_back(a);
            col[b].push_back(a);
            // down[a] = b;
        }
        set_a.insert(a);
    }
    for(auto it : set_a)
    {
        auto n = col.find(top[it]);
        // auto t = col.find(down[it]);
        // std::reverse_iterator<decltype(t)> rt(t);
        long long area;
        // cout << ": " << it << " " << down[it] << " " << top[it] << endl; 
        while(n != col.end())
        {
            for(auto i : n->second)
            {
                area = (fabs(n->first - top[it]) + 1) * (fabs(it - i) + 1);
                if(area > max)
                    max = area;
            }
            n++;
        }
        // while(*(rt) != *col.begin())
        // {
        //     for(auto i : rt->second)
        //     {
        //         cout << "t " << rt->first << " " << i;
        //         area = (fabs(down[it] - rt->first) + 1) * (fabs(it - i) + 1);
        //         cout << " " << area << endl;
        //         if(area > max)
        //             max = area;
        //     }
        //     rt++;
        // }
    }
    cout << max << endl;
    return 0;
}