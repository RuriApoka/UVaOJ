#define LOCAL

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef vector<int> IP;
typedef IP Line;
typedef vector<Line> IPNetwork;
typedef vector<bitset<8> > Binary;

bool readInIP(IPNetwork& ip);
void computeAns(const IPNetwork& ip, IP& network, IP& mask);
void computeBound(const Line& line, int& network, int& mask);
void printAns(IP& network, IP& mask);
void printIP(const IP& ip);

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);

	IPNetwork ip;
	while (readInIP(ip)) {
		IP network;
		IP mask;
		computeAns(ip, network, mask);
		printAns(network, mask);
		ip.clear();
	}
	
	return 0;
}

bool readInIP(IPNetwork& ip) {
	int m;
	if (cin >> m) {
		ip.resize(4);
		for (size_t i = 0; i < ip.size(); ++i) {
			ip[i].reserve(m);
		}

		int t;
		for (int i = 0; i < m; ++i) {
			cin >> t;
			ip[0].push_back(t);
			for (size_t j = 1; j < ip.size(); ++j) {
				cin.get();
				cin >> t;
				ip[j].push_back(t);
			}
		}
		return true;
	}
	else {
		return false;
	}
}

void computeAns(const IPNetwork& ip, IP& network, IP& mask) {
	network.resize(4, 0);
	mask.resize(4, 0);
	for (size_t i = 0; i < ip.size(); ++i) {
		size_t j;
		for (j = 1; j < ip[i].size(); ++j) {
			if (ip[i][j] != ip[i][j - 1]) {
				break;
			}
		}

		if (ip[i].size() == j) {
			network[i] = ip[i][0];
			mask[i] = 255;
		}
		else {
			computeBound(ip[i], network[i], mask[i]);
			break;
		}
	}
}

void computeBound(const Line& line, int& network, int& mask) {
	Binary binary(line.size());
	bitset<8> t;
	for (size_t i = 0; i < binary.size(); ++i) {
		binary[i] = line[i];
	}
	for (int i = 7; i > -1; --i) {
		size_t j;
		for (j = 1; j < binary.size(); ++j) {
			if (binary[j][i] != binary[j - 1][i]) {
				break;
			}
		}
		if (binary.size() != j) {
			for (; i > -1; --i) {
				binary[0][i] = 0;
			}
			break;
		}
		else {
			t.set(i);
		}
	}
	network = binary[0].to_ulong();
	mask = t.to_ulong();
}

void printAns(IP& network, IP& mask) {
	printIP(network);
	printIP(mask);
}

void printIP(const IP& ip) {
	for (size_t i = 0; i < ip.size() - 1; ++i) {
		cout << ip[i] << '.';
	}
	cout << ip[ip.size() - 1] << endl;
}