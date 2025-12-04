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
    long long sum = 0;
    int cnt = -1;
    string a;
    fstream f("input.txt", ios::in);
    fstream t("tinput.txt", ios::out);
    while(getline(f, a))
        t << a << endl;
    f.close();
    t.close();
    while(cnt != 0)
    {
        fstream fstr("tinput.txt", ios::in);
        fstream temp("temp.txt", ios::out);
        string next, prev, middle;
        cnt = 0;
        bool first_run = true;
        vector<int> ppos, mpos;
        getline(fstr, middle);
        while(getline(fstr, next))
        {
            if(first_run)
            {
                prev = string(middle.size(), '.');
            }
            for(int i = 0; i < middle.size(); i++)
            {
                if(middle[i] == '@' && count(i, prev, middle, next) < 4)
                {
                    mpos.push_back(i);
                    cnt++;
                }
            }
            if(first_run)
                first_run = false;
            else
            {
                for(auto it : ppos)
                    prev[it] = '.';
                temp << prev << endl;
            }
            ppos = mpos;
            mpos.clear();
            prev = middle;
            middle = next;
        }
        next = string(middle.size(), '.');
        for(int i = 0; i < middle.size(); i++)
        {
            if(middle[i] == '@' && count(i, prev, middle, next) < 4)
            {
                mpos.push_back(i);
                cnt++;
            }
        }
        for(auto it : ppos)
            prev[it] = '.';
        for(auto it : mpos)
            middle[it] = '.';
        temp << prev << endl;
        temp << middle << endl;
        cout << cnt << endl;
        sum += cnt;
        fstr.close();
        temp.close();
        rename("temp.txt", "tinput.txt");
    }
    cout << endl << "Total Sum : " << sum << endl;
    return 0;
}