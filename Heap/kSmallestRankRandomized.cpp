/*
	Name: Given an array having large no. of numbers find k Smallest number
	Copyright: 
	Author: Hemant Pandey
	Date: 08/09/16 10:32
	Description:  applying concept of find rank in randomized way and taking action if
				pivot location comes after K i.e. he is not candidate of min k number
				using randomized partition function
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define N 30
#define K 5
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
	for(i=0;i<N;i++){
		b[i]=10-2*i;
	}		
		
	for(i=0;i<N;i++)
		printf("%d ",b[i]);
	printf("\n");
	
	int j,l,ele;
	for(i=0;i<2*K;i++)
		a[i]=b[i];
	
	for( ;i<N;i++){
		do
		{
			l=Partition(a,0,2*K-1);
			//printf("%d\n",l);	
		}while(l<K);
		for(j=l;j<2*K&&i<N;j++)
			a[j]=b[i++];
		i--;
	}
	
	int e;
	e=findRank(a,0,2*K-1,K);
	
	for(i=0;i<K;i++)
		printf("%d ",a[i]);
	return 0;
}

int findRank(int x[],int i,int j,int r){
	if(i==j)
		return x[i];
	int t;
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
	int i,j,x,t,p;
	p=RPivot(l,r);
	t=a[r];
	a[r]=a[p];
	a[p]=t;
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
