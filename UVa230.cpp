#define LOCAL

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <set>
using namespace std;

typedef pair<string, string> Book;
typedef map<string, string> NameAuthor;
typedef NameAuthor::iterator NAIt;
typedef Book AuthorName;
typedef map<AuthorName, bool> Books;
typedef Books::iterator BIt;
typedef set<AuthorName> Returned;
typedef Returned::iterator RIt;

bool readInBooks(Books& books, NameAuthor& name_author);
void excuteCommand(Books& books, NameAuthor& name_author);
inline void borrowBook(Books& books, NameAuthor& name_author, string& book_name);
inline void returnBook(NameAuthor& name_author, Returned& returned, string& book_name);
void shelveBook(Books& books, Returned& returned);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	Books books;
	NameAuthor name_author;
	while (readInBooks(books, name_author)) {
		excuteCommand(books, name_author);
	}
	return 0;
}

bool readInBooks(Books& books, NameAuthor& name_author) {
	string info;
	while (getline(cin, info) && ("" != info)) {
		if ("END" == info) {
			return true;
		}
		else {
			int index = info.find(" by ");
			books.insert({ { string(info.begin() + index + 4, info.end()),
				string(info.begin(), info.begin() + index) }, true });
			name_author.insert({ string(info.begin(), info.begin() + index),
				string(info.begin() + index + 4, info.end()) });
		}
	}
	return false;
}

void excuteCommand(Books& books, NameAuthor& name_author) {
	Returned returned;
	string command, book_name;
	for (cin >> command; "END" != command; cin >> command) {
		if ("SHELVE" == command) {
			shelveBook(books, returned);
		}
		else {
			cin.get();
			getline(cin, book_name);
			if ("BORROW" == command) {
				borrowBook(books, name_author, book_name);
			}
			else {
				returnBook(name_author, returned, book_name);
			}
		}
	}
}

void borrowBook(Books& books, NameAuthor& name_author, string& book_name) {
	books[{name_author[book_name], book_name}] = false;
}

void returnBook(NameAuthor& name_author, Returned& returned, string& book_name) {
	returned.insert({ name_author[book_name], book_name });
}

void shelveBook(Books& books, Returned& returned) {
	BIt b_it;
	for (RIt r_it = returned.begin(); r_it != returned.end(); ++r_it) {
		b_it = books.find(*r_it);
		b_it->second = true;
		if (books.begin() == b_it) {
			cout << "Put " << r_it->second << " first" << endl;
		}
		else {
			for (--b_it; (books.begin() != b_it) && (false == b_it->second); --b_it)
				;
			if ((books.begin() != b_it) || (true == b_it->second)) {
				cout << "Put " << r_it->second << " after " << b_it->first.second << endl;
			}
			else {
				cout << "Put " << r_it->second << " first" << endl;
			}
		}
	}
	cout << "END" << endl;
	returned.clear();
}