#include <bits/stdc++.h>

using namespace std;

int count(int &i, string &prev, string &middle, string &next)
{
    int cnt = 0;
    if(i > 0)
    {
        if(middle[i - 1] == '@') cnt++;
        if(prev[i - 1] == '@') cnt++;
        if(next[i - 1] == '@') cnt++;
    }
    if(i < middle.size() - 1)
    {
        if(middle[i + 1] == '@') cnt++;
        if(prev[i + 1] == '@') cnt++;
        if(next[i + 1] == '@') cnt++;  
    }
    if(prev[i] == '@') cnt++;
    if(next[i] == '@') cnt++;
    return cnt;
}

int main()
{
    fstream fstr("input.txt", ios::in);
    string next, prev, middle;
    int cnt = 0;
    getline(fstr, middle);
    while(getline(fstr, next))
    {
        if(next.size() == middle.size() && prev.size() != middle.size())
        {
            prev = string(middle.size(), '.');
        }
        for(int i = 0; i < middle.size(); i++)
        {
            if(middle[i] == '@' && count(i, prev, middle, next) < 4)
                cnt++;
        }
        prev = middle;
        middle = next;
    }
    next = string(middle.size(), '.');
    for(int i = 0; i < middle.size(); i++)
    {
        if(middle[i] == '@' && count(i, prev, middle, next) < 4)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}