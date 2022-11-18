#include<iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<int, map<int, string>> m;

	ifstream ifs;
	ifs.open("input.txt");
	string str;
	getline(ifs, str);
	int N = stoi(str);
	if (N > 200000 || N < 2) {

		return 0;
	}
	int id, day, hour, minutes, time;
	string status;

	int n = 0;
	int aN = 0;

	//считывание по словам строчки
	while (!ifs.eof() && aN != N)
	{
		switch (n) {
		case 0:
			ifs >> day;
			n++;
			break;
		case 1:
			ifs >> hour;
			n++;
			break;
		case 2:
			ifs >> minutes;
			n++;
			break;
		case 3:
			ifs >> id;
			n++;
			break;
		case 4:
			ifs >> status;
			n++;
			break;
		case 5:
			n = 0;
			time = day * 24 * 60 + hour * 60 + minutes;
			aN++;
			m[id].emplace(time, status);
			break;
		}
	}
	map <int, int> taxi;
	for (auto qw1 : m) {
		int time_start = 0, time = 0;
		for (auto qw2 : qw1.second) {
			if (qw2.second == "A") {
				time_start = qw2.first;
			}
			else if (qw2.second == "S" || qw2.second == "C") {
				time = time + qw2.first - time_start;
				time_start = 0;
			}
		}
		taxi[qw1.first] = time;
		time = 0;
	}
	ofstream ofs;
	ofs.open("output.txt");
	bool q = true;
	for (auto now : taxi) {
		if (q == false)ofs << " ";
		q = false;
		ofs << now.second;
		
	}
	ofs.close();
	ifs.close();
	return 0;
}
/*for (int j = 0; j < n; j++) {
	getline(cin, s);
	eng = s.substr(0, s.find(' ')); //выделяем из строки английское слово
	s = s.substr(s.find('-') + 2, s.size()); //оставляем в строке только латинские слова

	i = s.find(',');
	while (i > 0) { //для каждого латинского слова создаём запись в словаре и добавляем туда eng 
		a[s.substr(0, i)].insert(eng);
		s = s.substr(i + 2, s.size() - 1);
		i = s.find(',');
	}
	a[s].insert(eng);
}
cout << a.size() << "\n"; //вывод
for (auto c : a) {
	i = 1;
	cout << c.first << " - ";
	for (auto lat : c.second) {
		cout << lat;
		if (i != c.second.size()) { cout << ", "; }
		else { cout << "\n"; }
		i++;
	}
}*/

/*	
	ofstream ofs;
	ofs.open("output.txt");
	if(i!=0)ofs<<" ";
	ofs<<now.second;

*/