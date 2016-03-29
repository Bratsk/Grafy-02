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
/*Tutaj tak samo jak w poprzednim zestawie tworzy graf i rysuje*/
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
/*Tak samo jak w poprzednim zestawie*/
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
/*Losuje pierwsze 2 wierzcholki do randomizacji i 
sprawdza czy jest rowne 1 (czyli czy sa polaczone)*/
    while(isTruefirst==false){
        i_1 = rand()%_NumberOfVertices;
        j_1 = rand()%_NumberOfVertices;
        /*Sprawdza czy nie wylosowane krawedzie nie sa te same*/
        if(i_1==j_1)
            continue;
        /*Sprawdza czy jest rowne 1 (czyli czy sa polaczone) */
        isTruefirst = Matrix[i_1][j_1];
    }

/*Losuje kolejne 2 wierzcholki do randomizacji i */
    bool isTruesecond = false;
    int counter=0;
    while(isTruesecond==false){
        i_2 = rand()%_NumberOfVertices;
        j_2 = rand()%_NumberOfVertices;
        counter++;
        /*Tutaj mamy zmienna counter na wypadek, gdyby doszlo do nieskonczonej petli. 
        Jesli counter==50, oznacza ze petla jest nieskonczona, czyli nie da sie
        zrandomizowac grafu*/
        if(counter==50){
            std::cout << "Grafu nie da sie zrandomizowac\n";
            std::ofstream graph;
            graph.open("RandomizationGraph.tex", std::ios::app);
            graph << "\\end{document}\n";
            graph.close();
            return;
        }
        /*Sprawdza czy nie wylosowane krawedzie nie sa te same*/
        if(i_2 == j_2)
            continue;
        /*Sprawdza czy ktorys z wylosowanych krawedzi nie jest rowny wczesniej wylosowanemu*/
        if(i_1==i_2 || j_1==j_2 || i_1 == j_2 || i_2 == j_1)
            continue;
        /*Sprawdza czy sposob wylosowych krawedzi nie jest juz polaczony*/
        if(Matrix[i_1][j_2]==1 || Matrix[i_2][j_1]==1 )
            continue;
        /*Sprawdza czy jest rowne 1 (czyli czy sa polaczone) */
        isTruesecond = Matrix[i_2][j_2];
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

