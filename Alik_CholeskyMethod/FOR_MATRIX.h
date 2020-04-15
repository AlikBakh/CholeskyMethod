#ifndef FOR_MATRIX_H_
#define FOR_MATRIX_H_

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <iterator>


using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::fstream; 
using std::ofstream;


namespace ChooseMatrix
{
	static int MatrixSize;

	vector<vector<double> > ShowMatrix_A(int n);

	void Create_L_and_Lt(vector<vector<double> >& A);
}


#endif // !FOR_MATRIX_H_
