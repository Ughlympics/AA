#include "myset.h"
#include <iostream>
#include <vector>



    // Function for intersection of two sets
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;


BinarySet generateRandomSet(size_t size, size_t range) {
    BinarySet newSet(range);  
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, range - 1);

    for (size_t i = 0; i < size; ++i) {
        newSet.insert(dist(gen));  
    }

    return newSet;
}

void testSearchPerformance(size_t setSize, size_t range) {
    BinarySet testSet = generateRandomSet(setSize, range);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, range - 1);
    size_t searchElement = dist(gen);

    auto start = high_resolution_clock::now();
    bool found = testSet.contains(searchElement); 
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start).count();

    
    cout << "Set size: " << setSize << endl;
    cout << "Element to search: " << searchElement << endl;
    cout << "Search result: " << (found ? ":)" : ":(") << endl;
    cout << "Search time: " << duration << " nanosec" << endl;
    cout << "-------------------------------" << endl;
}
void testUnionPerformance(size_t setSize1, size_t setSize2, size_t range) {

    BinarySet set1 = generateRandomSet(setSize1, range);
    BinarySet set2 = generateRandomSet(setSize2, range);

    auto start = high_resolution_clock::now();
    BinarySet unionSet = BinarySet::association(set1, set2);  
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start).count();

    cout << "Size of set1: " << setSize1 << endl;
    cout << "Size of set2: " << setSize2 << endl;
    cout << "Time of union complite: " << duration << " nanosec" << endl;
    cout << "-------------------------------" << endl;
}
    

    int main() {
        testSearchPerformance(100, 1000);    
        testSearchPerformance(1000, 10000); 
        testSearchPerformance(10000, 100000);  
        testUnionPerformance(100, 100, 1000);    
        testUnionPerformance(1000, 1000, 10000);  
        testUnionPerformance(10000, 10000, 100000);
        //size_t t = 10000;  // Example set size 1000
        //BinarySet set1(t);
        //BinarySet set2(t);
        //BinarySet set3(t);

        //// Insert some elements into the first set
        //set1.insert(3);
        //set1.insert(64);
        //set1.insert(128);
        //set1.insert(999);

        //// Insert some elements into the second set
        //set2.insert(64);
        //set2.insert(128);
        //set2.insert(500);
        //set2.insert(999);

        //set3.insert(3);
        //set3.insert(64);
        //set3.insert(128);
        //set3.insert(999);
        //set3.insert(99);

        //// Print elements of both sets
        //std::cout << "Elements of the first set: ";
        //set1.print();
        //std::cout << "Elements of the second set: ";
        //set2.print();

        //// Perform set intersection
        //BinarySet resultSetIntersection = BinarySet::intersection(set1, set2);
        //std::cout << "Intersection of the sets: ";
        //resultSetIntersection.print();

        //// Perform set association (union)
        //BinarySet resultSetAssociation = BinarySet::association(set1, set2);
        //std::cout << "Association (union) of the sets: ";
        //resultSetAssociation.print();

        //// Perform set difference (set1 - set2)
        //BinarySet resultSetDifference = BinarySet::difference(set1, set2);
        //std::cout << "Difference (set1 - set2) of the sets: ";
        //resultSetDifference.print();

        //BinarySet resultSetSymDifference = BinarySet::symdifference(set1, set2);
        //std::cout << "SymDifference (set1 - set2) of the sets: ";
        //resultSetSymDifference.print();


        //bool isSubset = BinarySet::issubset(set1, set2);
        //if (isSubset) {
        //    std::cout << "Set1 is a subset of Set2" << std::endl;
        //}
        //else {
        //    std::cout << "Set1 is not a subset of Set2" << std::endl;
        //}

        //bool isSubset2 = BinarySet::issubset(set1, set3);
        //if (isSubset2) {
        //    std::cout << "Set1 is a subset of Set3" << std::endl;
        //}
        //else {
        //    std::cout << "Set1 is not a subset of Set3" << std::endl;
        //}


        return 0;
    }