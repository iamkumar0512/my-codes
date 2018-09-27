#include <bits/stdc++.h>
#include <string>

using namespace std;

void lps_make(string pat, int M, int* lps)
{
    int len = 0;
    lps[0] = 0; 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void match_arr(int m[],int lps[],string pat,string txt,int n)
{
    int i=0,j=0;
    while(i<n)
    {
        if(txt[i]==pat[j])
        {
            j++;
            m[i]=j;
            i++;
        }
        else
        {
            if(j!=0)
            j=lps[j-1];
            else
            {
                m[i]=0;
                i++;
            }
        }
    }
}
int main()
{
	int n;
	cin>>n;
	string a,b;
	cin>>a;
	cin>>b;
	int lps[n];
	lps[0]=0;
	lps_make(a,n,lps);
	int m[n];
	match_arr(m,lps,a,b,n);
	int max=0,index=0;
	for(auto i=n-1;i>=0;i--)
	{
	    if(m[i]>=max)
	    {
	        max=m[i];
	        index=i+1;
	    }
	}
	cout<<index-max;
}