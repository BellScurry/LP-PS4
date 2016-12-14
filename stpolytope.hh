/**
 *  This code is implemented by Jongho Kim.
 */

#ifndef __STPOLYTOPE__
#define __STPOLYTOPE__

#include <iostream>
#include <ilcplex/ilocplex.h>

class Wgraph {

    class Edge {
        public:
            Edge() {}
            unsigned int vertex1;
            unsigned int vertex2;
            float weight;
    };

    public:
        Wgraph(std::istream& instream);
        unsigned int num_vertex;
        unsigned int num_edge;
        Edge *edge;
        void print(std::ostream& outstream = std::cout) const;
};


/** Solving spanning tree polytope LP using delayed column method */
IloCplex& solve_stpolytope(IloEnv& env);

#endif // __STPOLYTOPE__
