/*
	Name: Implementing Min Heap and it's Operation
	Copyright: 
	Author: Hemant Pandey
	Date: 07/09/16 00:27
	Description: It has all operation as:
		1-Add element
		2-Delete element
		3-Heapify a-Top Down
				  b-Bottom up
		4-delete min
		5-decrease key
		6-increase key
		7-update
		8-Sorting
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 10
int *a,lastIndex=-1,root=0;
int main()
{
	int lChild,rChild;
	a=(int *)malloc(sizeof(int)*SIZE);
	
	return 0;
}
void addElement(int e){
	a[++lastIndex]=e;
	Bottom_up_Heapify(lastIndex);
}
int Delete_Min(){
	int v=a[0];
	a[0]=a[lastIndex];
	lastIndex--;
	Top_Down_Heapify(root);
}

void Decrease_Key(int i,int v){
	a[i]-=v;				//i is index of node and v is value by which key is decreases
	Bottom_up_Heapify(i);
}

void Increase_Key(int i,int v){
	a[i]+=v;
	Top_Down_Heapify(i);
}

void Update_Key(int i,int x){
	if(a[i]<x)
		Increase_Key(i,x-a[i]);
	else
		Decrease_Key(i,a[i]-x);
}

void Delete_Key(int i){	
	Update_Key(i,a[lastIndex--]);
}

void Bottom_up_Heapify(int i){
	int temp;
	while(i>0&&a[(i-1)/2]>a[i]){
		temp=a[(i-1)/2];
		a[(i-1)/2]=a[i];
		a[i]=temp;
		i=(i-1)/2;
	}
}

void Top_Down_Heapify(int i){
	int temp,l,r,m;
	while(2*i+1<lastIndex){
		l=2*i+1;
		r=2*i+2;
		if(r<lastIndex&&a[l]>a[r])
			m=r;
		else
			m=l;
		if(a[i]>a[m]){
			temp=a[i];
			a[i]=a[m];
			a[m]=a[i];
			i=m;
		}
		else
			return 0;
	}
}
