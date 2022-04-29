#include <iostream>
#include <string>
using namespace std;
bool is_id_number(const string& s) {
	int y, m, d;
	string b[11] = { "1","0","X","9","8","7","6","5","4","3","2"};
	int a[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int flag = 0;
	string sex;
	int judge = 0;
	if (s.length() == 18) {
		for (int i = 0; i < 17; i++) {
			if (s[i] < '0' || s[i] > '9') {
				return false;
				break;
			}
			if (i == 16) {
				y = stoi(s.substr(6, 4)); m = stoi(s.substr(10, 2)); d = stoi(s.substr(12, 2));
			}
		}
		if (m > 12 || m < 1)
			return false;
		if (y % 400 == 0 || y % 100 != 0 && y % 4 == 0) {
			day[1] = 29;
		}
		if (d > day[m - 1] || d < 1)
			return false;
		for (int i = 0; i < 17; i++) {
			judge += stoi(s.substr(i, 1)) * a[i];
		}
		judge = judge % 11;
		if (s.substr(17, 1) == b[judge])
			flag = 1;
		if (flag == 1)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main() {
	string s;
	int sexual = 0;
	for (s; getline(cin, s);) {
		cout << s << ":";
		if (is_id_number(s)) {
			cout << " " << s.substr(6, 4) << "-" << s.substr(10, 2) << "-" << s.substr(12, 2) << " ";
			sexual = stoi(s.substr(14, 3));
			if (sexual % 2 == 0)
				cout << "F" << endl;
			else
				cout << "M" << endl;
		}
		else
			cout << " invalid" << endl;
	}
}