#include "FOR_MATRIX.h"

#pragma region Вывод матрицы А
vector<vector<double> > ChooseMatrix::ShowMatrix_A(int n)
{
	cout << "\nChoose matrix size(5 or 6):";
M:	cin >> n;
	ChooseMatrix::MatrixSize = n;

	fstream File;
	string p;
	vector<vector<double> > mymatrix(ChooseMatrix::MatrixSize, vector<double>(ChooseMatrix::MatrixSize));

	if (n == 5)
	{
		p = "Matrix55.txt";
		cout << "File Matrix55.txt is opened.\n\nMatrix A 5x5:" << endl;
	}
	else if (n == 6)
	{
		p = "Matrix66.txt";
		cout << "File Matrix66.txt is opened.\n\nMatrix A 6x6:" << endl;
	}
	else
	{
		cout << "Error , choose another size" << endl;
		goto M;
	}


	File.open(p);
	if (!File.is_open())
	{
		cout << "ERROR! File is not founded";
	}
	else
	{
		for (int i = 0; i < ChooseMatrix::MatrixSize; i++) 
		{
			for (int j = 0; j < ChooseMatrix::MatrixSize; j++)
			{
				mymatrix.resize(ChooseMatrix::MatrixSize);
				File >> mymatrix[i][j];
				cout << std::setw(15u) << mymatrix[i][j];
			}
			cout << endl;
		}
	}
	cout << endl;
	File.close();
	return mymatrix;
}
#pragma endregion


#pragma region Метод Холецкого

void ChooseMatrix::Create_L_and_Lt(vector<vector<double> >& A)
{
	int n = ChooseMatrix::MatrixSize;
	vector<vector<double> > L(n, vector<double>(n));

	L[0][0] = sqrt(A[0][0]);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			double sum = 0;
			if (i == j)
			{
				for (int k = 0; k < j; k++)
				{
					sum += pow(L[j][k], 2);
				}
				L[i][j] = sqrt(A[i][j] - sum);
			}
			else
			{
				for (int k = 0; k < j; k++)
				{
					sum += L[i][k] * L[j][k];
				}
				L[i][j] = (A[i][j] - sum) / L[j][j];
			}

		}
	}

	cout << endl << "Matrix L:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << std::setw(15u) << L[i][j];
		}
		cout << endl;
	}
	cout << endl << endl << endl << "Matrix Lt:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << std::setw(15u) << L[j][i];

		cout << endl;
	}
	
	ofstream FileMatrixL("Lower_Triangular.txt", std::ios_base::out);
	if (!FileMatrixL.is_open())
		cout << "Matrix L not written to file";
	else
	{
		cout << "Matrix L  written to Lower_Triangular.txt" << endl;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				FileMatrixL << std::setw(15u) << L[i][j];
			}
			FileMatrixL << endl;
		}
	}
	FileMatrixL.close();


	ofstream FileMatrixLt("Transp_Lower_Triangular.txt", std::ios_base::out);
	if (!FileMatrixLt.is_open())
		cout << "Matrix Lt not written to file";
	else
	{
		cout << "Matrix Lt  written to Transp_Lower_Triangular.txt" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				FileMatrixLt << std::setw(15u) << L[j][i];
			}
			FileMatrixLt << endl;
		}
	}
	FileMatrixLt.close();
}
#pragma endregion






