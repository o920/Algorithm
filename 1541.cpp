#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char arr[51];
	cin >> arr;
	int len = strlen(arr);
	int sum = 0, temp = 0, n = 0;
	int ans[25] = {0,};
	for (int i = 0; i < len; i++) {
		if (arr[i] == '-') {
			sum += temp;
			ans[n] = sum;
			//- ���� ���� ���ڵ��� ���� �� ��������
			n++;
			temp = 0;
			sum = 0;
		}
		else if (arr[i] == '+') {
			sum += temp;
			temp = 0;
		}
		else {
			temp *= 10;
			temp += (arr[i] - '0');
			// �����ڰ� ������ �� ���� ó��
		}
	}
	sum += temp;
	ans[n] = sum;
	int result = ans[0];
	for (int i = 1; i < n+1; i++) result -= ans[i];
	cout << result << endl;
}