#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 7

int Partition(int *,int,int,int);
int main()
{
	int *a;
	a=(int *)malloc(sizeof(int)*MAXSIZE);
	int i;
	for(i=0;i<MAXSIZE;i++)
		scanf("%d",&a[i]);
	int p=a[rand()%MAXSIZE];
	printf("%d\n",p);
	int k=Partition(a,0,MAXSIZE-1,p);
//	printf("%d\n",k);
	for(i=0;i<MAXSIZE;i++)
		printf("%d ",a[i]);
	return 0;
}

int Partition(int x[],int l,int r,int p){
	int i,j,temp;
	i=l;
	j=r;
	while(i<=j){
		while(x[i]<=p)
			i++;
		while(x[j]>p)
			j--;
		if(i<j){
			temp=x[i];
			x[i]=x[j];
			x[j]=temp;
		}
		i++;
		j--;
	}
	return j;
}
