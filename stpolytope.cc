#include "stpolytope.hh"

 
/** 
 *  1. Read graph structure and value of edges from input stream
 *  2. Generate and store xstar (RHS of constraint) 
 */
STPolytope::STPolytope(IloEnv& env, std::istream& instream) {

    instream >> num_vertex >> num_edge;
    edge = new Edge[num_edge];

    xstar = *new IloRangeArray(env);
    char suffix[5];
    for(int j=0; j < num_edge; j++) {
        char rowname[10] = "row";
        sprintf(suffix, "%d", j+1);
        strcat(rowname, suffix);
        instream >> edge[j].vertex1 >> edge[j].vertex2 >> edge[j].weight;
        xstar.add(IloRange(env, edge[j].weight, edge[j].weight, rowname));
    }
}

void STPolytope::print(std::ostream& outstream) const {

    outstream   << "Graph Info" << std::endl
                << "\tN(vertex) =\t" << num_vertex << std::endl
                << "\tN(edge) =\t" << num_edge << std::endl;

    outstream   << "v1\tv2\tweight" << std::endl
                << "----------------------" << std::endl;
    for(int j=0; j < num_edge; j++) {
        outstream   << edge[j].vertex1 << "\t"
                    << edge[j].vertex2 << "\t"
                    << edge[j].weight << std::endl;
    }
}

/**
 *  This method returns the first subproblem in delayed column generation
 *  method. All slack variables (y) will be zero, so corresponding columns
 *  will not join. Only the decision variables (s) will join.
 */
IloModel STPolytope::firstSubproblem(IloEnv env) const {

    IloModel model(env);
    IloNumVarArray s(env);          // Decision Variables

    IloObjective obj = IloMinimize(env);
  
    for(int j=0; j < num_edge; j++) {
        IloNumColumn col = obj(1.0);
        for(int k=0; k < num_edge; k++) {
            if(j!=k)
                col += xstar[k](0);
            else
                col += xstar[k](1.0);
        }
        s.add(IloNumVar(col));
        char varname[10] = "s";
        char suffix[5];
        sprintf(suffix, "%d", j+1);
        strcat(varname, suffix);
        s[j].setName(varname);
    }

    model.add(obj);
    model.add(xstar);

    return model;
}

/** Solve an LP with starting point */
/*
IloCplex& STPolytope::solve(IloModel& model, BFSol& startpt) {

    //IloEnv env = model.getEnv();
    //IloCplex cplex(model);

    //
    cplex.setVectors(x, 0, var, 0, 0, 0);
}
*/

STPolytope::BFSol::BFSol(IloEnv& env, unsigned int *_index) {

    memcpy(index, _index, sizeof(_index));
}
