/*
	Name: Finding Inversion Pair
	Copyright: 
	Author: Hemant PAndey
	Date: 04/09/16 08:49
	Description: using Devide&Conquer Approach in O(nlogn)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define arrsize 10
long long int c=0;
void MergeIP(int a[],int l,int r);
void MergeIPcount(int a[],int l,int r,int k);
int main() {   
       	int a[arrsize]={2,3,1,4,6,0,7,8,11,9},i,j,count=0;            
        MergeIP(a,0,arrsize-1);
        printf("No.of Inversion Pair :%d\n",c);                           
    return 0;
}

void MergeIP(int a[],int l,int r){
	if(l<r){
		int k=(l+r)/2;
		MergeIP(a,l,k);
		MergeIP(a,k+1,r);
		MergeIPcount(a,l,r,k);
	}
}

void MergeIPcount(int a[],int l,int r,int k){
	int *b;    
	b=(int *)malloc(sizeof(int)*(r-l+1));
	int i=l,j=k+1,x=0;
	while(i<=k&&j<=r){
		if(a[i]<=a[j]){
            b[x++]=a[i++];            
        }			
		else if(a[i]>a[j]){
            b[x++]=a[j++];
            c=c+(k-i+1);
        }
        
            
	}	
	while(i<=k)
		b[x++]=a[i++];
	while(j<=r)
		b[x++]=a[j++];
	i=l;
	x=0;
	while(i<=r)
		a[i++]=b[x++];
	free(b);
}
