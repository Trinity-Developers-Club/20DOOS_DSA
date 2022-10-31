#include<bits/stdc++.h>
using namespace std;
void getLPS(string pat,int m,int lps[]);
void KMPpatternSearch(string txt,string pat)
{
	int n=txt.size();
	int m=pat.size();
	int i=0,j=0;
	int lps[m];
	getLPS(pat,m,lps);
	while(i<n)
	{
		if(txt[i]==pat[j])
		{
			i++;
			j++;
		}
		 if(j==m)
		{
		cout<<"Pattern found at = "<<i-m<<endl;
	    j=lps[j-1];
		}
		else if(i<n&&txt[i]!=pat[j])
		{
			if(j>0)
			j=lps[j-1];
			else
			i=i+1;
		}
	}
}
void getLPS(string pat,int m,int lps[])
{
	int len=0,i=1;
	lps[0]=0;
	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	for(int j=0;j<m;j++)
	cout<<lps[j]<<" ";
	
}
int main()
{
	string txt,pat;
	getline(cin,txt);
	getline(cin,pat);
	KMPpatternSearch(txt,pat);
	return 0;
}
