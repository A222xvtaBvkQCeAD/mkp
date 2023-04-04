#ifndef MKP_H
#define MKP_H
#include "chromosome.h"

class MKP {
public:
    // constructs an MKP with a population of randomly encoded chromosomes
    MKP();
    MKP(std::string fname);

    // read items from file named fname into array of items
    void read_items(std::string fname, Item itemArray[]);

    // accessors
    inline int get_avgFitness() const { return avgFitness; }

    // calculates average fitness of all Chromosomes in population
    void calc_avgFitness();

    // run one generation of the algorithm
    void run();
private:
    static const int POPULATION = 100;      // population size (number of solutions per generation)
    double avgFitness;                      // average fitness of Chromosome population
    Chromosome population[POPULATION];      // current population of Chromosomes
    Item itemArray[Chromosome::LENGTH];     // array of items to run MKP on

    // compares TOURNAMENT_SIZE + 1 chromosomes from current population and returns the chromosome with the highest fitness
    Chromosome select() const;

    // returns a Chromosome created by combining the first crossPt elements of parent1's encoding with the remaining elements of parent2's encoding
    Chromosome recombine(const Chromosome& parent1, const Chromosome& parent2, int crossPt) const;

    // iterates over chromosome's encoding with a MUTATION_RATE chance of randomizing the value at the current position
    void mutate(Chromosome& chromosome);
};
#endif
