//双指针——判断子序列
#include <iostream>

using namespace std;

bool isSubsequence(int a[],int n,int b[],int m)
{
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
            j++;
        }
        i++;
    }
    return j==m; //如果j==m，则说明b是a的子序列，因为b的元素已经全部匹配过了
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    if(isSubsequence(a,n,b,m))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }   
    system("pause");
}
    
