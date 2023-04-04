#ifndef KNAPSACK_H
#define KNAPSACK_H
#include "item.h"

class Knapsack {
public:
    // constructs an empty knapsack with zero value and MAX_CAPACITY capacity
    Knapsack();

    // accessors
    inline int get_capacity() const { return capacity; }
    inline int get_value() const    { return value; }

    // mutators
    inline void set_capacity(const int capacity)  { this->capacity = capacity; }
    inline void set_value(const int value)        { this->value = value; }

    // reduces knapsack's capacity equal to item's weight and increases knapsack's value equal to item's value
    // if an item's weight is greater than the knapsack's capacity, no changes are made
    bool add_item(Item item);

    // sets knapsack's capacity and value equal to those of rhs
    Knapsack& operator=(const Knapsack& rhs);
private:
    const int MAX_CAPACITY = 100;       // maximum weight which any knapsack can contain
    int capacity;                       // remaining weight which a knapsack can contain
    int value;                          // total value contained within a knapsack
};

#endif
