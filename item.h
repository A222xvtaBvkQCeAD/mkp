#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    // accessors
    inline int get_weight() const   { return weight; }
    inline int get_value() const    { return value; }
    inline int get_ratio() const    { return ratio; }

    // mutators
    inline void set_weight(const int weight)  { this->weight = weight; }
    inline void set_value(const int value)    { this->value = value; }
    inline void set_ratio()                   { ratio = value / weight; }

    // lhs is less than rhs if the ratio of lhs is less than the ratio of rhs
    inline friend bool operator<(const Item& lhs, const Item& rhs) { return lhs.get_ratio() < rhs.get_ratio(); }
private:
    int weight;         // amount by which an item reduces a knapsack's capacity
    int value;          // amount by which an item contributes to a knapsack's value
    double ratio;       // value-to-weight ratio
};

#endif
