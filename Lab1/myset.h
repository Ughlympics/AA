#pragma once
#include <vector>

class BinarySet {
private:
    std::vector<uint64_t> set;
    size_t size;

public:
    // Constructor
    BinarySet(size_t t);

    // Methods
    void insert(size_t x);
    void remove(size_t x);
    bool contains(size_t x) const;
    void clear();
    void print() const;

    // Static methods for set operations
    static BinarySet intersection(const BinarySet& set1, const BinarySet& set2);
    static BinarySet association(const BinarySet& set1, const BinarySet& set2);
    static BinarySet difference(const BinarySet& set1, const BinarySet& set2);
    static BinarySet symdifference(const BinarySet& set1, const BinarySet& set2);
    static bool issubset(const BinarySet& set1, const BinarySet& set2);
};

