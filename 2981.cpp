#include <iostream>
#include <algorithm>
using namespace std;

int arr[100]; // �Է¹޴� �迭
int ans[100]; // �ִ������� ����� ���ϴ� �迭
int gcd(int a, int b) { // �ִ����� ���ϴ� �Լ�
	return a % b ? gcd(b, a%b) : b;
}
int main() {
	//�Է¹ޱ�
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n); // �������� ����
	//�ִ����� ���ϱ�, arr[i]-arr[i-1] = M * (arr[i]/M - arr[i-1]/M)
	int sub = arr[1] - arr[0];
	for (int i = 2; i < n; i++) sub = gcd(sub, arr[i] - arr[i - 1]);
	//�ִ������� ��� ���ϱ�
	int count = 0;
	for (int i = 1; i*i <= sub; i++) {
		if (sub%i == 0) {
			ans[count++] = i;
			if (i != sub / i) ans[count++] = sub / i;
		}
	}
	sort(ans, ans + count); 
	//���
	for (int i = 0; i < count; i++) {
		if (ans[i] != 1) cout << ans[i] << " ";
	}
}