//
// Created by Ciaran on 11/08/2021.
//

#ifndef CODINGINTERVIEWSTUFF_BINARYSEARCH_H
#define CODINGINTERVIEWSTUFF_BINARYSEARCH_H

#include <algorithm>

/**
 * @brief interface for containers that are sortable.
 * @details Containers that implement this interface
 * can be sorted.
 */
template<typename ContainerType>
class Sortable {
public:

    using ItemType = typename ContainerType::value_type;
    using TheContainerType = ContainerType;

    Sortable(ContainerType containerType) : container_(containerType) {};

    virtual bool operator==(const Sortable &rhs) = 0;

    virtual bool operator!=(const Sortable &rhs) = 0;

    virtual bool operator>(const Sortable &rhs) = 0;

    virtual bool operator<(const Sortable &rhs) = 0;

    virtual bool operator>=(const Sortable &rhs) = 0;

    virtual bool operator<=(const Sortable &rhs) = 0;

    virtual int size() = 0;

//    virtual ContainerType::iterator begin() noexcept = 0;
//
//    virtual ContainerType::iterator end() noexcept = 0;

    virtual ItemType operator[](int index) = 0;

    /**
     * @brief sort the container inplace.
     */
//    virtual void sort() = 0;

public:
    ContainerType container_;
};


/**
 * It is not necessarily the case that all Searchable algorithms require sorted containers.
 * Therefore, Searchable cannot inherit from Sortable - each algorithm much independently choose its interfaces.
 */

template<typename ContainerType>
class SearchAlgorithm {
public:
    using ItemType = typename ContainerType::value_type;
    using ContainerType_ = ContainerType;

    explicit SearchAlgorithm(ContainerType container)
            : container_(container) {}

    /**
     * @brief find the index of the item
     */
    virtual int find(const ItemType &item) = 0;

protected:

    ContainerType container_;

};

/**
 * @brief
 *
 * @details Complexity O(log2 n) in the worst case. This is because each time you
 * iterate you half the number of items that need to be searched.
 *
 * @notes This will need to be templated. Accepts only containers that can be sorted.
 * Therefore it will accept containers that implement comparison operators (==, !=, >, <, =>, =<)
 * Perhaps an interface "Sortable" would be helpful here.
 *
 * @notes it may also be useful to have a Searchable interface.
 */
template<typename ContainerType>
class BinarySearch : public SearchAlgorithm<ContainerType> {
public:
    using ItemType = typename ContainerType::value_type;

    explicit BinarySearch(ContainerType container)
            : SearchAlgorithm<ContainerType>(container) {}

    int find(const ItemType &item) override {
        return find(item, 0, this->container_.size()-1);
    }

    int find(const ItemType &item, int start, int end)  {
        // first ensure the container is sorted.
        std::sort(this->container_.begin(), this->container_.end());

        // find mid point.
        int midpointOfRange = -1;
        int range = end - start;
        if (range % 2 == 0) {
            // even
            midpointOfRange = start + (range / 2);
        } else {
            midpointOfRange = start + ((range + 1) / 2);
        }

        // check whether we have guessed correctly
        ItemType itemAtMidpoint = this->container_[midpointOfRange];
        if (itemAtMidpoint == item) {
            return midpointOfRange;
        } else {
            // when ItemType > itemAtMidpoint
            if (item > itemAtMidpoint){
                // call find recursively with range (midpointOfRange - end]
                return find(item, midpointOfRange, this->container_.size());
            } else {
                // call find recursively with range (0 - midpointOfRange]
                return find(item, 0, midpointOfRange);
            }
        }
        throw std::logic_error("This algorithm should never reach here!");
    }

};


#endif //CODINGINTERVIEWSTUFF_BINARYSEARCH_H
