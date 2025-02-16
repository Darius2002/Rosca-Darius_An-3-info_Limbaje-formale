
#include <iostream>
#include<string>
using namespace std;

string Concatenare(string s1, string s2);
string Inversare(string s1);
string Substitutie(string s, string a, string b);
int Lungime(string s);

int main()
{
	string s1, s2;
	int c = 0;
	cout << "Alegeti sirul s1: " << endl;
	cin >> s1; 
	cout << endl << "Alegeti sirul s2: " << endl;
	cin >> s2;
	cout << endl;

	while (c != 1) {
		cout << "1.Stop" << endl << "2.Concatenare" << endl << "3.Inversare" << endl << "4.Subtitutie" << endl << "5.Lungime" << endl;

		cin >> c;

		switch (c)
		{
			case 2:
			{
				cout << Concatenare(s1, s2) << endl;
				break;
			}
			
			case 3:
			{
				int aux = 0;
				cout << "1.s1" << endl << "2.s2" << endl;
				cin >> aux;
				if (aux == 1) {
					cout << Inversare(s1);
				}
				else if (aux == 2)
				{
					cout << Inversare(s2);
				}
				else {
					cout << "Nu ati ales un sir existent!!!" << endl;
				}

				break;
			}
			case 4: 
			{
				string a, b;
				int aux = 0; 
				cout << "Alege simbolul care vrei sa fie inlocuit" << endl;
				cin >> a;
				cout << "Alege simbolul care il va inlocui" << endl;
				cin >> b;

				if (a.length() != 1 || b.length() != 1)
				{
					cout << "Trebuie sa alegi doar un simbol";
				}
				else
				{
					cout << "Alege sirul" << endl << "1.s1" << endl << "2.s2" << endl;
					cin >> aux;
					if (aux == 1) {
						s1 = Substitutie(s1, a, b);
						cout << s1 << endl;
					}
					else if (aux == 2) {
						s2 = Substitutie(s2, a, b);
						cout << s2 << endl;
					}
					else {
						cout << "Nu ati ales un sir existent!!!" << endl;
					}
				}
				break;
			}
			case 5:
			{
				int aux = 0;
				cout << "Alege sirul" << endl << "1.s1" << endl << "2.s2" << endl;
				cin >> aux;
				if (aux == 1) {
					cout << Lungime(s1) << endl;
				}
				else if (aux == 2) {
					cout << Lungime(s2) << endl;
				}
				else {
					cout << "Nu ati ales un sir existent!!!" << endl;
				}

				break;
			}
		}
		cout << endl;
	}

}


string Concatenare(string s1, string s2) {

	return (s1 + s2);
}

string Inversare(string s1) {

	string aux = s1;
	reverse(aux.begin(), aux.end());
	return aux;

}

string Substitutie(string s, string a, string b) {

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == a[0]) {
			s[i] = b[0];
		}
	}
	return s;
}

int Lungime(string s) {
	return s.length();
}