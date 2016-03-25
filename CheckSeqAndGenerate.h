#pragma once

#include "Graph.h"

class CheckSeqAndGenerate: public Graph{

public:
    CheckSeqAndGenerate(int *arraySeq, int NSize);
    int CountSum();
    int CountSumForArray(int *_SeqToCheck, int _arraySize);
    bool CheckSeq();
    void GenerateGraph(bool isGraph);
    ~CheckSeqAndGenerate();
protected:
    int *_SeqToCheck;
    int _arraySize;
};
