#include <iostream>
#include <cstdlib>

using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        qsort(arr,n,sizeof(int),compare);
        for(int i=k;i<n;i++)
        {
            if(arr[i-1]==arr[i])
            {
                k++;
                continue;
            }
            break;
        }
        cout<<k<<'\n';
    }
}
