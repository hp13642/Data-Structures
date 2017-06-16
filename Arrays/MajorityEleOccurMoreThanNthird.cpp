/*
	Name: a0,a1,a2...............an-1 has a Majority Number that occur 
	more than n/3 times
	Copyright: 
	Author: Hemant PAndey
	Date: 04/09/16 09:22
	Description:using Naive Approach it could be done in O(n^2) 
	USING Sorting it could be done in O(nlogn+n) but using 
	BUCKET APPROACH it has to be done in O(n) 
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define arrsize 20
int c1=0,c2=0;
int s1,s2;
int main()
{	
	int a[arrsize]={2,3,1,2,4,6,2,2,2,0,7,8,1,2,2,2,2,1,2,2},i,j;	
	for(i=0;i<arrsize;i++){
		if(c1>0&&a[i]==s1)
			c1++;
		else if(c2>0&&a[i]==s2)
			c2++;
		else if(c1==0){
			s1=a[i];
			c1++;
		}			
		else if(c2==0){
			s2=a[i];
			c2++;
		}			
		else{
			c1--;
			c2--;
		}		
	}
	if(!c1&&!c2)
		printf("No Such Majority element Founded\n");
	else if(!c1&&c2)
		printf("Majority element is :%d\n",s2);
	else if(c1&&!c2)
		printf("Majority element is :%d\n",s1);
	else{
		c1=0;
		c2=0;
		for(i=0;i<arrsize;i++){
			if(a[i]==s1)
				c1++;
			else if(a[i]==s2)
				c2++;
		}
		if(c1>c2)
			printf("Majority element is :%d\n",s1);
		else
			printf("Majority element is :%d\n",s2);
	}	
	return 0;
}
