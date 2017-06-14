//Using Hash Map it can be done in O(n)
//Using Sorting it can be done in o(nlogn)
//And using brute force i.e using two loops in O(n^2)
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args)  {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t--!=0){
		    int n=sc.nextInt();
		    int sum=sc.nextInt();
		    Map<Integer,Integer> m=new HashMap<Integer,Integer>();
		    boolean flag=true;
		    for(int i=0;i<n;i++){
		        int te=sc.nextInt();
		        
		        if (m.containsKey(sum-te) && flag) {
                        System.out.println("Yes");
                        flag=false;
                    }
                else
                m.put(te, i);
		    }
		    if(flag)
		        System.out.println("No");
		    
		}
	}
}
