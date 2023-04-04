#include <chrono>
#include <fstream>
#include <random>
#include <string>
#include "chromosome.h"
#include "item.h"
#include "knapsack.h"
#include "mkp.h"

MKP::MKP() {
    for (int i = 0; i < POPULATION; ++i)
        population[i] = Chromosome();
}

MKP::MKP(std::string fname) {
    read_items(fname, itemArray);
    for (int i = 0; i < POPULATION; ++i)
        population[i] = Chromosome(itemArray);
    calc_avgFitness();
}

void MKP::read_items(std::string fname, Item itemArray[]) {
    int weight, value;
    int i = 0;
    std::ifstream file(fname);

    while (file >> weight >> value) {
        itemArray[i].set_weight(weight);
        itemArray[i].set_value(value);
        ++i;
    }
    file.close();
}

void MKP::calc_avgFitness() {
    avgFitness = 0;
    for (int i = 0; i < POPULATION; ++i)
        avgFitness += population[i].get_fitness();
    avgFitness /= (double)POPULATION;
}

Chromosome MKP::select() const {
    const int TOURNAMENT_SIZE = 10;     // tournament size (number of solutions compared in selection)
    std::default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution dist(0, POPULATION - 1);
    int index = dist(engine);     // index into current population array
    int maxFitness = population[index].get_fitness();
    int maxIndex = index;

    for (int i = 0; i < TOURNAMENT_SIZE; ++i) {
        index = dist(engine);
        if (population[index].get_fitness() > maxFitness) {
            maxFitness = population[index].get_fitness();
            maxIndex = index;
        }
    }

    return population[maxIndex];
}

Chromosome MKP::recombine(const Chromosome& parent1, const Chromosome& parent2, int crossPt) const {
    int encoding[Chromosome::LENGTH];

    for (int i = 0; i < crossPt; ++i)
        encoding[i] = parent1.encoding[i];
    for (int i = crossPt; i < Chromosome::LENGTH; ++i)
        encoding[i] = parent2.encoding[i];

    Chromosome child = Chromosome(encoding);

    return child;
}

void MKP::mutate(Chromosome& chromosome) {
    const double MUTATION_RATE = 0.05;       // probability that mutation occurs at any Chromosome encoding position
    std::default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution distInt(0, Chromosome::NUM_KNAPS - 1);
    std::uniform_real_distribution distReal(0.0, 1.0);

    for (int i = 0; i < Chromosome::LENGTH; ++i) {
        double mutate = distReal(engine);
        if (mutate < MUTATION_RATE) {
            int encoding = distInt(engine);
            chromosome.encoding[i] = encoding;
        }
    }
    chromosome = Chromosome(chromosome.encoding, itemArray);
}

void MKP::run() {
    Chromosome population[POPULATION];      // next generation of Chromosomes
    std::default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution dist(1, Chromosome::LENGTH - 2);  // guarantees that at least one element from parent1 and parent2 is included
    int crossPt = dist(engine);

    for (int i = 0; i < POPULATION; i+=2) {
        Chromosome parent1 = select();
        Chromosome parent2 = select();
        Chromosome child1 = recombine(parent1, parent2, crossPt);
        Chromosome child2 = recombine(parent2, parent1, crossPt);
        mutate(child1);
        mutate(child2);
        population[i] = child1;
        if (i + 1 < POPULATION)
            population[i + 1] = child2;
    }
    for (int i = 0; i < POPULATION; ++i)
        this->population[i] = population[i];
    calc_avgFitness();
}
