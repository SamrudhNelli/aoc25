#include <bits/stdc++.h>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        
        // Combine the two hashes (a simple XOR is a basic method)
        return h1 ^ h2; 
    }
};

unordered_map<pair<string, string>, string, pair_hash> dat;

string add_strings(string a, string b)
{
    if(dat[{a, b}].size())
    {
        // cout << "data";
        return dat[{a, b}];
    }
    if(dat[{b, a}].size())
    {
        // cout << "data";
        return dat[{b, a}];
    }
    map<char, int> ump;
    string t;
    for(int i = 0; i < a.size(); i++)
        ump[a[i]]++;
    for(int j = 0; j < b.size(); j++)
    {
        if(!ump[b[j]])
            ump[b[j]]++;
        else
            ump.erase(b[j]);
    }
    for(auto it : ump)
        t.push_back(it.first);
    dat[{a, b}] = t;
    return t;
}

int main()
{
    fstream fstr("input.txt", ios::in);
    string s;
    long long cnt = 0;
    while(getline(fstr, s))
    {
        vector<set<string>> button_press;
        int ind;
        string state, t;
        for(int i = 0; i < s.size(); i++, ind++)
        {
            if(s[i] == '[')
                ind = -1;
            else if(s[i] == '#')
                state.push_back('0' + ind);
            else if(s[i] == ']')
                button_press.resize(ind);
            else if(s[i] >= '0' && s[i] <= '9')
                t.push_back(s[i]);
            else if(s[i] == ')')
            {
                button_press[0].insert(t);
                t.clear();
            }
            else if(s[i] == '{')
                break;
        }
        if(!state.size())
            continue;
        cout << s << endl;
        for(int i = 0; i < button_press.size(); i++)
        {
            if(button_press[i].find(state) != button_press[i].end())
            {
                cnt += (i + 1);
                break;
            }
            if(i == button_press.size() - 1)
            {
                break;
            }
            int l = 0, r = i;
            while(l <= r)
            {
                if(l == r)
                {
                    auto j = button_press[l].begin();
                    while(j != button_press[l].end())
                    {
                        auto k = next(j);
                        while(k != button_press[l].end())
                        {
                            t = add_strings(*j, *k);
                            cout << *j << " + " << *k << " = " << t << endl;
                            button_press[i + 1].insert(t);
                            k = next(k);
                        }
                        j = next(j);
                    }
                }
                else 
                {
                    auto j = button_press[l].begin();
                    while(j != button_press[l].end())                    
                    {
                        auto k = button_press[r].begin();
                        while(k != button_press[r].end())
                        {
                            t = add_strings(*j, *k);
                            cout << *j << " + " << *k << " = " << t << endl;
                            button_press[i + 1].insert(t);
                            k = next(k);
                        }
                        j = next(j);
                    }
                }
                r--;
                l++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}