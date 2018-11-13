#include <iostream>
#include <fstream>
#include <vector>
#define INF 99999//which means two points can't reach each other
using namespace std;
using std::vector;
typedef vector<size_t> D1array;
typedef vector<vector<size_t>> D2array;

int floydwarshallMethod(int N, D2array matrix, D2array Pi);

int main()
{
	int N = 0;
	int i, j;
	cout << "input the number of the points" << endl;
	cin >> N;
	while (N < 2)
	{
		cout << "please input 2 points or more." << endl;
		cin >> N;
	}
	cout << "Make sure your matrix has " << N << " * " << N << " numbers."  << endl;
	
	D2array matrix(N + 1, D1array(N + 1, 0));//initial a (n+1)*(n+1)matrix
	D2array Pi(N + 1, D1array(N + 1, 0));//initial point route

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (matrix[i][j] >= INF)
			{
				Pi[i][j] = INF;
			}
			if (i == j)
			{
				Pi[i][j] = 0;
			}
			if (i != j && matrix[i][j] < INF)
			{
				Pi[i][j] = j;
			}
		}
	}

	ifstream fin("Ddata.txt");
	ofstream foutD("D_result.txt");
	ofstream foutP("P_result.txt");
	if (!fin)
	{
		cout << "read in failed!" << endl;
	}
	else
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				fin >> matrix[i][j];
			}
		}
		cout << "read in success!" << endl;
	}

	floydwarshallMethod(N, matrix, Pi);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (matrix[i][j] >= 99999)
			{
				foutD << "INF";
			}
			else foutD << matrix[i][j] << " ";
			foutD << " ";
		}
		foutD << "\n";
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Pi[i][j] >= 99999)
			{
				foutP << "INF";
			}else foutP << Pi[i][j] << " ";
			foutP << " ";
		}
		foutP << "\n";
	}
	return 0;
}

int floydwarshallMethod(int N, D2array matrix, D2array Pi)
{
	/*
	input:the distance between each 2 points
	output:the shortest distance between each 2 points
	*/
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (matrix[i][j] > matrix[i][k] + matrix[k][j])
				{
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					//Pi[i][j] = Pi[k][j];
					Pi[i][j] = Pi[i][k];
					//this path routes k
					//so i->j's shortest path needs k->j's shortest path
					//so it must route Pi[k][j]
				}
			}
		}
	}
	return 0;
}