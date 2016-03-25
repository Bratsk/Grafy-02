#include "Graph.h"

float Graph::Degree_Begin = 0;
const float Graph::rad = M_PI/180;
Graph::Graph(){

}
void Graph::GenerateGraphBegin(std::ofstream &graph, int NumberOfVertices, std::string NameOfFile, bool OverRead)
{
    if(OverRead==false){
        graph.open(NameOfFile.c_str());
                graph << "\\documentclass{article}\n" \
            "\\usepackage{tikz}\n" \
            "\\usetikzlibrary{arrows}\n" \
            "\\begin{document}\n";
    }
    else{
        graph.open(NameOfFile.c_str(), std::ios::app);}

        graph << "\\begin{tikzpicture}[every path/.style={>=latex},\
            every node/.style={draw,circle}]\n";
        float *x = new float[NumberOfVertices];
        float *y = new float[NumberOfVertices];
        const float Degree = 180 - (180 * (NumberOfVertices-2))/NumberOfVertices;

        CountPoints(x,y,NumberOfVertices,Degree);

        for(int i=0;i<NumberOfVertices;i++)
        {
            graph << "\\node ("<< i+1 <<") \
            at (" << x[i] << "," << y[i] <<")  { "<< i+1 <<" };\n";
        }
        delete []x;
        delete []y;

}
void Graph::GenerateGraphEnd(std::ofstream &graph)
{
    graph << "\\end{tikzpicture}\n";
        graph << "\\end{document}\n";
        graph.close();
}
void Graph::CountPoints(float *x, float *y, int n, float Degree)
{
    for(int i=0;i<n;i++)
    {
        x[i] = 3 * cos( Degree_Begin * rad);
        y[i] = 3 * sin( Degree_Begin * rad);
        Degree_Begin+=Degree;
    }
   /* for(int i=0;i <n;i++)
        std::cout << x[i] << " " << y[i] << std::endl;*/
}

bool Graph::IsInTab(int Value, int *Tab, int NSize)
{
    bool is = false;
    for(int ix=0;ix<NSize;ix++)
        if(Value==Tab[ix]){
            is = true;
            break;
        }

    return is;
}

int cmp( int * arg1, int * arg2 )
{
    if( * arg1 <* arg2 )
         return 1;

    if( * arg1 >* arg2 )
         return -1;

    return 0;
}
