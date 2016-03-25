#pragma once
#include "Graph.h"

class GraphRandomization: public Graph
{
public:
    GraphRandomization();

/*Tworzy graf i generuje*/
    void MakeAndGenerate();
/*Generuje graf jako macierz*/
    void GenerateAsMatrixNL();
/*Randomizuje macierz*/
    void Randomize();
    void printMatrix();
    ~GraphRandomization();

protected:
    bool **Matrix;
    int _NumberOfVertices;
    int _NumberOfEdges;
};
