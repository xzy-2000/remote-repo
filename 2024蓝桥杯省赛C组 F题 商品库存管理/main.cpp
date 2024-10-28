//#include <bits/stdc++.h>

//using namespace std;
//
//int main() {
//	int n, m, cnt;
//	cin >> n >> m;//输入的第一行 n 和 m，分别表示商品的种类数和操作的个数
//	int list[n + 1][2];
////	vector <int> list[n + 1];
//	int num[n + 1] = {0}, ans[n + 1];
//	for (int i = 1; i <= m; i++) {
//		cin >> list[i][0] >> list[i][1];
//		for (int j = list[i][0] ; j <= list[i][1]; j++) {
//			num[j]++;
//		}
//	}
//
//	for (int i = 1; i <= m; i++) {
//		for (int k = 1; k <= n; k++) {
//			ans[k] = num[k];
//		}
////		memcpy(ans, num, sizeof(num));
//		cnt = 0;
//		for (int j = list[i][0] ; j <= list[i][1]; j++)
//			ans[j]--;
//		for (int k = 1; k <= n; k++) {
//			if (!ans[k])
//				cnt++;
//			cout << ans[k] << ' ';
//		}
//		cout << cnt << '\n';
//	}
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
pair<int, int>pr[N];
int diff[N], sum[N], ans = 0;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		diff[a]++, diff[b + 1]--;
		pr[i] = {a, b};
	}
	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
		sum[i] += sum[i - 1] + (diff[i] <= 1);
		if (diff[i] == 0)
			ans++;//记录未被操作的商品
	}
	for (int i = 0; i < m; i++)
		cout << sum[pr[i].second] - sum[pr[i].first - 1] + ans << endl;
	return 0;
}
/*
5 3
1 2
2 4
3 5

7 4
1 3
2 3
3 5
6 7
*/