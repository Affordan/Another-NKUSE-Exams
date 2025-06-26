#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

int N;
double minlen = 10000, *x, *r;//�ֱ�Ϊ��СԲ���г��ȣ�ÿ��Բ�ĺ����꣬ÿ��Բ�뾶
double *bestr;//��СԲ���еİ뾶˳��

double center(int t)//�õ�ÿ��Բ��Բ������
{
	double temp = 0;
	for (int j = 1; j < t; ++j)//��ΪĿ��Բ�п�����������֮ǰ����һԲ���У�����һһ�ж�
	{
		double xvalue = x[j] + 2.0 * sqrt(r[t] * r[j]);//����r[j],��x[j],Ҫ���Լ�������
		if (xvalue > temp)
			temp = xvalue;
	}
	return temp;
}
void compute()
{
	double low = 0, high = 0;
	for (int i = 1; i < N; ++i)
	{
		if (x[i] - r[i] < low)
			low = x[i] - r[i];
		if (x[i] + r[i] > high)
			high = x[i] + r[i];
	}
	if (high - low < minlen)
	{
		minlen = high - low;
		for (int i = 1; i < N; ++i)
			bestr[i] = r[i];
	}
}
void backtrack(int t)
{
	if (t == N)
	{
		compute();
	}
	else
	{
		for (int j = t; j < N; ++j)
		{
			swap(r[t], r[j]);
			double centerx = center(t);
			if (centerx + r[t] + r[1] < minlen)
			{
				x[t] = centerx;
				backtrack(t + 1);
			}
			swap(r[t], r[j]);
		}
	}
}
int main()
{
	cin >> N;
	r = new double[N];
	x = new double[N];
	bestr = new double[N];
	for (int i = 1; i < N; ++i)
		cin >> r[i];
	backtrack(1);
	cout << setprecision(2) << std::fixed << minlen << endl;
	return 0;
}