//Finding XOR of each element of array result will be same that elemnt ,that occurs odd no of times
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int temp,res=0;
	    for(int i=0;i<n;i++){
	        cin>>temp;
	        res^=temp;
	    }
	    cout<<res<<endl;
	}
	return 0;
}
