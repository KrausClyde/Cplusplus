#include "Map.h"
#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void Floyd(MGraph g);

void Floyd(MGraph g)
{
	int A[VertexNum][VertexNum];
	int path[VertexNum][VertexNum];
	int i, j, k, n = VertexNum;
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
	{
		A[i][j] = g.edges[i][j];
		path[i][j] = -1;
	}
	for (k = 0; k<n; k++)
	{
		for (int row = 0; row<n; row++)
		for (int col = 0; col<n; col++)
		if (A[row][col]>(A[row][k] + A[k][col]))
		{
			A[row][col] = A[row][k] + A[k][col];
			path[row][col] = k;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf(" %d ", path[i][j]);
		printf("\n");
	}
	printf("path\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf(" %d ", A[i][j]);
		printf("\n");
	}

}
