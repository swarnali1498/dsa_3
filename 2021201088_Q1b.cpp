#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
	string s;
	cin>>s;
	long long int i,j,k;
	cin>>k;
	map<string,long long int> mp;
	long long int n=s.size();
	for(i=0;i<n;i++)
	{
		string key=s.substr(i);
		mp[key]=i;
	}
	vector<pair<long long int,string>> suffix_array;
	for(auto itr:mp)
	{
		suffix_array.push_back({itr.second,itr.first});
	}
	
	/*for(auto itr:suffix_array)
	cout<<itr.first<<" "<<itr.second<<endl;
	cout<<endl;*/
	
	long long int maxlen=0;
	for(i=0;i<=n-k;i++)
	{
		string a=suffix_array[i].second;
		string b=suffix_array[i+k-1].second;
		for(j=0;j<min(a.size(),b.size());j++)
		{
			if(a[j]!=b[j])
			break;
		}
		maxlen=max(maxlen,j);
	}
	if(maxlen)
	cout<<maxlen<<endl;
	else
	cout<<-1<<endl;
}
