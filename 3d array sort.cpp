#include<bits/stdc++.h>

using namespace std;

struct data{
    int x1;
    int x2;
    int x3;
};
bool compare(vector<data> x,vector<data> y) 
{ 
    if(x[0].x3==y[0].x3)
    return (x[0].x2 < y[0].x2 ); 
    return (x[0].x3 < y[0].x3 ); 
} 

int main() {
	int n,m;
	
	cin>>n>>m;
	
	vector <data> arr[n];
	
	for(int i=0;i<n;i++)
	{
  	data temp;
    temp.x1=0;
    temp.x2=0;
    temp.x3=0;
  	arr[i].push_back(temp);
    cin>>(arr[i][0].x1);
  }
	
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i][0].x2;
	    arr[i][0].x3=(arr[i][0].x1)*(arr[i][0].x2);
	}
	sort(arr,arr+n,compare);
	for(int i=0;i<n;i++)
	cout<<arr[i][0].x1<<' '<<arr[i][0].x2<<' '<<arr[i][0].x3<<'\n';
}
