#include <bits/stdc++.h>
#define DEBUG(x) cout<<#x<<"->"<<x<<endl
using namespace std;

int t, m1, d1, x1, m2, d2, x2, ans;
string mt1, mt2;

int monthIndex(string mt) {
	if (mt == "January") return 1;
	if (mt == "February") return 2;
	if (mt == "March") return 3;
	if (mt == "April") return 4;
	if (mt == "May") return 5;
	if (mt == "June") return 6;
	if (mt == "July") return 7;
	if (mt == "August") return 8;
	if (mt == "September") return 9;
	if (mt == "October") return 10;
	if (mt == "November") return 11;
	if (mt == "December") return 12;
}

bool checkYear(int year) {
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

void swapDates() {
	if (x2 < x1) {
		swap(x1, x2), swap(d1, d2), swap(m1, m2);
	} else if (x2 == x1) {
		if (m2 < m1) {
			swap(x1, x2), swap(d1, d2), swap(m1, m2);
		} else if (m2 == m1) {
			if (d2 < d1) {
				swap(x1, x2), swap(d1, d2), swap(m1, m2);
			}
		}
	}
}

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		ans = 0;
		cin >> mt1; scanf("%d, %d", &d1, &x1);
		cin >> mt2; scanf("%d, %d", &d2, &x2);
		m1 = monthIndex(mt1), m2 = monthIndex(mt2);
		swapDates();
		if (x1 != x2) {
			int r400, r100, r4, aux1, aux2;
			aux1 = (x1 - x1%400 + ((x1 % 400 > 0) ? 400 : 0)), aux2 = (x2 - x2%400);
			r400 = (aux1 <= aux2) ? ((aux2 - aux1)/400) + 1 : 0;
			aux1 = (x1 - x1%100 + ((x1 % 100 > 0) ? 100 : 0)), aux2 = (x2 - x2%100);
			r100 = (aux1 <= aux2) ? ((aux2 - aux1)/100) + 1 : 0;
			aux1 = (x1 - x1%4 + ((x1 % 4 > 0) ? 4 : 0)), aux2 = (x2 - x2%4);
			r4 = (aux1 <= aux2) ? ((aux2 - aux1)/4) + 1 : 0;
			ans = ans + r4 - r100 + r400;
			if (checkYear(x1) && m1 > 2) --ans;
			if (checkYear(x2) && ((m2 == 2 && d2 < 29) || m2 < 2)) --ans;
		} else {
			if (checkYear(x1)) {
				if (m1 <= 2 && (m2 > 2 || (m2 == 2 && d2 == 29))) {
					++ans;
				}
			}
		}
		printf("Case %d: %d\n", i, ans);
	}
}