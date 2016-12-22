/**
 *  This code is implemented by Jongho Kim.
 */

#include <iostream>
#include <ilcplex/ilocplex.h>
#include "stpolytope.hh"

ILOSTLBEGIN

int main (int argc, char **argv)
{
    IloEnv env;
    std::ifstream infile("input.txt");
    STPolytope given_problem(env, infile);
    given_problem.print();

    IloCplex solution(given_problem.firstSubproblem(env));
    solution.exportModel("first_subproblem.lp");
    solution.solve();

    STPolytope::printSol(env, given_problem.tableau, solution);
    
    return 0;
}
