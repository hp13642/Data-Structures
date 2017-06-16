/*
	Name: Given an array having large no. of numbers find k Smallest number
	Copyright: 
	Author: Hemant Pandey
	Date: 07/09/16 23:52
	Description: using 2k space and applying concept of find rank
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define N 30
#define K 7
int findRank(int x[],int i,int j,int r);
int RPivot(int l,int r);
int Partition(int a[],int l,int r);

int main()
{	
	srand(time(0));
	int *b;
	int i,*a;
	b=(int *)malloc(sizeof(int)*N);
	a=(int *)malloc(sizeof(int)*2*K);
	for(i=0;i<N;i++)
		b[i]=50-2*i;
		
	for(i=0;i<N;i++)
		printf("%d ",b[i]);
	printf("\n");
	
	int j,l,ele;
	l=K;
	for(i=0;i<N;i++){
		if(i<2*K)
			a[i]=b[i];
		else			
		if(i-l==K){
			ele=findRank(a,0,2*K-1,K);
			printf("%d\n",ele);
			l=i;
			j=K;
			a[j++]=b[i];		
		}
		else
			a[j++]=b[i];
	}	
	ele=findRank(a,0,2*K-1,K);		//OR call ele=findRank(a,0,j,2*k-j);
	printf("%d\n",ele);	
	
	for(i=0;i<K;i++)
		printf("%d ",a[i]);
	return 0;
}


int findRank(int x[],int i,int j,int r){
	if(i==j)
		return x[i];
	int t,p=RPivot(i,j);
	t=x[p];							// in this aprtition function p is index of pivot lelement
	x[p]=x[j];
	x[j]=t;	
	int k=Partition(x,i,j);
	//printf("\n%d  %d\n",p,k);
	if(r==j-k+1)
		return x[k];
	else if(r<=j-k)
		return findRank(x,k+1,j,r);		
	else
		return findRank(x,i,k-1,r-j+k-1);
			
}
int RPivot(int l,int r){
	
       return l+(rand()%(r-l));	
}
int Partition(int a[],int l,int r){
	int i,j,x,t;
	i=l-1;
	x=a[r];
	for(j=l;j<r;j++){
		if(a[j]<=x){
			i++;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	t=a[i+1];
	a[i+1]=a[r];
	a[r]=t;
	return ++i;
}
