/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

bool cmp(vector<int> &A,vector<int> &B){

    if(A.size() != B.size()) return A.size() < B.size();
    for(int i=0 ;i<A.size();i++) 
        if(A[i]!=B[i])
            return A[i]>B[i];

}

vector<int> sub(vector<int>&A,vector<int>&B){
    vector<int> C;
    int t=0;
    for(size_t i=0;i<A.size();i++){
        t=A[i]-t;
        if(i<B.size()){
            t-=B[i];
        }
        C.push_back((t+10)%10);
        if( t<0 )   t=1;
        else        t=0;
    }  
    while (C.size()>0 && C.back()==0) C.pop_back();
}


int main(){
    string a,b;
    cin >> a >> b ;

    vector <int> A,B;
    for(int i=a.size()-1;i>=0;i--)  A.push_back(a[i]-'0');
    for(int i=a.size()-1;i>=0;i--)  B.push_back(a[i]-'0');

    if(cmp(A,B)){
        vector<int> C = sub(A,B);
        for(size_t i;i=A.size()-1;i--) cout<<C[i];

    }else{
        vector<int> C = sub(B,A);
        cout<<"-";
        for(size_t i;i=B.size()-1;i--) cout<<C[i];  
    }
    system("pause");
}*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> mul(vector<int>&A,vector<int>&B){
    vector<int> C(A.size() + B.size(), 0);

    int t=0;
    for(size_t i=0;i<A.size();i++){
        for(size_t j=0;j<B.size();j++){
            t += A[i]*B[j]+C[i+j];
            C[i+j]=t%10;
            t/=10;
        }
        C[i+B.size()] = t;
    }
    
    while(C.size()>0 && C.back()==0){
        C.pop_back();
    }
    return C;
}


int main(){
    string a,b;
    cin >> a >> b;

    vector<int> A, B;
    for(int i = a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i = b.size()-1;i>=0;i++) B.push_back(b[i]-'0');

    vector<int> C = mul(A, B);
    for(int i=C.size();i>=0;i--) cout << C[i];
    system("pause");
}




