/*
	Name: Given an array having large no. of numbers find k Smallest number
	Copyright: 
	Author: Hemant Pandey
	Date: 07/09/16 21:52
	Description: using space O(k) and Time O(n) usiing approach of MaxHeap
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define N 20
#define K 7
void addElement(int e);
void Bottom_up_Heapify(int i);
void Top_Down_Heapify(int i);
int lastIndex=-1,*a,root=0;
int main()
{	
	srand(time(0));
	int *b,i;
	b=(int *)malloc(sizeof(int)*N);
	a=(int *)malloc(sizeof(int)*K);
	for(i=0;i<N;i++)
		b[i]=rand()%50;
		
	for(i=0;i<N;i++)
		printf("%d ",b[i]);
	printf("\n");
	for(i=0;i<N;i++){
		if(i>K-1){
			if(b[i]<a[0]){
				a[0]=b[i];
				Top_Down_Heapify(root);	
			}
		}
		else
			addElement(b[i]);
	}
	
	//At the end our max Heap contain all k smallest element out of n
	for(i=0;i<K;i++)
		printf("%d ",a[i]);
	return 0;
}
void addElement(int e){
	a[++lastIndex]=e;
	Bottom_up_Heapify(lastIndex);
}



void Bottom_up_Heapify(int i){
	int temp;
	while(i>0&&a[(i-1)/2]<a[i]){
		temp=a[(i-1)/2];
		a[(i-1)/2]=a[i];
		a[i]=temp;
		i=(i-1)/2;
	}
}

void Top_Down_Heapify(int i){
	int temp,l,r,m;
	while(2*i+1<K){
		l=2*i+1;
		r=2*i+2;
		if(r<K&&a[l]<a[r])
			m=r;
		else
			m=l;
		if(a[i]<a[m]){
			temp=a[i];
			a[i]=a[m];
			a[m]=temp;
			i=m;
		}
		else
			return ;
	}
}
