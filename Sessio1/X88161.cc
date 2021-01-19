#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct game {
	int x, y;
};

typedef vector<game> Row;
typedef vector<Row> League;

struct result {
	int team_num = 0;
	int score = 0;
	int goals_favor = 0;
	int goals_contra = 0;
};

League read_mat(int n) {
	League l(n, Row(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> l[i][j].x >> l[i][j].y; 
		}
	}
	return l;
}

bool comp(const result& a, const result& b) {
	if (a.score == b.score and a.goals_favor - a.goals_contra == b.goals_favor - b.goals_contra) return a.team_num < b.team_num;
	else if (a.score == b.score) return a.goals_favor - a.goals_contra > b.goals_favor - b.goals_contra;
	return a.score > b.score;
}

int main() {
	int n;
	cin >> n;
	League l = read_mat(n);
	vector<result> v(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				v[i].goals_favor += l[i][j].x;
				v[j].goals_favor += l[i][j].y;
				v[i].goals_contra += l[i][j].y;
				v[j].goals_contra += l[i][j].x;
				if (l[i][j].x > l[i][j].y) v[i].score += 3;
				else if (l[i][j].x < l[i][j].y) v[j].score += 3;
				else {
					++v[i].score;
					++v[j].score;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) v[i].team_num = i + 1;
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; ++i) {
		cout << v[i].team_num << ' ' << v[i].score << ' ' << v[i].goals_favor << ' ' << v[i].goals_contra << endl;
	}
}
