#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
#include <queue>
using namespace std;

struct Job {
	int priority;
	int ix;
	bool ja;
} jobs[100];

queue<Job> fila;

int N, n, m;
int answ;

bool maior(Job &j)
{
	for (int i = 0; i < n; i++) {
		if (! jobs[i].ja && jobs[i].priority > j.priority) {
			return false;
		}
	}
	
	return true;
}

void go()
{
	Job j;
	j.ix = -1;
	
	while (j.ix != m) {
		j = fila.front();
		fila.pop();
		while (! maior(j)) {
			fila.push(j);
			j = fila.front();
			fila.pop();
		}
		jobs[j.ix].ja = true;
		++answ;
	}
	
}

int main()
{
	cin >> N;
	Job j;

	while (N--) {
		//cout << "here" << endl;
		cin >> n >> m;
		while(! fila.empty()) fila.pop();
		answ = 0;
		for (int i = 0; i < n; i++) {
			cin >> j.priority;
			j.ix = i;
			j.ja = false;
			fila.push(j);
			jobs[i] = j;	
		}
		go();
		cout << answ << endl;
	}

	return 0;
}
