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
    multiset<pair<long long, pair<int, int>>> set;
    long long maxd = LLONG_MAX, t;
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = i + 1; j < v.size(); j++)
        {
            set.insert({0LL + (v[i][0] - v[j][0]) * (v[i][0] - v[j][0]) + (v[i][1] - v[j][1]) * (v[i][1] - v[j][1]) + (v[i][2] - v[j][2]) * (v[i][2] - v[j][2]), {i, j}});
        }
    }
    vector<unordered_map<int, int>> collection;
    int max_size = 2;
    unordered_map<int, int> links;
    for(auto i : set)
    {
        // cout << i.first << " : { " << v[i.second.first][0] << "," << v[i.second.first][1] << "," << v[i.second.first][2] << "}, { " << v[i.second.second][0] << "," << v[i.second.second][1] << "," << v[i.second.second][2] << "}";
        if(links[i.second.first] && links[i.second.second] && ( links[i.second.first] != links[i.second.second] ))
        {
            int k = links[i.second.second] - 1;
            for(auto it : collection[k])
            {
                links[it.first] = links[i.second.first];
                collection[links[i.second.first] - 1][it.first]++;
            }
            collection[k].clear();
            if(collection[links[i.second.first] - 1].size() > max_size)
                max_size = collection[links[i.second.first] - 1].size();
        }
        else if(links[i.second.first])
        {
            collection[links[i.second.first] - 1][i.second.second]++;
            links[i.second.second] = links[i.second.first];
            if(collection[links[i.second.first] - 1].size() > max_size)
                max_size = collection[links[i.second.first] - 1].size();
        }
        else if(links[i.second.second])
        {
            collection[links[i.second.second] - 1][i.second.first]++;
            links[i.second.first] = links[i.second.second];
            if(collection[links[i.second.second] - 1].size() > max_size)
                max_size = collection[links[i.second.second] - 1].size();
        }
        else 
        {
            unordered_map<int, int> ump = {{i.second.first, 1}, {i.second.second, 1}};
            collection.push_back(ump);
            links[i.second.first] = collection.size();
            links[i.second.second] = collection.size();
        }
        if(max_size == v.size())
        {
            cout << v[i.second.first][0] << " " << v[i.second.second][0] << " = " << 1LL * v[i.second.first][0] * v[i.second.second][0] << endl;
            break;
        }
    }
    return 0;
}