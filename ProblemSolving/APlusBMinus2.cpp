#include <iostream>
#include <string>

using namespace std;
int main()
{
	string A;
	cin >> A;
	for (int i = 0; i < A.size(); i += 10) {
		cout << A.substr(i, 10) << endl;
	}
	return 0;
}
