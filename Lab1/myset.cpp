#include "myset.h"
#include <iostream>
#include <algorithm>  // для std::min и std::max

// Constructor
BinarySet::BinarySet(size_t t) : size(t) {
    size_t num_elements = (t + 63) / 64;
    set.resize(num_elements, 0);
}

// Method implementations (insert, remove, contains, clear, print, etc.)
void BinarySet::insert(size_t x) {
    size_t block = x / 64;
    size_t pos = x % 64;
    set[block] |= (1ULL << pos);
}

void BinarySet::remove(size_t x) {
    size_t block = x / 64;
    size_t pos = x % 64;
    set[block] &= ~(1ULL << pos);
}

bool BinarySet::contains(size_t x) const {
    size_t block = x / 64;
    size_t pos = x % 64;
    return set[block] & (1ULL << pos);
}

void BinarySet::clear() {
    for (auto& block : set) {
        block = 0;
    }
}

void BinarySet::print() const {
    for (size_t i = 0; i < size; ++i) {
        if (contains(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

// Static method implementations
BinarySet BinarySet::intersection(const BinarySet& set1, const BinarySet& set2) {
    size_t new_size = std::min(set1.size, set2.size);
    BinarySet result(new_size);
    for (size_t i = 0; i < result.set.size(); ++i) {
        result.set[i] = set1.set[i] & set2.set[i];
    }
    return result;
}

BinarySet BinarySet::association(const BinarySet& set1, const BinarySet& set2) {
    size_t new_size = std::max(set1.size, set2.size);
    BinarySet result(new_size);
    size_t min_size = std::min(set1.set.size(), set2.set.size());
    for (size_t i = 0; i < min_size; ++i) {
        result.set[i] = set1.set[i] | set2.set[i];
    }
    for (size_t i = min_size; i < set1.set.size(); ++i) {
        result.set[i] = set1.set[i];
    }
    for (size_t i = min_size; i < set2.set.size(); ++i) {
        result.set[i] = set2.set[i];
    }
    return result;
}

BinarySet BinarySet::difference(const BinarySet& set1, const BinarySet& set2) {
    size_t new_size = set1.size;
    BinarySet result(new_size);
    size_t min_size = std::min(set1.set.size(), set2.set.size());
    for (size_t i = 0; i < min_size; ++i) {
        result.set[i] = set1.set[i] & ~set2.set[i];
    }
    for (size_t i = min_size; i < set1.set.size(); ++i) {
        result.set[i] = set1.set[i];
    }
    return result;
}

BinarySet BinarySet::symdifference(const BinarySet& set1, const BinarySet& set2) {
    size_t new_size = std::max(set1.size, set2.size);
    BinarySet result(new_size);
    size_t min_size = std::min(set1.set.size(), set2.set.size());
    for (size_t i = 0; i < min_size; ++i) {
        result.set[i] = set1.set[i] ^ set2.set[i];
    }
    for (size_t i = min_size; i < set1.set.size(); ++i) {
        result.set[i] = set1.set[i];
    }
    for (size_t i = min_size; i < set2.set.size(); ++i) {
        result.set[i] = set2.set[i];
    }
    return result;
}

bool BinarySet::issubset(const BinarySet& set1, const BinarySet& set2) {
    for (size_t i = 0; i < set1.set.size(); ++i) {
        if ((set1.set[i] & set2.set[i]) != set1.set[i]) {
            return false;
        }
    }
    return true;
}