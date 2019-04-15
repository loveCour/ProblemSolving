#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ps;	
	cin >> ps;

	int LeftParen = 0;
	int CurRodNum = 0;
	bool isLaser = false;
	for (auto s : ps)
	{
		if (s == '(')
		{
			++LeftParen;
			isLaser = true;
		}
		else if (s == ')')
		{
			--LeftParen;
			if (isLaser)
			{
				//�������� �߶� ���� ���� ����� ������ŭ ���Ѵ�.
				CurRodNum += LeftParen;
				isLaser = false;
			}
			else
			{
				//���� �ִ� �����ϱ� 1 ���Ѵ�.
				++CurRodNum;
			}
		}
	}
	cout << CurRodNum;
	return 0;
}