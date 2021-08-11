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





/*
 * What I've learnt from implementing BinarySearch
 * ---------------------------------------------------------------
 * - Firstly, I've found that I immediately tried to generalize the algorithm to all search and sortable
 *   algorithms. This takes a bit more effort and I ran into trouble. It would have been better to start out
 *   implementing the business logic of the BinarySearch algorithm itself, and only once it works
 *   on (say) a vector of ints, work on generalizing to other types. This way, I can use my passing tests as a guide when generalizing. This process I think would be more efficient.
 * - Moreover, by jumping the gun and trying to pre-empt the framework needed for the algorithm, I've
 *   inadvertedly implemented something that isn't required - the Sortable interface.
 *   Since the binary search algorithm only works on sorted containers, and we are looking for the index of
 *   the item in the container passed in, it is necessary for the user to sort the container proir to input
 *   into Binary Search. therefore, the container does not need to be sortable in order for binary search to
 *   work. It does however need to be sortable, but this shouldd be done outside the scope of BinarySearch.
 */








