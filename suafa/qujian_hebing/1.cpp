#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int main() {
    int n;
    cin >> n;

    vector<PII> segs;

    for(int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
   }
    sort(segs.begin(), segs.end());

    int count=0;
    int cur_r = 0, cur_l = 0;


    for(int i=0; i<segs.size(); i++){

        int l = segs[i].first;
        int r = segs[i].second;

        //第一个区间，初始化当前区间的右边界和左边界，便于后面的动态比较和更新
        if(i==0 ){
            cur_r = r;
            cur_l = l;   //保存第一个数组的数据，后面比较后，更新
            count=1;
        }else{
            if(l<=cur_r)  //当i！=0，假设i=1，则是第二个数组的左边界跟第一个数组的右边界比较
            {              //小于，说明第二个数组的左边界是在第一个数组区间内的，那就可以合并
                cur_r = max(cur_r,r); //更新右边界
                
            }else{//反之，无交集，也就是新区间的左边界不在前区间内
                count++; //为什么在这添加，因为是算的最大合并区间，当不能合并时，加一，表示新增一个区间
                //若写在上面if判断，那连续的几个区间的合并会计算为多次，题目要求最终合并后的区间数，不是次数
                cur_r = r;
                cur_l = l;
            }
        }
        
    }
    cout << count << endl;
    system("pause");
} 
