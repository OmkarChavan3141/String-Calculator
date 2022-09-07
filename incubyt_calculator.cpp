#include<bits/stdc++.h>
using namespace std;

vector<int> checkNegative(string num)
{
	int flag=0;
	int t=0;
	
	vector<int>neg;
	
	for(int i=0;i<num.size();i++)
	{
		if(num[i]=='-')
		{
			flag=1;
		}
		
		if(num[i]==',' && flag==1)
		{
			neg.push_back(-t);
			t=0;
			flag=0;
		}
		
		if(num[i]>='0' && num[i]<='9' && flag==1)
		{
			t=(t*10)+num[i]-'0';
		}
	}
	if(flag==1)neg.push_back(-t);
	return neg;
}
int add(string num)
{
	if(num.size()==0)
	return 0;
	
	int t=0;
	int flag=0;
	int check=0;
	
	vector<int>vec;
	
	for(int i=0;i<num.size();i++)
	{
		if(num[i]==',')
		{
			vec.push_back(t);
			t=0;
			flag=0;
		}
		else
		{
			if(num[i]=='-')
			{
				if(check==0)
				{
					cout<<"Negatives not allowed:";
					vector<int>neg=checkNegative(num);
					for(auto it:neg)
					{
						cout<<it<<" ";
					}
					cout<<endl;
					check=1;
				}
				flag=1;
			}
			
			if(num[i]>='0' && num[i]<='9' && flag==0)
			{
				t=(t*10)+(num[i]-'0');
			}
			
			if(num[i]>='a' && num[i]<='z' && flag==0)
			{
				t=(num[i]-'a'+1);
			}
		}
	}
	vec.push_back(t);
	
	int sum=0;
	
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]>1000)continue;
		sum+=vec[i];
	}
	return sum;
}


int main()
{
	string numbers;
	cin>>numbers;
	
	cout<<add(numbers);
}
