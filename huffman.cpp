#include <iostream>
#include <queue>
using namespace std;
int i,stone[999];
 
int stonemax(int n,int k)
{
	priority_queue<int> q;
	//����������ȶ���
	for(i=0;i<n;i++)
	q.push(stone[i]);
	int sum=0,max=0;
	while(q.size()>2)
	//��ΪҪ������ܷ��ã�����Ҫ��ϲ�����������
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
	//������С���ȶ���
	for(i=0;i<n;i++)
	q.push(stone[i]);
	int sum=0,min=0;
	while(q.size()>k)
	//��ΪҪ����С�ܷ��ã�����Ҫ��ϲ�����������
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
	freopen("in.txt","r",stdin); //�����ض����������ݽ���in.txt�ļ��ж�ȡ 
	freopen("out.txt","w",stdout); //����ض���������ݽ�����out.txt�ļ���
    int n,k;
	cin>>n>>k;
    for(i=0; i<n; i++)
    cin>>stone[i];
    cout<<stonemax(n,k)<<endl;
    cout<<stonemin(n,k)<<endl;
    fclose(stdin);//�ر��ض�������
	fclose(stdout);//�ر��ض������
}



