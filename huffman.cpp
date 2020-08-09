#include <iostream>
#include <queue>
using namespace std;
int i,stone[999];
 
int stonemax(int n,int k)
{
	priority_queue<int> q;
	//生成最大优先队列
	for(i=0;i<n;i++)
	q.push(stone[i]);
	int sum=0,max=0;
	while(q.size()>2)
	//因为要求最大总费用，所以要求合并次数尽量多
	{
		sum=0;
		for(i=0;i<2;i++)
		{
			sum+=q.top();
			q.pop();
		}
		max+=sum;
		q.push(sum);
	}
	while(!q.empty())
	{
		max+=q.top();
		q.pop();
	}
	return max;
}
 
int stonemin(int n,int k)
{
	priority_queue<int,vector<int>,greater<int> > q;
	//生成最小优先队列
	for(i=0;i<n;i++)
	q.push(stone[i]);
	int sum=0,min=0;
	while(q.size()>k)
	//因为要求最小总费用，所以要求合并次数尽量少
	{
		sum=0;
		for(i=0;i<k;i++)
		{
			sum+=q.top();
			q.pop();
		}
		min+=sum;
		q.push(sum);
	}
	while(!q.empty())
	{
		min+=q.top();
		q.pop();
	}
	return min;
}
 
int main()
{
	freopen("in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取 
	freopen("out.txt","w",stdout); //输出重定向，输出数据将保存out.txt文件中
    int n,k;
	cin>>n>>k;
    for(i=0; i<n; i++)
    cin>>stone[i];
    cout<<stonemax(n,k)<<endl;
    cout<<stonemin(n,k)<<endl;
    fclose(stdin);//关闭重定向输入
	fclose(stdout);//关闭重定向输出
}



