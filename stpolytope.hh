/**
 *  This code is implemented by Jongho Kim.
 */

#ifndef __STPOLYTOPE__
#define __STPOLYTOPE__

#include <iostream>
#include <ilcplex/ilocplex.h>


/** A spanning tree polytope LP problem */
class STPolytope {
 
    /** A basic feasible solution (of subproblem) */
    class BFSol {
        public:
            BFSol(IloEnv& env, unsigned int *_index);
            unsigned int n;
            IloNumArray sol;
            unsigned int *index;
    };

    class Edge {
        public:
            Edge() {}
            unsigned int vertex1;
            unsigned int vertex2;
            float weight;
    };

    public:
        STPolytope(IloEnv& env, std::istream& instream);
        void print(std::ostream& outstream = std::cout) const;
        IloCplex& masterIteration(IloModel& model);

        IloModel firstSubproblem(IloEnv env) const;
        IloCplex& solve(IloModel& model, BFSol& startpt);
        BFSol& solve_subproblem(BFSol& bfsol);
        unsigned int num_vertex;
        unsigned int num_edge;
        Edge *edge;

        /** RHS of constraint */
        IloRangeArray xstar;
};


#endif // __STPOLYTOPE__
