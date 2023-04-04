#include "knapsack.h"

Knapsack::Knapsack() {
    set_capacity(MAX_CAPACITY);
    set_value(0);
}

bool Knapsack::add_item(Item item) {
    // if item's weight does not exceed knapsack's capacity, add it to knapsack
    if (item.get_weight() <= get_capacity()) {
        set_capacity(get_capacity() - item.get_weight());
        set_value(get_value() + item.get_value());
        return true;
    }
    else
        return false;
}

Knapsack& Knapsack::operator=(const Knapsack& rhs) {
    capacity = rhs.capacity;
    value = rhs.value;
    
    return *this;
}
