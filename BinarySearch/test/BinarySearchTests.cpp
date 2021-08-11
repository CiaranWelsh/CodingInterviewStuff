//
// Created by Ciaran on 11/08/2021.
//
#include "gtest/gtest.h"
#include "BinarySearch.h"

class BinarySearchTests : public ::testing::Test {

public:

    BinarySearchTests() = default;
};


using SortableIntVector = Sortable<std::vector<int>>;
/**
 * We first need something to sort
 * So implement a Sortable
 */
class IntVector : public Sortable<std::vector<int>> {
public:
    using SortableType = std::vector<int> ;

    using value_type = SortableIntVector::TheContainerType::value_type;

    explicit IntVector(std::vector<int> container)
        : SortableIntVector(std::move(container)) {};

    bool operator==(const SortableIntVector &rhs) {
        return container_ == rhs.container_;
    }

    bool operator!=(const SortableIntVector &rhs) {
        return container_ != rhs.container_;
    }

    bool operator>(const SortableIntVector &rhs) {
        return container_ > rhs.container_;
    }

    bool operator<(const SortableIntVector &rhs) {
        return container_ < rhs.container_;
    }

    bool operator>=(const SortableIntVector &rhs) {
        return container_ >= rhs.container_;
    }

    bool operator<=(const SortableIntVector &rhs) {
        return container_ <= rhs.container_;
    }

    ItemType operator[](int index){
        return container_[index];
    }

    int size() {
        return (int)container_.size();
    }

//    int find(ItemType itemType){
//        BinarySearch<IntVector> binarySearch(this);
//    }

    TheContainerType::iterator begin() noexcept{
        return container_.begin();
    }


    TheContainerType::iterator end() noexcept{
        return container_.end();
    }
};

TEST_F(BinarySearchTests, end) {
    IntVector v({1, 2, 3,4, 5, 6, 7});
    BinarySearch<IntVector> binarySearch(v);
    ASSERT_EQ(binarySearch.find(7), 6);

}

TEST_F(BinarySearchTests, t) {
    IntVector v({1, 2, 3,4, 5, 6, 7});
    BinarySearch<IntVector> binarySearch(v);
    ASSERT_EQ(binarySearch.find(6), 5);

}














