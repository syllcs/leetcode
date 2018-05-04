#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	stack<int> s;
	s.push(2);
	s.push(3);
	cout << s.size() << endl;
	cout << s.at(0) << endl;
	cout << s[1] << endl;
}
