// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
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
	char vertex[VertexNum];                                //�����         
	int edges[VertexNum][VertexNum];                       //�ڽӾ���,�ɿ����߱�         
	int n, e;                                               //ͼ�е�ǰ�Ķ������ͱ���         
}MGraph;
void Floyd(MGraph g);
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
