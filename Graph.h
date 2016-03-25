#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <ctime>
#include <algorithm>

int cmp( int * arg1, int * arg2 );
class CheckSeqAndGenerate;
class Graph
{
	public:
		typedef int size_type;

	public:
		/** */
		Graph(void);
		/** */
		Graph(size_type counterNodes, size_type counterEdges);

		void GenerateGraphBegin(std::ofstream &graph, int NumberOfVertices, std::string NameOfFile,bool OverRead);
        void GenerateGraphEnd(std::ofstream &graph);
        void CountPoints(float *x, float *y, int n, float Degree);
        int CountSum(int *SeqTab, int NSize);
        bool IsInTab(int Value, int *Tab, int NSize);

/*		size_type getCounterNodes(void) const
		{
			return _counterNodes;
		}

		size_type getCounterEdges(void) const
		{
			return _counterEdges;
		}*/
        virtual ~Graph(){}
		//virtual void printGraph(void) = 0;
	protected:
	    static float Degree_Begin;
        static const float rad ;
		size_type _counterNodes;
		size_type _counterEdges;
};
