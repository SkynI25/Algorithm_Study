#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int d[1000001]; // 배열 선언, 초기에 배열은 0으로 초기화 되어 있음.

int dp(int n) {
	if (n < 0) // 만약 남은 길이 1일 때 길이가 2인 타일이 들어가게 되는 경우는 n이 0보다 작아지게 되는 경우이고 이는 성립되면 안되므로 return 0를 해준다.
		return 0;

	if (n == 0) // 만약 n이 0이 된 경우 그 때의 경우의 수 1을 리턴해준다.
		return 1;

	if (d[n] > 0) // 메모이제이션, DP에선 배열을 꼭 사용하고 메모이제이션은 항상 이와 같다.
		return d[n];

	d[n] = (dp(n - 1) + dp(n - 2)*2) % 10007;
	// 타일의 길이가 1인 경우의 수와 타일의 길이가 2인 경우의 수를 더해준 것을 d[n] 배열에 더하여 모든 경우의 수를 구한다.
  // 그리고 2*2 타일의 경우도 생각해줘야 한다. 2 * 1 가로 두개가 나올 때 2 * 2 가 나올 수 있으므로 가로가 나올 때 * 2를 해주면 된다.
	// 문제의 출력조건에서 방법의 수를 10007로 나눈 나머지를 출력해야하므로 나눠준다

	return d[n] % 10007; // 리턴 값도 나눠준다.
}

int main() {

	int ans = 0;

	cin >> ans;

	cout << dp(ans) << endl;

	return 0;
}
