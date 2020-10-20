#include "state.h"
#include <iostream>

using namespace std;

string state::get_continent()
{
	return continent;
}
/*string state::get_language()
{
	return language;
}*/

void state::read_from(ifstream& file)
{
	getline(file, country);
	getline(file, capital);
	getline(file, government);
	getline(file, language);
	getline(file, religion);
	getline(file, continent);
	file >> area;
	file.ignore();
	file >> population;
	file.get();
}

void state::display()
{
	cout << "\nCountry : " << country << endl;
	cout << "\nCapital : " << capital << endl;
	cout << "\nGoverment : " << government << endl;
	cout << "\nLanguage : " << language << endl;
	cout << "\nReligion : " << religion << endl;
	cout << "\nArea : " << area << endl;
	cout << "\nPopulation : " << population << endl;
	cout << "\n-----------##------------";
}

void Sum(state ct[], int num, string acontinent)
{
	ofstream outfile("sum.txt");
	float sumarea = 0;
	int sumpop = 0;
	for (int i = 0; i < num; i++)
	{
		if (ct[i].get_continent() == acontinent)
		{
			sumarea += ct[i].area;
			sumpop += ct[i].population;
		}
	}
	cout << "\nSum area : " << sumarea << endl;
	cout << "Sum population : " << sumpop << endl;
	outfile << "Sum area : " << sumarea << endl;
	outfile << "Sum population : " << sumpop << endl;
	outfile.close();
}

void   find(state ct[], int num, string lang)
{
	ofstream outfile("ex2.txt");
	int max = ct[0].population;
	int j = 0;
	for (int i = 1; i <= num; i++)
	{
		if (ct[i].language == lang)
		{
			if (max < ct[i].population)
			{
				max = ct[i].population;
				j = i;
			}
		}
	}
	cout << "\nName and capital of the largest state in terms of population :" << endl;
	cout << "Country : " << ct[j].country << endl;
	cout << "Capital : " << ct[j].capital << endl;
	outfile << "Name and capital of the largest state in terms of population :" << endl;
	outfile << "Country : " << ct[j].country << endl;
	outfile << "Capital : " << ct[j].capital << endl;
	outfile.close();
}
