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

    std::cout << solution.solve();
    
    return 0;
}
