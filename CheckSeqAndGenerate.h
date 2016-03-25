#pragma once

#include "Graph.h"

class CheckSeqAndGenerate: public Graph{

public:
    CheckSeqAndGenerate(int *arraySeq, int NSize);
    /*Liczy sume klasy tablicy*/
    int CountSum();
    /*Liczy sume klasy tablicy danego jako argument*/
    int CountSumForArray(int *_SeqToCheck, int _arraySize);
    /*Funkcja prawdzajaca czy dana sekwencja jest grafem*/
    bool CheckSeq();
    /*Jeżeli dana sekwencja jest grafem, to gon generuje*/
    void GenerateGraph(bool isGraph);
    ~CheckSeqAndGenerate();
protected:
    int *_SeqToCheck;
    int _arraySize;
};
