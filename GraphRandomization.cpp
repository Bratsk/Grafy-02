#include "GraphRandomization.h"

GraphRandomization::GraphRandomization(): Graph()
{

}
GraphRandomization::~GraphRandomization()
{
    for(int i=0;i<_NumberOfVertices;i++)
        delete [] Matrix[i];
    delete [] Matrix;
}
void GraphRandomization::MakeAndGenerate()
{
    int n, l;
    std::cout << "Podaj liczbe wierzcholkow\n";
    std::cin >> n;
    std::cout << "Podaj liczbe krawedzi\n";
    std::cin >> l;
    std::cout << "\n";
    _NumberOfVertices = n;
    _NumberOfEdges = l;
    srand(time(0));
    Matrix = new bool* [n];
    for(int i = 0; i < n; ++i)
        Matrix[i] = new bool[n];

    GenerateAsMatrixNL();
    std::ofstream graph;
    GenerateGraphBegin(graph, _NumberOfVertices, "RandomizationGraph.tex", false);
    for(int i=0;i <n;i++)
        for(int j=i; j<n;j++)
            if(Matrix[i][j]==1)
                graph <<  "\\draw[-] ("<< i+1 << ") edge (" << j+1 << ");\n";
    graph << "\\end{tikzpicture}\n";
    graph.close();
    //GenerateGraphEnd(graph);
}
void GraphRandomization::GenerateAsMatrixNL()
{
     int edge = _NumberOfEdges;

    for(int i=0;i <_NumberOfVertices;i++)
        for(int j=0;j<_NumberOfVertices;j++)
            Matrix[i][j] = 0;

    while(edge>0)
    {
        int i = rand()%(_NumberOfVertices-1);
        int j = (rand()%(_NumberOfVertices-i-1))+(i+1);
        //std::cout << i << ", " << j << "\n";
        if(Matrix[i][j]==0){
            Matrix[i][j] = 1;
            Matrix[j][i] = 1;
            edge--;
            //std::cout << edge << "\n";
        }
    }

    std::cout << "Graf jako macierz przed randomizacja\n";
    for(int i=0;i <_NumberOfVertices;i++){
        for(int j=0;j<_NumberOfVertices;j++){
            std::cout << Matrix[i][j] << " ";}
        std::cout << std::endl;}
}

void GraphRandomization::Randomize()
{
    int i_1, j_1, i_2, j_2;
    bool isTruefirst=false;
    while(isTruefirst==false){
        i_1 = rand()%_NumberOfVertices;
        j_1 = rand()%_NumberOfVertices;
        if(i_1==j_1)
            continue;
        isTruefirst = Matrix[i_1][j_1];
    }

    //int counter = 8;|| counter>0
    bool isTruesecond = false;
    while(isTruesecond==false){
        i_2 = rand()%_NumberOfVertices;
        j_2 = rand()%_NumberOfVertices;
        //std::cout << isTruesecond << " ";
        if(i_2 == j_2){//std::cout << "tu?\n";
            continue;}
        if(i_1==i_2 || j_1==j_2 || i_1 == j_2 || i_2 == j_1){//std::cout << "czy tu?\n";
            continue;}
        if(Matrix[i_1][j_2]==1 || Matrix[i_2][j_1]==1 ){//std::cout << "czy moze tu?\n";
            continue;}
        isTruesecond = Matrix[i_2][j_2];
       // counter--;
    }
    std::cout << "\n(" << i_1+1 << "," << j_1+1 << ") i ";
    std::cout << "(" << i_2+1 << "," << j_2+1 << ")\n\n";
    Matrix[i_1][j_1] = Matrix[j_1][i_1] = 0;
    Matrix[i_1][j_2] = Matrix[j_2][i_1] = 1;
    Matrix[i_2][j_2] = Matrix[j_2][i_2] = 0;
    Matrix[i_2][j_1] = Matrix[j_1][i_2] = 1;

    std::cout << "Graf jako macierz po randomizacji\n";
   for(int i=0;i <_NumberOfVertices;i++){
        for(int j=0;j<_NumberOfVertices;j++){
            std::cout << Matrix[i][j] << " ";}
        std::cout << std::endl;}


     std::ofstream graph;
    GenerateGraphBegin(graph, _NumberOfVertices, "RandomizationGraph.tex", true);
    for(int i=0;i <_NumberOfVertices;i++)
        for(int j=i; j<_NumberOfVertices;j++)
            if(Matrix[i][j]==1){
              graph <<  "\\draw[-] ("<< i+1 << ") edge (" << j+1 << ");\n";}
    GenerateGraphEnd(graph);
}

