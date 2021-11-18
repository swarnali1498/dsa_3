#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
	string s;
	cin>>s;
	long long int i,j,k;
	map<string,long long int> mp;
	long long int n=s.size();
	string sr="";
	for(i=0;i<n;i++)
	{
		sr=s[i]+sr;
	}
	s=s+"#"+sr;
	long long int old_len=n;
	n=s.size();
	for(i=0;i<n;i++)
	{
		string key=s.substr(i);
		mp[key]=i;
	}
	vector<long long int> suffix_array;
	for(auto itr:mp)
	{
		suffix_array.push_back(itr.second);
	}
	vector<long long int> inverse_suffix(n),lcp_array(n);
	for(i=0;i<n;i++)
	{
		inverse_suffix[suffix_array[i]]=i;
	}
	long long int lcp=0;
	for(i=0;i<n;i++)
	{
		if(inverse_suffix[i]==n-1)
		{
			lcp=0;
		}
		else
		{
			long long int index=inverse_suffix[i]+1;
			long long int next=suffix_array[index];
			while(i+lcp<n && next+lcp<n && s[i+lcp]==s[next+lcp])
			{
				lcp++;
			}
		}
		lcp_array[inverse_suffix[i]]=lcp;
		if(lcp>0)
		lcp--;
	}
	/*for(auto itr:suffix_array)
	cout<<itr<<" ";
	cout<<endl;
	for(auto itr:lcp_array)
	cout<<itr<<" ";
	cout<<endl;*/
	long long int pos=0,maxlen=0;
	for(i=0;i<n-1;i++)
	{
		if(lcp_array[i]>maxlen)
		{
			if((suffix_array[i+1]<old_len && suffix_array[i]>old_len) || (suffix_array[i+1]>old_len && suffix_array[i]<old_len))
			{
				maxlen=lcp_array[i];
				pos=suffix_array[i];
			}
		}
	}
	string longest_palindrome=s.substr(pos,maxlen);
	cout<<longest_palindrome<<endl;
	return 0;
}
