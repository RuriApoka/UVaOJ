#define LOCAL

#include <cstdio>
#include <array>
using namespace std;

typedef array<int, 4> Sheet;
typedef array<Sheet, 25> Book;

void computeAns(Book& book, const int pages);
void printAns(const Book& book, const int pages);
void lessThanFivePages(const Book& book, const int pages);
void moreThanFourPages(const Book& book, const int pages);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int pages;
	Book book;
	while (scanf("%d", &pages) && (0 != pages)) {
		computeAns(book, pages);
		printAns(book, pages);
	}
	return 0;
}

void computeAns(Book& book, const int pages) {
	int page = 1;
	int sheets = (pages >> 2) + (0 != (pages % 4));
	for (int i = 0; i < sheets; ++i) {
		book[i][1] = page++;
		book[i][2] = page++;
	}
	for (int i = sheets - 1; page <= pages; --i) {
		book[i][3] = page++;
		book[i][0] = page++;
	}
}

void printAns(const Book& book, const int pages) {
	printf("Printing order for %d pages:\n", pages);
	if (pages < 5) {
		lessThanFivePages(book, pages);
	}
	else {
		moreThanFourPages(book, pages);
	}
}

void lessThanFivePages(const Book& book, const int pages) {
	switch (pages) {
	case 1:
		puts("Sheet 1, front: Blank, 1");
		break;
	case 2:
		puts("Sheet 1, front: Blank, 1\nSheet 1, back : 2, Blank");
		break;
	case 3:
		puts("Sheet 1, front: Blank, 1\nSheet 1, back : 2, 3");
		break;
	default:
		puts("Sheet 1, front: 4, 1\nSheet 1, back : 2, 3");
		break;
	}
}

void moreThanFourPages(const Book& book, const int pages) {
	int sheets = (pages >> 2) + (0 != (pages % 4));
	int i = 1;
	switch (pages % 4) {
	case 1:
		i++;
		printf("Sheet 1, front: Blank, 1\nSheet 1, back : %d, Blank\n"
			"Sheet 2, front: Blank, %d\nSheet 2, back : %d, %d\n",
			book[0][2], book[1][1], book[1][2], book[1][3]);
		break;
	case 2:
		printf("Sheet 1, front: Blank, 1\nSheet 1, back : %d, Blank\n", book[0][2]);
		break;
	case 3:
		printf("Sheet 1, front: Blank, 1\nSheet 1, back : %d, %d\n", book[0][2], book[0][3]);
		break;
	default:
		i--;
		break;
	}
	for (; i < sheets; ++i) {
		printf("Sheet %d, front: %d, %d\nSheet %d, back : %d, %d\n",
			(i + 1), book[i][0], book[i][1], (i + 1), book[i][2], book[i][3]);
	}
}