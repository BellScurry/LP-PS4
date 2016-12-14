#include "stpolytope.hh"

Wgraph::Wgraph(std::istream& instream) {

    instream >> num_vertex >> num_edge;
    edge = new Edge[num_edge];
    for(int j=0; j < num_edge; j++)
        instream >> edge[j].vertex1 >> edge[j].vertex2 >> edge[j].weight;
}

void Wgraph::print(std::ostream& outstream) const {

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
