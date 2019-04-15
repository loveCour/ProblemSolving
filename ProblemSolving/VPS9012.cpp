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
				//레이저가 잘라서 새로 생긴 막대기 갯수만큼 더한다.
				CurRodNum += LeftParen;
				isLaser = false;
			}
			else
			{
				//원래 있던 막대기니까 1 더한다.
				++CurRodNum;
			}
		}
	}
	cout << CurRodNum;
	return 0;
}