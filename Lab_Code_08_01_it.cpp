// Lab_Code_08_01_it.cpp

#include <iostream>

using namespace std;

bool IsTriple(const char* s, const int i);
bool ContainsTriple(const char* s);
void ReplaceTriples(const char* s, char* t);

int main() {
	const int maxLen = 100;
	char s[maxLen + 1];   // вхідний рядок
	char t[maxLen + 1];   // результат (кожна трійка "!!!" стає парою "**", рядок не довшає)

	cout << "Enter string: ";
	cin.getline(s, maxLen + 1);

	if (ContainsTriple(s))
		cout << "Group '!!!' found" << endl;
	else
		cout << "No group '!!!' found" << endl;

	ReplaceTriples(s, t);
	cout << "Modified string: " << t << endl;

	return 0;
}

// true, якщо починаючи з позиції i в рядку s стоять три знаки оклику поспіль
bool IsTriple(const char* s, const int i) {
	return s[i] == '!' && s[i + 1] == '!' && s[i + 2] == '!';
}

// true, якщо рядок містить хоча б одну трійку "!!!"
bool ContainsTriple(const char* s) {
	int i = 0;
	while (s[i] != '\0') {
		if (IsTriple(s, i))
			return true;
		i++;
	}
	return false;
}

// записує в t копію рядка s, у якій кожну трійку "!!!" замінено на "**"
void ReplaceTriples(const char* s, char* t) {
	int i = 0;   // позиція в s
	int j = 0;   // позиція в t
	while (s[i] != '\0') {
		if (IsTriple(s, i)) {
			t[j++] = '*';
			t[j++] = '*';
			i += 3;
		}
		else
			t[j++] = s[i++];
	}
	t[j] = '\0';
}