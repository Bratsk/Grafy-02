#include "CheckSeqAndGenerate.h"

CheckSeqAndGenerate::CheckSeqAndGenerate(int *arraySeq, int NSize): Graph()
{
    _SeqToCheck = new int[NSize];
    for(int i=0; i<NSize;i++)
        _SeqToCheck[i] = arraySeq[i];
    _arraySize = NSize;
}
CheckSeqAndGenerate::~CheckSeqAndGenerate(){
    delete [] _SeqToCheck;
}
bool CheckSeqAndGenerate::CheckSeq()
{
    /*Tworze kopie listy sekwencji  ktorej bede korzystal*/
    int *SequenceTab = new int[_arraySize];
    for(int i=0; i<_arraySize;i++)
        SequenceTab[i] = _SeqToCheck[i];

    for(int i=0; i<_arraySize;i++)
        std::cout << SequenceTab[i] << " ";
    std::cout << "\n";
    /*Dodatkowa tablica do ktorej beda przypisywane stopnie-1*/
    int *TmpSeqTab;

    int Sum = CountSum();
    qsort(SequenceTab, _arraySize, sizeof(int), ( int( * )( const void *, const void * ) ) cmp);
    /*Sprawdzam warunki poczatkowe tj. czy suma jest parzysta 
    i czy najwiekszy element z listy nie jest wiekszy od liczy wierzcholkow*/ 
    if(Sum%2==1 || SequenceTab[0] >= _arraySize)
        return false;
    else{
        int IsZero = 1;
        while(IsZero>0){
            int d_i = SequenceTab[0];
            IsZero = 0;
            int _newarraySize = _arraySize-1;

            TmpSeqTab = new int[_newarraySize];
            /*Okreslamy liczbe stopni*/
            int deg = _newarraySize - d_i;
            /* pomocniczej tablicy przypisujemy elementy tablicy od [0 - deg] 
            pomniejszone o 1*/
            for(int i=0; i<_newarraySize-deg; i++){
                TmpSeqTab[i] = SequenceTab[i+1]-1;
                IsZero += TmpSeqTab[i];}
            /* pomocniczej tablicy przypisujemy elementy tablicy od [deg - arraySize] */
            for(int i=_newarraySize-deg; i<_newarraySize; i++){
                TmpSeqTab[i] = SequenceTab[i+1];
                IsZero += TmpSeqTab[i];}

            for(int i=0; i<_newarraySize;i++)
                std::cout << TmpSeqTab[i] << " ";
            std::cout << "\n";
            /*Sortujemy tablice */
            qsort(TmpSeqTab, _newarraySize, sizeof(int), ( int( * )( const void *, const void * ) ) cmp);

            delete [] SequenceTab;
            SequenceTab = TmpSeqTab;
        }
        delete [] TmpSeqTab;
        if(!IsZero)
            return true;
        else
            return false;
    }
}

/*Funkcja dziala dosc skomplikowanie. W posortowaniej sekwencji, 
przechodzimy od najwiekszej n-liczby stopni (wierzcholek oznaczamy jako nr 1)
i przypisujemy je kolejne wiercholki (2,3,..., m) gdzie m to n-ty wierzcholek.
Wiercholkowi przypisujemy 0, a elemntom 2-n odejmujemy 1. Nastepnie przechodzimy
do wiercholka nr 2 i powtarzamy proces, az sekwencja wypelni sie zerami*/
void CheckSeqAndGenerate::GenerateGraph(bool isGraph)
{

    if(!isGraph){
        std::cout << "Sequence is not a Graph";
        return;}

        std::cout << "Sequence is a Graph\n";
        qsort(_SeqToCheck, _arraySize, sizeof(int), ( int( * )( const void *, const void * ) ) cmp);
        /*Okreslamy ilosc wiercholkow i krawedzi grafu*/
        int NumberVertices = _arraySize;
        int NumberEdges = CountSumForArray(_SeqToCheck, _arraySize)/2;

        std::cout << "Number of Edges: " << NumberEdges << "\n";
        std::cout << "Number of Vertices: " << NumberVertices << "\n";

        std::ofstream graph;
        GenerateGraphBegin(graph, NumberVertices, "SeqAsGraph.tex", false);
        for(int i=1;i<=NumberVertices;i++){

            if(CountSumForArray(_SeqToCheck, _arraySize)==0)
                break;
            /*Okreslamy od ktorego wierzcholka rysujemy krawedzie i ich ilosc*/
            int VerticeFrom = i;
            int SizeArrayUseVertTo = _SeqToCheck[VerticeFrom-1];

            int NextVertice = 0;
            int j=i+1;
            while(j<=SizeArrayUseVertTo+i)
            {
                 /*Okreslamy do ktorego wierzcholka rysujemy krawedz*/
                int VerticeTo = j+NextVertice;

                if(!_SeqToCheck[VerticeTo-1] ){NextVertice++;
                    continue;}

                //std::cout << "\\draw[-] ("<< VerticeFrom << ") edge (" << VerticeTo << ");\n";
                graph <<  "\\draw[-] ("<< VerticeFrom << ") edge (" << VerticeTo << ");\n";
                /*Z sekwencji odejmujemy uzyte krawedzie*/ 
                _SeqToCheck[VerticeFrom-1]-=1;
                _SeqToCheck[VerticeTo-1]-=1;
                for(int ix=0;ix<NumberVertices;ix++)
                    std::cout << _SeqToCheck[ix] << ",";
                std::cout << "\n";
                j++;
            }
        }
        GenerateGraphEnd(graph);

}
int CheckSeqAndGenerate::CountSum()
{
    int Sum=0;
    for(int i=0;i<_arraySize;i++)
        Sum += _SeqToCheck[i];
    return Sum;
}
int CheckSeqAndGenerate::CountSumForArray(int *_SeqToCheck, int _arraySize)
{
    int Sum=0;
    for(int i=0;i<_arraySize;i++)
        Sum += _SeqToCheck[i];
    return Sum;
}
