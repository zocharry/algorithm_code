
#include<iostream>

#include<cmath>

using namespace std;

 

int l[20];//皇后所在列数

int n;//皇后个数

 

void output(int n) {//输出n皇后的某个解

	int i;

	for (i = 1; i <= n; i++) {

		cout << l[i];

	}

	cout << endl;

}

 

int place(int t,int r) {//判断第r行皇后能否放在第t列

	int i=1;

	while(i<r){//皇后的行数r一定要大于i

		if (t == l[i] || abs(r-i) == abs(t - l[i])) {

			return 0;

		}

		++i;

	}

	return 1;

}

 

void nqueen(int m) {//递归求解

	int i;

	for (i=1; i <= n; i++) {

		l[m] = i;

		if (place(i,m)) {

			if (m == n) {

				output(n);//如果最后一个皇后也放置完毕，则输出结果

			}

			else {

				nqueen(m + 1);//否则，进行下一个皇后的放置

			}

		}

	}

}

 

int main() {

	cout << "请输入1~20以内的数作为皇后个数：";

	cin >> n;

	if (n > 20) {

		cout << "输入值偏大，请重新输入：";

		cin >> n;

	}

	nqueen(1);

	system("pause");

	return 0;

}

