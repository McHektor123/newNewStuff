#include "pch.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
using std::cerr;
using std::endl;
#include <fstream>
using std::ofstream;
#include <cstdlib>
#include <vector>
#include "Collumn.h"
#include "Writer.h"
// This program output values from an array to a file named example2.dat


Writer::Writer()
{
}

Writer::~Writer()
{
}

void Writer::print(vector<Collumn*> vec)
{
	ofstream outdata; // outdata is like cin
	outdata.open("table.txt"); // opens the file
	if (!outdata) { // file couldn't be opened
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}
	int longest = Utils::getLongestName(vec);
	outdata <<"Index" << "\t" << "Title" << setw(longest) << "\t" << "Length" << "\t" << "Gerne" << "\t" << "Rating" << endl;
	for (auto i : vec) {
	outdata << i->getNumber() << "\t"
		    <<i->getTitle()   << setw(27-i->getTitle().length())
			<< i->getLength() <<  " min" << "\t"
			<< i->getGerne()  << "\t"
			<< i->getRating() << "/10"
		<< endl;
	}
	outdata.close();
}