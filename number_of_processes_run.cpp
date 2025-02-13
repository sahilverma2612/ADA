#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void finishh(float a[],float f[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(f[j]>=f[i]){
				swap(f[j],f[i]);
				swap(a[j],a[i]);
			}
		}
	}
	//cout<<"Arrival Time\tFinish Time\n";
	for(int i=0;i<n;i++){
	//	cout<<a[i]<<"\t\t"<<f[i]<<"\n";
	}
	int count=1,i=0;
	while(i<n){
		if(f[i]<=a[i+1] ){
			count++;
		}
			i++;
	}
//	cout<<"\nNumber of processes run="<<count;
cout<<count<<"\t\t\t";
}
void arrivalf(float a[],float f[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(f[j]>=f[i]){
				swap(a[j],a[i]);
				swap(f[j],f[i]);				
			}
		}
	}
//	cout<<"\nArrival Time\tFinish Time\n";
	for(int i=0;i<n;i++){
	//	cout<<a[i]<<"\t\t"<<f[i]<<"\n";
	}
	int count=1,i=0;
	while(i<n){
		if(f[i]<=a[i+1] ){
			count++;
		}
			i++;
	}
//	cout<<"\nNumber of processes run="<<count;
cout<<count<<"\t\t";
}
void sjf(float a[],float f[],int n){
	float t[n];
	for(int i=0;i<n;i++){
		t[i]=f[i]-a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(t[j]>=t[i]){
				swap(a[j],a[i]);
				swap(f[j],f[i]);
				swap(t[j],t[i]);
			}
		}
	}
	//cout<<"\nArrival Time\tFinish Time\t\tTime of exwcution\n";
	for(int i=0;i<n;i++){
	//	cout<<a[i]<<"\t\t"<<f[i]<<"\t\t"<<t[i]<<"\n";
	}
	int count=1,i=0;
	while(i<n){
		if(f[i]<=a[i+1] ){
			count++;
		}
			i++;
	}
//	cout<<"\nNumber of processes run="<<count;
	cout<<count<<"\n";
}
int main(){
	srand(time(0));
	int n,t;
	t=rand()%10 +5;
	cout<<"Size\tfinish function\t\tarrival function\tsjf\n";
	for(int i=0;i<t;i++){
	n = rand()%1000;
	cout<<n<<"\t\t";
	
	float arrival[n],finish[n];
	for(int i=0;i<n;i++){
		arrival[i]= (rand()+1)%15;
	//	cout<<"Enter arrival time of "<<i<<"index="<<arrival[i]<<endl;
//	cout<<arrival[i]<<"\t";
		finish[i]= (rand()+1)%20;
			//	cout<<"Enter Finish time of "<<i<<"index="<<finish[i]<<endl;
	//			cout<<finish[i]<<"\t";
		if(arrival[i]>finish[i]){
			i--;
		}
	}
	finishh(arrival,finish,n);
	arrivalf(arrival,finish,n);
	sjf(arrival,finish,n);
}
	return 0;
}
