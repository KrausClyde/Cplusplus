// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once
/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
*/
const int  VertexNum = 4;
const int MAXNUM = 10;
typedef struct
{
	char vertex[VertexNum];                                //顶点表         
	int edges[VertexNum][VertexNum];                       //邻接矩阵,可看做边表         
	int n, e;                                               //图中当前的顶点数和边数         
}MGraph;
void Floyd(MGraph g);
// TODO:  在此处引用程序需要的其他头文件
