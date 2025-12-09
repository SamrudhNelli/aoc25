#include <bits/stdc++.h>

using namespace std;

struct Node 
{
    Node * left;
    Node * right;
    long long val;
    bool traversed = false;
    Node()
    { 
        left = NULL;
        right = NULL;
    }
};

long long find_timelines(Node *head)
{
    if(head == NULL)
    {
        return 1LL;
    }
    else
    {
        if(!head->traversed)
        {
            head->val = find_timelines(head->left) + find_timelines(head->right);
            head->traversed = true;
        }
        return head->val;
    }
}

int main()
{
    fstream fstr("input.txt", ios::in);
    string s;
    unordered_map<int, vector<Node *>> collection_left, collection_right;
    Node *root;
    getline(fstr, s);
    bool root_found = false;
    while(getline(fstr, s))
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '^')
            {
                Node *head = new Node();
                for(auto it : collection_left[i - 1])
                    it->right = head;
                for(auto it : collection_right[i + 1])
                    it->left = head;
                collection_left[i - 1].clear();
                collection_right[i + 1].clear();
                collection_left[i].push_back(head);
                collection_right[i].push_back(head);
                if(!root_found)
                {
                    root = head;
                    root_found = true;
                }
            }
        }
    }
    long long timelines = find_timelines(root);
    cout << timelines << endl;
    return 0;
}