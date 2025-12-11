#include <bits/stdc++.h>
#include <z3++.h> // The Operations Research Solver

using namespace std;
using namespace z3;

int solve_with_z3(vector<vector<int>>& buttons, vector<int>& targets) 
{
    context c;
    optimize opt(c); 

    vector<expr> button_presses;
    for (int i = 0; i < buttons.size(); i++) 
    {
        string name = "button_" + to_string(i);
        expr var = c.int_const(name.c_str());
        button_presses.push_back(var);
        opt.add(var >= 0);  // Variable Constraints
    }

    for (int i = 0; i < targets.size(); i++) 
    {
        expr sum = c.int_val(0); 
        for (int j = 0; j < buttons.size(); j++) 
        {
            bool flag = false;
            for (int it : buttons[j]) 
            {
                if (it == i) 
                { 
                    flag = true; 
                    break; 
                }
            }
            if (flag) 
                sum = sum + button_presses[j];
        }
        opt.add(sum == c.int_val(targets[i]));  // Sum constraints
    }
    
    expr total_sum = c.int_val(0);
    for (auto const &it : button_presses)
        total_sum = total_sum + it;
    opt.minimize(total_sum);  // Objective function

    if (opt.check() == sat) // Run the model
    {
        model m = opt.get_model();
        return m.eval(total_sum).get_numeral_int64();
    }
    return -1;
}

int main() 
{
    fstream fstr("input.txt");
    string s;
    long long cnt = 0;
    while (getline(fstr, s)) 
    {
        vector<vector<int>> buttons;
        vector<int> target;

        regex button_regex(R"(\(([\d,]+)\))");
        auto button_begin = sregex_iterator(s.begin(), s.end(), button_regex);
        auto button_end = sregex_iterator();
        for (auto i = button_begin; i != button_end; i++) 
        {
            stringstream ss(i->str(1));
            string t;
            vector<int> temp;
            while (getline(ss, t, ','))
                temp.push_back(stoll(t));
            buttons.push_back(temp);
        }

        regex target_regex(R"(\{([\d,]+)\})");
        smatch target_match;
        if (regex_search(s, target_match, target_regex)) 
        {
            stringstream ss(target_match[1]);
            string t;
            while (getline(ss, t, ','))
                target.push_back(stoll(t));
        }

        cnt += solve_with_z3(buttons, target);
    }
    cout << cnt << endl;
    return 0;
}