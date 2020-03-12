#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> vec(N);
	vector<int> vec2(8001, 0);
	int mean = 0, max=0;
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
		mean += vec[i];
		int temp = (vec[i] <= 0) ? abs(vec[i]) : vec[i] + 4000; // ������ �迭 8000�� �� �տ�, ����� �ڿ� ����
		vec2[temp]++; // �Է¹��� ���� ����� �������
		if (vec2[temp] > max) max = vec2[temp]; // �� ���� ���� �� �����س���
	}
	sort(vec.begin(), vec.end()); 
	bool isSecond = false; // �󵵰� ���� �� �� �ι�°�� ���� �� �˾Ƴ��� ����
	int mode = 0;
	for (int i = -4000; i <= 4000; i++) {
		int temp = i <= 0 ? abs(i) : i + 4000;
		if (vec2[temp] == max) { // if ���� �ι�° �ɸ��� �ι�°�� ���� ���� mode�� �����ϰ� �ݺ��� ����������
			mode = i;
			if (isSecond) break;
			isSecond = true;
		}
	}

	cout << round(mean / (double)N) << "\n";
	cout << vec[round(N / 2)] << "\n";
	cout << mode << "\n";
	cout << vec[vec.size()-1] - vec[0] << "\n";
}