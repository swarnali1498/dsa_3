#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;

class node
{
	public:
	long long int data;
	long long int index;
	node()
	{
		data=0;
		index=0;
	}
	node(long long int d,long long int i)
	{
		data=d;
		index=i;
	}
};

class minHeap
{
	public:
	long long int s;
	vector<node> heap;
	
	minHeap(vector<node> ar,int hsize)
	{
		heap=ar;
		s=hsize;
		build_min_heap();
	}
	void min_heapify(long long int i)
	{
		long long int l,r,min;
		l=2*i+1;
		r=2*i+2;
		if(r<s && heap[r].data<heap[i].data)
			min=r;
		else
			min=i;
		if(l<s && heap[l].data<heap[min].data)
			min=l;
		if(min!=i)
		{
	        	node t=heap[i];
			heap[i]=heap[min];
			heap[min]=t;
	        	min_heapify(min);
		}
	}
	void build_min_heap()
	{
	    long long int i,j;
	    for(i=s/2;i>=0;i--)
	        min_heapify(i);
	}
	node extract_min()
	{
		node t=heap[0];
		heap[0]=heap[s-1];
		heap[s-1]=t;
		s--;
		min_heapify(0);
		return t;
	}
	void replace_min(node nn)
	{
		heap[0].data=nn.data;
		min_heapify(0);
	}
};



int main(int argc,char* argv[])
{
	FILE* fin;
	char* in=argv[1];
 	fin=fopen(in,"r");
 	char ch;
 	long long int i,j;
 	long long int temp_filesize=200;
 	vector<long long int> temp(temp_filesize);
 	vector<char*> out;
 	while(fin)
    	{
    		while(temp.size()<200 && fin)
    		{
    			long long int number;
 			fscanf(fin,"%lld,",&number);
 			temp.push_back(number);
 		}
 		sort(temp.begin(),temp.end());
 		FILE* tempfile;
 		string fname=to_string(j);
 		char* fn=new char[fname.size()+1];
 		strcpy(fn,fname.c_str());
 		tempfile=fopen(fn,"w");
 		for(i=0;i<temp.size();i++)
 		{
 			fprintf(tempfile, "%lld,", temp[i]);
 		}
 		out.push_back(fn);
 		j++;
 		fclose(tempfile);
 	}
 	
 	long long int k=out.size();
 	FILE* file_pointer[k];
 	for(i=0;i<out.size();i++)
 	{
 		FILE* fp=fopen(out[i],"r");
 		if(fp)
 		file_pointer[i]=fp;
 	}
 	FILE* output;
 	output=fopen(argv[2],"w");
 	vector<node> heap(out.size());
 	i=0;
 	while(i<out.size())
 	{
 		if (fscanf(file_pointer[i], "%lld,", &heap[i].data) != 1)
 			break;
 		heap[i].index=i;
 		i++;
 	}
 	minHeap hp(heap,out.size());
 	long long int count=0;
 	while(count!=out.size())
 	{
 		node min=hp.extract_min();
 		fprintf(output, "%lld,", min.data);
 		node nn(0,min.index); 
 		if (fscanf(file_pointer[min.index], "%lld,",&nn.data)!= 1) 
 		{
            		count++;
        	}
        	else
        		hp.replace_min(nn);
 	}
 	fclose(fin);
 	fclose(output);
}
