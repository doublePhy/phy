//离散化   二分+差分+前缀和  输入

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 300010;
int a[N], s[N];
vector<pair<int,int>> add,query;
vector<int> alls;


int find(int x){
    int l=0,r=alls.size()-1;//alls是从0开始的，
    while(l<r){
        int mid=(r+l) >> 1;
        if(alls[mid]>=x) r=mid;
        else l=mid+1;
    }
    return l+1;
}


int main()
{
    int n,m;
    cin >> n >>m;
    for(int i = 1;i <= n; i++){
        int x,c;
        cin>>x>>c;
        add.emplace_back(x,c); //记录下标。也可写成push_back(pair<int,int>(x,i));
        alls.push_back(x);//所有需要用到的坐标，x，l，r    
        
    }

    for(int i = 1;i <= m; i++){
        int l,r;
        cin>>l>>r;
        query.emplace_back(l,r); //把当前查询的左右端点存进query容器。也可写成push_back(pair<int,int>(x,i));
        alls.push_back(l);
        alls.push_back(r);
    }
    
    //排序和去重。左闭右开
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end()); //去重，erase删除单个元素或者区间，删除区间是左开右闭
    //unique把数组中不重复的元素移动到数组前面；所有重复的元素全部挤到数组尾部；返回重复段开头的迭代器。
    //经过排序和去重，原本那些题目需要用到的 数据坐标，边界坐标，都被映射到了1~alls.size()之间的整数坐标上了。这时alls就是一个映射表



    for(int i =0 ;i < add.size() ; i++){
    
        int j=find(add[i].first);
        a[j]+=add[i].second;//把修改的值，映射到离散化后的数组上
    }
        
    
    //前缀和
    for(int i=1 ; i<=alls.size() ;i++){
        s[i]=a[i]+s[i-1];
    }
    //查询
    for(int i =0 ;i < m ; i++){
        int L = query[i].first;
        int R = query[i].second;
        int left = find(L);
        int right = find(R);
        cout << s[right] - s[left - 1] << '\n';
        
    }
    return 0;

}