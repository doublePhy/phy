//实现C = A + B, A >= 0, B >= 0

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;


vector<int> add(vector<int> &A, vector<int> &B)
{
    if(A.size()<B.size()) 
        return add(B,A);

    vector<int> C;
    int t = 0;
    //A.size()是无符号整型，所以需要size_t i ，两个无符号整型进行判断
    for ( size_t i=0 ; i < A.size() ; i++ ){ 
        t += A[i];

        if ( i < B.size() ) t += B[i];

        C.push_back( t%10 );
        t=t/10;
    }
    if ( t ) C.push_back( t );
    return C;
}


int main(){
    string n,m;
    cin >> n >> m;

    vector<int> A,B;
    for(int i=n.size()-1;i>=0;i--) A.push_back(n[i]-'0');
    for(int i=m.size()-1;i>=0;i--) B.push_back(m[i]-'0');
    vector<int> C = add(A,B);
    for(int i=C.size()-1;i>=0;i--)
        cout << C[i];
    system("pause");
}