#include<bits/stdc++.h>
using namespace std;
void peek(int arr[],int n){
			for(int i=0;i<n;i++){
					if((i==0)&&(arr[i]>arr[i+1]) || (i==n-1)&&(arr[i]>arr[i-1])){
				cout<<arr[i]<<" is peek";
					break;
			}
					else if((arr[i]>arr[i-1])&&(arr[i]>arr[i+1])){
				cout<<arr[i]<<" is peek";
						break;
			}
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
     peek(arr,n);
return 0;	
}
