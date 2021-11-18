#include<iostream>
#include<math.h>
using namespace std;

class Trie
{
    public:
    Trie* ar[2];
    long long int data;
    Trie()
    {
        ar[0]=ar[1]=NULL;
        data=0;
    }
    
};

Trie* t=new Trie();
void insert(long long int data)
{
    Trie* ptr=t;
    long long int x=pow(2,40);
    for(;x>0;x/=2)
    {
        bool nextbit=data & x;
        if(!ptr->ar[nextbit])
        {
            ptr->ar[nextbit]=new Trie();
        }
        ptr=ptr->ar[nextbit];
    }
    ptr->data=data;
}

long long int max_xor(long long int data)
{
    Trie* ptr=t;
    long long int x=pow(2,40);
    for(;x>0;x/=2)
    {
        bool nextbit=data & x;
        if(ptr->ar[!nextbit])
        {
            ptr=ptr->ar[!nextbit];
        }
        else
        {
            ptr=ptr->ar[nextbit];
        }
    }
    return ptr->data^data;
}

int main() 
{
    long long int n,q,v,query;
    cin>>n>>q;
    long long int i,j;
    for(i=0;i<n;i++)
    {
        cin>>v;
        insert(v);
    }
    for(i=0;i<q;i++)
    {
        cin>>query;
        cout<<max_xor(query)<<endl;
    }
}

