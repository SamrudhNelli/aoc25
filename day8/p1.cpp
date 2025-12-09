#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream fstr("input.txt", ios::in);
    string s;
    vector<vector<long long>> v; 
    long long a, b, c;
    while(getline(fstr, s))
    {
        sscanf(s.c_str(), "%lld,%lld,%lld", &a, &b, &c);
        v.push_back({a, b, c});
    }
    priority_queue<pair<long long, pair<int, int>>> top1000;
    long long maxd = LLONG_MAX, t;
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = i + 1; j < v.size(); j++)
        {
            top1000.push({0LL + (v[i][0] - v[j][0]) * (v[i][0] - v[j][0]) + (v[i][1] - v[j][1]) * (v[i][1] - v[j][1]) + (v[i][2] - v[j][2]) * (v[i][2] - v[j][2]), {i, j}});
            if(top1000.size() > 1000)
                top1000.pop();
        }
    }
    int n = top1000.size();
    vector<unordered_map<int, int>> collection;
    unordered_map<int, int> links;
    for(int i = 0; i < n; i++)
    {
        // cout << top1000.top().first << " : { " << v[top1000.top().second.first][0] << "," << v[top1000.top().second.first][1] << "," << v[top1000.top().second.first][2] << "}, { " << v[top1000.top().second.second][0] << "," << v[top1000.top().second.second][1] << "," << v[top1000.top().second.second][2] << "}" << endl;
        if(links[top1000.top().second.first] && links[top1000.top().second.second] && ( links[top1000.top().second.first] != links[top1000.top().second.second] ))
        {
            auto e = collection[links[top1000.top().second.second] - 1];
            for(auto it : e)
            {
                links[it.first] = links[top1000.top().second.first];
                collection[links[it.first] - 1][it.first]++;
            }
            e.clear();
        }
        else if(links[top1000.top().second.first])
        {
            collection[links[top1000.top().second.first] - 1][top1000.top().second.second]++;
            links[top1000.top().second.second] = links[top1000.top().second.first];
        }
        else if(links[top1000.top().second.second])
        {
            collection[links[top1000.top().second.second] - 1][top1000.top().second.first]++;
            links[top1000.top().second.first] = links[top1000.top().second.second];
        }
        else 
        {
            unordered_map<int, int> ump = {{top1000.top().second.first, 1}, {top1000.top().second.second, 1}};
            collection.push_back(ump);
            links[top1000.top().second.first] = collection.size();
            links[top1000.top().second.second] = collection.size();
        }
        top1000.pop();
    }
    int max = 0, smax = 0, tmax;
    for(int i = 0; i < collection.size(); i++)
    {
        if(collection[i].size() >= max)
        {
            tmax = smax;
            smax = max;
            max = collection[i].size();
        }
        else if(collection[i].size() >= smax)
        {
            tmax = smax;
            smax = collection[i].size();
        }
        else if(collection[i].size() >= tmax)
        {
            tmax = collection[i].size();
        }
    }
    cout << max << " " << smax << " " << tmax << " = " << 1LL * max * smax * tmax << endl;
    return 0;
}