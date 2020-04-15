#include "FOR_MATRIX.h"

//В репозитории есть файл "Отчет курсач.docx" , в котором четко и ясно
//излагается про содержимое в данной проге. Успехов!

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
M:	cout << "\t\t\t\t\tCholesky Decomposition.\n\n\n";


	vector<vector<double> > A(ChooseMatrix::MatrixSize, vector<double>(ChooseMatrix::MatrixSize));	
	A = ChooseMatrix::ShowMatrix_A(ChooseMatrix::MatrixSize);
	
	ChooseMatrix::Create_L_and_Lt(A);

	int select = 0;
	cout << endl << "Start again?\nYes - enter 1, No - any key : " << endl;
	cin >> select;
	if (select == 1)
	{
		system("cls");
		goto M;
	}

	else return 0;

	system("pause");
	cin.get();
	return 0;
}

