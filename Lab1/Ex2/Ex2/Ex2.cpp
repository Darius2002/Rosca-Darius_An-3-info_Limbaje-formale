
#include <iostream>
#include<string>
using namespace std;

string Concatenare(string s1, string s2);
string Repetare(string s, int n);
string Inversare(string s1);
string Extractie(string s, int i, int j);
string Inlocuire(string s, string a, string b);

int main()
{
	string s1;
	int c = 0;
	cout << "Alegeti cucantul: " << endl;
	getline(cin, s1);

	while (c != 1) {
		cout << "1.Stop" << endl << "2.Concatenare" << endl << "3.Repetare" << endl << "4.Inversare" << endl << "5.Extractie" << endl << "6.Inlocuire" << endl;
		cin >> c;

		switch (c)
		{
			case 2:
			{
				string s2;
				cout << "Al doilea cuvant: " << endl;
				cin >> s2;
				cout << Concatenare(s1, s2) << endl;
				break;
			}

			case 3:
			{
				int n = 0;
				cout << "Numarul de relici: " << endl;
				cin >> n;
				cout << Repetare(s1, n) << endl;
				break;
			}
			case 4:
			{
				cout << Inversare(s1) << endl;
				break;
			}
			case 5:
			{
				int i = 0, j = 0;
				cout << "Pozitaia de la care incepem: " << endl;
				cin >> i;

				if (i >= s1.length())
				{
					cout << "Pozita este prea mare" << endl;

				}
				else
				{
					cout << "Pozitaia finala: " << endl;
					cin >> j;
					if (j <= i) {
						cout << "Pozita finala este prea mare" << endl;
					}
					else
					{
						cout << Extractie(s1, i, j) << endl;
					}
				}



				break;
			}
			case 6:
			{
				string a, b;
				cout << "Sirul cautat: " << endl;
				getline(cin, a);
				cout << "Sirul inlocuitor: " << endl;
				getline(cin, b);
				cout << Inlocuire(s1, a, b) << endl; 
				break;
			}

			cout << endl;
		}
	}

}


string Concatenare(string s1, string s2) {

	return (s1 + s2);
}

string Repetare(string s, int n) {

	string r;

	for (int i = 0; i < n; ++i) 
	{
		r += s;
	}
	return r;
}

string Inversare(string s1) {

	string aux = s1;
	reverse(aux.begin(), aux.end());
	return aux;

}

string Extractie(string s, int i, int j) {
	string aux;

	for (int k = i; k <= j; ++k) {

		aux += s[k];
	}
	return aux;
}

string Inlocuire(string s, string a, string b) {
	int pos = s.find(a); 
	while (pos != string::npos) { 
		s.replace(pos, a.length(), b); 
		pos = s.find(a, pos + b.length()); 
	}
	return s; 
}