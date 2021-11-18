#include<iostream>
#include<map>
using namespace std;

int main()
{
	string s;
	cin>>s;
	long long int i,j;
	map<string,long long int> mp;
	string str=s+s;
	long long int n=s.size();
	for(i=0;i<2*n;i++)
	{
		string key=str.substr(i);
		mp[key]=i;
	}
	string ans;
	for(auto itr:mp)
	{
		if(itr.second>=0 && itr.second<n)
		{
			ans=itr.first.substr(0,n);
			break;	
		}
	}
	cout<<ans<<endl;
}
