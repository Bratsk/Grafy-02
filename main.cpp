#include "main.h"

int main(int argc, char ** argv)
{
    srand(time(0));
	std::cout << "Choose an action:" << std::endl;
	Graph * graph = 0;
//	Generator new_generator;
	unsigned option;
	do
	{
		std::cout
			<< "1	: Check if sequence is graph \n"
			<< "2	: Degree Preserving Randomization\n"
			<< "3	: Looking for the strongest connected component\n"
			<< "4	: Generate random Eulerian graph and find Eulerian cycle\n"
			<< "5	: Generate random k-regular graph\n"
			<< "6	: Check if graph is a hamiltonian graph\n"
			<< "0	: end\n" << std::endl;
		std::cin >> option;
		switch(option)
		{
			case 1:{

                    int NSize = 4;
                    int Tab[4] = {1, 2, 2, 3};
                    CheckSeqAndGenerate *SeqToCheck = new CheckSeqAndGenerate(Tab, NSize);
                    bool isGraph = SeqToCheck->CheckSeq();
                    SeqToCheck->GenerateGraph(isGraph);
                    delete SeqToCheck;
                    break;
                    }
			case 2: {
                    std::cout << "Najpierw wygenerujemy graf\n";
                    GraphRandomization *graph = new GraphRandomization();
                    graph->MakeAndGenerate();
                    graph->Randomize();
                    delete graph;
                    break;
			}
			case 3: /** converting to adjacency list*/
                    break;
            case 4: /** converting to incidence matrix*/
                    break;
			case 5:
                    break;
			case 6:
                    break;
			default: option = 0; break;
		}
		std::cout << std::endl;
	}while(option);
	delete graph;
	return 0;
}

