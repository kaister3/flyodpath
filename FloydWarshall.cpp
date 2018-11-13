#include <iostream>
#include <fstream>
#include <vector>
#define CANNOT_RAECH 99999//which means two points can't reach each other
using namespace std;
using std::vector;
typedef vector<size_t> D1array;
typedef vector<vector<size_t>> D2array;

int floydwarshallMethod(int i, int j, D2array matrix)
{
	/*
	input:the distance between each 2 points
	output:the shortest distance between each 2 points
	*/
	if (i == j)
	{
		return
	}
}

int main()
{
	int N = 0;
	int i, j, k;
	cout << "input the number of the points" << endl;
	cin >> N;
	while (N < 2)
	{
		cout << "please input 2 points or more." << endl;
		cin >> N;
	}
	cout << "Make sure your matrix has " << N << " * " << N << " numbers."  << endl;
	
	D2array matrix(N + 1, D1array(N + 1, 0));//initial a (n+1)*(n+1)matrix
	D2array point_route(N + 1, D1array(N + 1, 0));//initial point route

	ifstream fin("Ddata.txt");
	ifstream fin_point("Pdata.txt");
	ofstream fout("D_result.txt");
	ofstream fout("P_result");
	if (!fin)
	{
		cout << "read in failed!" << endl;
	}
	else
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				fin >> matrix[i][j];
			}
		}
		cout << "read in success!" << endl;
	}

	for (i =1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (matrix[i][j] >= 99999)
			{
				fout << "CannotReach";
			}
			else fout << matrix[i][j];
			fout << " ";
		}
		fout << "\n";
	}
	return 0;
}