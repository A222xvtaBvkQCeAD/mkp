#include "chromosome.h"
#include <chrono>
#include <random>
#include <string>

#include <iostream>

Chromosome::Chromosome() {
    fitness = -1;
    gen_encoding();
}

Chromosome::Chromosome(const int encoding[]) {
    fitness = -1;
    set_encoding(encoding);
}

Chromosome::Chromosome(Item items[]) {
    fitness = -1;
    gen_encoding();
    add_items(items);
}

Chromosome::Chromosome(const int encoding[], Item items[]) {
    fitness = -1;
    set_encoding(encoding);
    add_items(items);
}

Chromosome::Chromosome(const Chromosome& chromosome) {
    fitness = chromosome.fitness;
    for (int i = 0; i < LENGTH; ++i)
        encoding[i] = chromosome.encoding[i];
    for (int i = 0; i < NUM_KNAPS; ++i)
        knaps[i] = chromosome.knaps[i];
    set_fitness();
}

std::string Chromosome::get_encoding() const {
    std::string encoding = "";
    for (int i = 0; i < LENGTH; ++i) {
        encoding.append(std::to_string(this->encoding[i]));
    }
    return encoding;
}

void Chromosome::set_fitness() {
    fitness = 0;
    for (int i = 0; i < NUM_KNAPS; ++i)
        fitness += knaps[i].get_value();
}

void Chromosome::set_encoding(const int encoding[LENGTH]) {
    for (int i = 0; i < LENGTH; ++i)
        this->encoding[i] = encoding[i];
}

void Chromosome::gen_encoding() {
    std::default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution dist(0, NUM_KNAPS);
    for (int i = 0; i < LENGTH; ++i)
        encoding[i] = dist(engine);
}

void Chromosome::add_items(Item items[]) {
    for (int i = 0; i < LENGTH; ++i)
        if (encoding[i] > 0)
            knaps[encoding[i] - 1].add_item(items[i]);
    set_fitness();
}

Chromosome& Chromosome::operator=(const Chromosome& chromosome) {
    for (int i = 0; i < LENGTH; ++i)
        encoding[i] = chromosome.encoding[i];
    for (int i = 0; i < NUM_KNAPS; ++i)
        knaps[i] = chromosome.knaps[i];
    fitness = chromosome.fitness;

    return *this;
}

bool operator==(const Chromosome& lhs, const Chromosome& rhs) {
    return lhs.get_encoding() == rhs.get_encoding();
}
