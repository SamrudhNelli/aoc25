#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream fstr("input.txt", ios::in);
    string s[5];
    int i = 0;
    long long cnt = 0;
    while(getline(fstr, s[i++]));
    bool product = true;
    long long prod = 1, sum = 0, t;
    for(int i = 0; i < s[0].size(); i++)
    {
        if(s[4][i] != ' ')
        {
            if(s[4][i] == '*')
                product = true;
            else
                product = false;
            prod = 1;
            sum = 0;
        }
        bool notallspaces = false;
        t = 0;
        for(int j = 0; j < 4; j++)
            if(s[j][i] != ' ')
            {
                notallspaces = true;
                t = t * 10 + (s[j][i] - 48);
            }
        if(!notallspaces)
        {
            if(product) cnt += prod;
            else cnt += sum;
            cout << cnt << endl;
        }
        if(product)
            prod *= t;
        else 
            sum += t;
    }
    if(product) cnt += prod;
    else cnt += sum;
    cout << cnt << endl;
    return 0;
}