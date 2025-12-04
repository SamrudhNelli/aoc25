#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream fstr("input.txt", ios::in);
    string s;
    long long cnt = 0;
    while(getline(fstr, s))
    {
        int first_dig = 0, second_dig = 0;
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] > first_dig)
            {
                first_dig = s[i];
                second_dig = 0;
            }
            else if(s[i] > second_dig)
            {
                second_dig = s[i];
            }
        }
        if(s[s.size() - 1] > second_dig)
            second_dig = s[s.size() - 1];
        cout << first_dig - 48 << second_dig - 48 << endl;
        cnt += ((first_dig - 48) * 10) + (second_dig - 48);
    }
    cout << cnt << endl;
    return 0;
}