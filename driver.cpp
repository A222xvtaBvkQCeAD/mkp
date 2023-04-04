#include <chrono>
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include "item.h"
#include "knapsack.h"
#include "mkp.h"

const int GENERATIONS = 100;
void gen_file(std::string fname);
void read_file(std::string fname);

int main() {
    char c;
    std::string fname = "data.txt";
    std::cout << "Would you like to read data from an existing file? (y/n)\n";
    std::cin >> c;
    if (c == 'y')
        std::cout << "Reading existing data.txt file\n";
    else {
        std::cout << "Generating new data.txt file\n";
        gen_file(fname);
    }

    MKP myMKP(fname);

    std::cout << myMKP.get_avgFitness() << '\n';
    for (int i = 0; i < GENERATIONS; ++i) {
        myMKP.run();
        std::cout << myMKP.get_avgFitness() << '\n';
    }

    return 0;
}

void gen_file(std::string fname) {
    const int WEIGHT_MIN = 20;
    const int WEIGHT_MAX = 100;
    const int VALUE_MIN = 100;
    const int VALUE_MAX = 1000;
    const int NUM_ITEMS = 50;
    std::default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution weight_dist(WEIGHT_MIN, WEIGHT_MAX);
    std::uniform_int_distribution value_dist(VALUE_MIN, VALUE_MAX);
    std::ofstream file(fname);

    for (int i = 0; i < NUM_ITEMS; ++i) {
        int weight = weight_dist(engine);
        int value = value_dist(engine);

        file << weight << ' ' << value << '\n';
    }
    file.close();
}
