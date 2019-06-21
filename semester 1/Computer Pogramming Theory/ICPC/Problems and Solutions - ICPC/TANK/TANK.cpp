#include <iostream>
#include <stdlib.h>

using namespace std;

void sel(int,int,int*);

int return_i,return_j;

int main ()
{
	int N,count=1; 
	int P[10000];
	cin>>N;
	while(N){
		int C,I,j;
		cin>>C; cin>>I;

		for(int ip=0; ip<I; ip++)
		{
			cin>> P[ip];
		}
		sel(C,I,P);
		cout<< "Case #"<<count<<": "<< return_i+1 <<" " << return_j+1 << "\n";
		N--; count++;
	}
}
void sel(int C, int I, int *P )
{

    for(int i=0; i<I; i++)
    {
        for(int j=i+1; j<I ; j++)
        {
            if(P[i] + P[j] == C)
	    { return_i = i; return_j=j;
		 return;
		}
        }
    }

}
