#include<iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()
using namespace std;
void profit_sorting(float profit[],float weight[],int size,int cap){
	for(int j=0;j<size-1;j++){
			int largest=j;
	for(int i=j+1;i<size;i++){
		if(profit[i]>profit[largest]) {
		largest=i;
		}
	}
			swap(profit[j],profit[largest]);
			swap(weight[j],weight[largest]);
	}
	cout<<"Profit is    ";
	for(int i=0;i<size;i++){
		cout<<profit[i]<<" ";
	}
	cout<<endl<<"Weight is    ";
for(int i=0;i<size;i++){
		cout<<weight[i]<<" ";
	}
	cout<<endl;
	float maximum_profit=0;
	for(int i=0;i<size;i++){
		
		float fraction;
		if(cap>=weight[i]){
			maximum_profit = maximum_profit + profit[i];
			cap = cap-weight[i];
		}
		else{
			fraction = (cap/weight[i]);
			maximum_profit = maximum_profit+ (profit[i]*fraction);
			cap-=weight[i]*fraction;;
		  }
		}
		cout<<"\nMaximum profit is "<<maximum_profit<<endl;
}
void weight_sorting(float profit[],float weight[],int size,int cap){
	for(int j=0;j<size-1;j++){
			int largest=j;
	for(int i=j+1;i<size;i++){
		if(weight[i]>weight[largest]) {
		largest=i;
		}
	}
		swap(profit[j],profit[largest]);
			swap(weight[j],weight[largest]);
	}
	cout<<endl<<"Profit is    ";
	for(int i=0;i<size;i++){
		cout<<profit[i]<<" ";
	}
	cout<<endl<<"Weight is    ";
for(int i=0;i<size;i++){
		cout<<weight[i]<<" ";
	}
	cout<<endl;
	float max_profit=0;
	for(int i=0;i<size;i++){
	float fraction;
		if(cap>=weight[i]){
			max_profit+=profit[i];
			cap-=weight[i];
		}
		else {
			fraction=(cap/weight[i]);
			max_profit+=(fraction * profit[i]);
			cap=0;
			break;
		}
	}
	cout<<"\nMaximum profit is "<<max_profit<<endl;
	}
void ratio_sorting(float profit[],float weight[],int size,int cap){
		float ratio[size];
	for(int j=0;j<size;j++){
			 ratio[j] = profit[j]/weight[j];
			 }
	for(int i=0;i<size-1;i++){
		int largest=i;
		for(int j=i+1;j<size;j++){
			if(ratio[j] > ratio[largest]){
				largest=j;
			}
		}
		 swap(ratio[i], ratio[largest]);
        swap(profit[i], profit[largest]);
        swap(weight[i], weight[largest]);
	}
	cout<<"ratio is    ";
		for(int i=0;i<size;i++){
		cout<<ratio[i]<<" ";
	}
	cout<<endl<<"Profit is    ";
		for(int i=0;i<size;i++){
		cout<<profit[i]<<" ";
	}
	cout<<endl<<"weight is    ";
for(int i=0;i<size;i++){
		cout<<weight[i]<<" ";
	}
	cout<<endl;
		float max_profit=0;
	for(int i=0;i<size;i++){
		if(cap>=weight[i]){
			max_profit += profit[i];
			cap -= weight[i];
		}
		else{
			float fraction=(float)cap/weight[i];
			max_profit += profit[i]* fraction;
			cap=0;
			break;
		}
	}
	cout<<"\nMaximum profit is "<<max_profit;
	}
void knapsack(float profit[],float w[],int size,int cap){
	profit_sorting(profit, w, size, cap);
    weight_sorting(profit, w, size, cap);
    ratio_sorting(profit, w, size, cap);
}
int main(){
	srand(time(0));
	int size,cap;
	cout<<"Enter size of knapsack =";
	cin>>size;
	cout<<"Enter capacity=";
	cin>>cap;
	float w[size],profit[size];
	for(int i=0;i<size;i++){
		w[i]=(float)(rand()%70);
		cout<<"\nEnter weight of "<<i<<" index is="<<w[i];
		profit[i]=rand()%100;
		cout<<"\nEnter profit of "<<i<<" index is="<<profit[i];
	}
	knapsack(profit,w,size,cap);
	return 0;
}
