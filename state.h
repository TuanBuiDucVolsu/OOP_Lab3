#ifndef STATE_H
#define STATE_H
#include <string>
#include <fstream>
using std::string;
using std::ifstream;
class state
{
public :
    string country;
    string capital;
    string government;
    string language;
    string religion;
    string continent;
    float area;
    int population;
    void read_from(ifstream& file);
    void display();
    string get_continent();
   // string get_language();
};
void Sum(state[], int, string);
void find(state[], int, string);

#endif

