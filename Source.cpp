#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
ifstream input("thefile.txt");
ifstream input2("thefile2.txt");
ofstream output("output.txt");
ofstream warnput("warning.txt");

#define SAME_LINES 78

class Plague {
public:
	string str;
	string code = "0";
};

int main(){
	string space; string spacett; string spacenm; string dummy; int i; int line = 0;
	Plague Eng;
	Plague Tur;
	for (i = 0; i < SAME_LINES+1; i++) {
		getline(input, space);
		getline(input2, space);
		output << space << '\n';
		line++;
	}
	while ( spacett != "EndLoadTT" && spacenm != "EndLoadTT") {
		input >> spacett;  input2 >> dummy;
		input >> spacenm;  input2 >> dummy;
		getline(getline(input, dummy, '"'), Eng.str, '"') >> Eng.code;
		getline(getline(input2, dummy, '"'), Tur.str, '"') >> Tur.code;
		line++;
		if (Eng.code == Tur.code && spacett != "EndLoadTT" && spacenm != "EndLoadTT") {
			output << spacett << " ";
			output << spacenm << " ";
			output << "\"" << Tur.str << "\"" << " " << Eng.code << endl;
		}
		else if (spacett != "EndLoadTT" && spacenm != "EndLoadTT"){
			while (Eng.code != Tur.code && spacett != "EndLoadTT") {
				output << spacett << " ";
				output << spacenm << " ";
				output << "\"" << Eng.str << "\"" << " " << Eng.code << endl;
				warnput << line << endl;
				input >> spacett;
				input >> spacenm;
				getline(getline(input, space, '"'), Eng.str, '"') >> Eng.code;
				line++;
			}
			output << spacett << " ";
			output << spacenm << " ";
			output << "\"" << Tur.str << "\"" << " " << Eng.code << endl;

		}
	}

	output << "EndLoadTT" << endl;
	return 0;
}