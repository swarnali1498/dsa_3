#include<iostream>
#include<vector>
using namespace std;
class Trie {
public:
    bool isEnd;
    Trie* children[26];
    Trie() 
    {
        isEnd=false;
        int i;
        for(i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
    Trie* root=NULL;
    void insert(string word) 
    {
        int i,j,n=word.size();
        Trie* ptr=root;
        for(i=0;i<n;i++)
        {
            int k=word[i]-'a';
            if(!root)
            {
                Trie* nn=new Trie();
                root=nn;
                ptr=nn;
            }
            if(ptr->children[k]==NULL)
            {
                ptr->children[k]=new Trie();
            }
            ptr=ptr->children[k];
        }
        ptr->isEnd=true;
    }
    
    int spell_checker(string word) {
        int i,j,n=word.size();
        if(root==NULL)
            return 0;
        Trie* ptr=root;
        for(i=0;i<n;i++)
        {
            int k=word[i]-'a';
            if(ptr->children[k]==NULL)
                return 0;
            else
            {
                ptr=ptr->children[k];
            }
        }
        if(ptr->isEnd==true)
            return 1;
        return 0;
    }
    
    void add_words(Trie* ptr,vector<string>& ans,string temp)
    {
        if(ptr==NULL)
            return;
        if(ptr->isEnd==true)
            ans.push_back(temp);
        int i;
        for(i=0;i<26;i++)
        {
            if(ptr->children[i]!=NULL)
            {
                temp.push_back('a'+i);
                add_words(ptr->children[i],ans,temp);
                temp.pop_back();
            }
        }
    }
    
    vector<string> autocomplete(string prefix)
    {
        vector<string> ans;
        if(root==NULL)
            return ans;
        int i;
        Trie* ptr=root;
        int n=prefix.size();
        for(i=0;i<n;i++)
        {
            int ind=prefix[i]-'a';
            if(ptr->children[ind]==NULL)
            {
                return ans;
            }
            ptr=ptr->children[ind];
        }
        add_words(ptr,ans,prefix);
        return ans;
    }
    
    /*int startsWith(string prefix) {
        int i,j,n=prefix.size();
        if(root==NULL)
            return 0;
        Trie* ptr=root;
        for(i=0;i<n;i++)
        {
            int k=prefix[i]-'a';
            if(ptr->children[k]==NULL)
                return 0;
            else
            {
                ptr=ptr->children[k];
            }
        }
        int words=number_of_words(ptr);
        return words;
    }*/
};

int main() 
{
    int n;
    cin>>n;
    int i,j;
    vector<string> d(n);
    Trie ob;
    for(i=0;i<n;i++)
    {
        cin>>d[i];
        ob.insert(d[i]);
    }
    int a,m;
    string t;
    cin>>a>>t;
    vector<string> ans;
    switch(a)
    {
        case 1: cout<<ob.spell_checker(t)<<endl;
                break;
        case 2: ans=ob.autocomplete(t);
                cout<<ans.size()<<endl;
                m=ans.size();
                for(i=0;i<m;i++)
                {
                    cout<<ans[i]<<endl;
                }
                break;
       /* case 3: ans=autocorrect(t);
                cout<<ans.size();
                m=ans.size();
                for(i=0;i<m;i++)
                {
                    cout<<ans[i]<<endl;
                }*/
    }
}