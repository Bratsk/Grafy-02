#pragma once
#include "Graph.h"

class GraphRandomization: public Graph
{
public:
    GraphRandomization();

    void MakeAndGenerate();
    void GenerateAsMatrixNL();
    void Randomize();
    void printMatrix();
    ~GraphRandomization();

protected:
    bool **Matrix;
    int _NumberOfVertices;
    int _NumberOfEdges;
};
