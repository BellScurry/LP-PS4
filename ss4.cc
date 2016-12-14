/**
 *  This code is implemented by Jongho Kim.
 */

#include <iostream>
#include <ilcplex/ilocplex.h>
#include "stpolytope.hh"

int main (int argc, char **argv)
{
    IloEnv env;
    IloModel model(env);
    IloCplex cplex(model);
    std::ifstream infile("input.txt");
    Wgraph givenwgraph(infile);
    givenwgraph.print();

    return 0;
}
