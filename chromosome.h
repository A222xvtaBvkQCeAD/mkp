#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <string>
#include "knapsack.h"

class Chromosome {
    friend class MKP;
public:
    // construct a chromosome with a random encoding
    Chromosome();
    // construct a chromosome with a given encoding
    Chromosome(const int encoding[]);
    // construct a chromosome from an array of Items with a random encoding
    Chromosome(Item itemArray[]);
    // construct a chromosome from an array of Items with a given encoding
    Chromosome(const int encoding[], Item itemArray[]);
    // copy constructor
    Chromosome(const Chromosome& chromosome);

    // accessors
    inline int get_fitness() const { return fitness; }
    std::string get_encoding() const;

    // mutators
    void set_encoding(const int encoding[]);
    void set_fitness();

    // generate random encoding
    void gen_encoding();

    // add an array of items to the set of knapsacks according to encoding
    void add_items(Item items[]);

    Chromosome& operator=(const Chromosome& chromosome);
    // returns true if lhs and rhs have the same encoding
    friend bool operator==(const Chromosome& lhs, const Chromosome& rhs);
private:
    static const int LENGTH = 50;       // genotype length (number of items per solution)
    static const int NUM_KNAPS = 5;     // number of knapsacks
    int fitness;                        // total value stored in knapsacks
    int encoding[LENGTH];               // encoded representation
    Knapsack knaps[NUM_KNAPS];          // set of knapsacks
};

#endif
