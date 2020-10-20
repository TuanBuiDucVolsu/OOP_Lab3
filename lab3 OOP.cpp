#include <iostream>
#include <string>
#include<Windows.h>
#include "state.h"

using namespace std;
void main()
{
	int N;
	ifstream infile;
	infile.open("state.txt");
	if (!infile.is_open())
	{
		cout << "Data file not found!"<<endl;
	}
	infile >> N;
	infile.get();
	state* ct = new state[N];

	for (int i = 0; i < N; i++)
	{
		ct[i].read_from(infile);
	}
	infile.close();
	for (int i = 0; i < N; i++)
	{
		ct[i].display();
	}
	string slanguage;
	cout << "\n+Enter the language : ";
	getline(cin, slanguage);
	find(ct, N, slanguage);

	string scontinent;
	cout << "\n+Enter the continent : ";
	getline(cin, scontinent);
	Sum(ct, N, scontinent);

	delete[] ct;
	
}
