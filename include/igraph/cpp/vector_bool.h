/* vim:set ts=4 sw=4 sts=4 et: */

#ifndef IGRAPHPP_VECTOR_BOOL_H
#define IGRAPHPP_VECTOR_BOOL_H

#include <cstring>
#include <igraph/cpp/error.h>
#include <igraph/cpp/types.h>

namespace igraph {

/// C++-style wrapper around an igraph_vector_bool_t
class VectorBool {
public:
    typedef bool_t& reference;
    typedef bool_t& const_reference;
    typedef bool_t* iterator;
    typedef const bool_t* const_iterator;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef bool_t value_type;
    typedef bool_t* pointer;
    typedef const bool_t* const_pointer;

private:
    /// The igraph_vector_bool_t instance encapsulated by the wrapper
    igraph_vector_bool_t m_vector;

    /// Whether we own the given igraph_vector_bool_t instance or not
    bool m_owner;

public:
    /*****************************/
    /* Constructors, destructors */
    /*****************************/

    /// Constructs a vector
    explicit VectorBool(size_type length = 0, pointer data = 0) : m_owner(true) {
        if (data) {
            IGRAPH_TRY(igraph_vector_bool_init_copy(&m_vector, data, length));
        } else
            IGRAPH_TRY(igraph_vector_bool_init(&m_vector, length));
    }

    /// Constructs a wrapper that wraps the given igraph_vector_bool_t instance
    /**
     * \param  own  specifies whether we own the given \c igraph_vector_bool_t instance
     *              or not. If own is false, the encapsulated \c igraph_vector_bool_t
     *              will not be destroyed when the \c VectorBool wrapper is destroyed.
     */
    VectorBool(igraph_vector_bool_t vector, bool own=true) : m_vector(vector), m_owner(own) {}

    /// Constructs a wrapper that refers to the same vector as the given igraph_vector_bool_t* pointer
    VectorBool(igraph_vector_bool_t* vector, bool own=false) : m_vector(*vector), m_owner(own) {}

    /// Copy constructor
    VectorBool(const VectorBool& other) : m_owner(true) {
        IGRAPH_TRY(igraph_vector_bool_copy(&m_vector, &other.m_vector));
    }

    /// Constructor from STL container
    template <typename InputIterator>
    VectorBool(InputIterator first, InputIterator last) {
        IGRAPH_TRY(igraph_vector_bool_init(&m_vector, 0));
        while (first != last) {
            this->push_back(*first);
            ++first;
        }
    }

    /// Destroys the vector
    ~VectorBool() {
        if (m_owner)
            igraph_vector_bool_destroy(&m_vector);
    }

    /******************/
    /* Static methods */
    /******************/

    /********************/
    /* Instance methods */
    /********************/

    /// Appends another vector to this one
    void append(const VectorBool& from) {
        IGRAPH_TRY(igraph_vector_bool_append(&m_vector, &from.m_vector));
    }

    /// Returns an iterator pointing to the first element of the vector
    iterator begin() {
        return &(VECTOR(m_vector)[0]);
    }

    /// Returns an iterator pointing to the first element of the vector (const)
    const_iterator begin() const {
        return &(VECTOR(m_vector)[0]);
    }

    /// Returns the last element of the vector
    reference back() {
        return VECTOR(m_vector)[size()-1];
    }

    /// Returns the last element of the vector (const variant)
    const_reference back() const {
        return VECTOR(m_vector)[size()-1];
    }

    /// Removes all the elements from the vector
    /**
     * Note that this function sets the length of the vector to zero, but it
     * does not allocate previously used memory -- it is still kept in case
     * the vector has to grow again.
     */
    void clear() {
        igraph_vector_bool_clear(&m_vector);
    }

    /// Returns whether a given element is in the vector, using linear search
    bool contains(value_type e) {
        return igraph_vector_bool_contains(&m_vector, e);
    }

    /// Returns a pointer to the internal igraph_vector_bool_t
    igraph_vector_bool_t* c_vector() {
        return &m_vector;
    }

    /// Returns a const pointer to the internal igraph_vector_bool_t
    const igraph_vector_bool_t* c_vector() const {
        return &m_vector;
    }

    /// Returns whether the vector is empty
    bool empty() const {
        return igraph_vector_bool_empty(&m_vector);
    }

    /// Returns an iterator pointing after the last element of the vector
    iterator end() {
        return &(VECTOR(m_vector)[size()]);
    }

    /// Returns an iterator pointing after the last element of the vector (const)
    const_iterator end() const {
        return &(VECTOR(m_vector)[size()]);
    }

    /// Fills the vector with the given item
    void fill(value_type element) {
        igraph_vector_bool_fill(&m_vector, element);
    }

    /// Returns the first element of the vector
    reference front() {
        return VECTOR(m_vector)[0];
    }

    /// Returns the first element of the vector (const variant)
    const_reference front() const {
        return VECTOR(m_vector)[0];
    }

    /// Pops an element from the end of the vector
    value_type pop_back() {
        return igraph_vector_bool_pop_back(&m_vector);
    }

    /// Prints the vector to the standard output
    void print() const {
        igraph_vector_bool_print(&m_vector);
    }

    /// Adds a new element to the end of the vector
    void push_back(value_type e) {
        IGRAPH_TRY(igraph_vector_bool_push_back(&m_vector, e));
    }

    /// Removes an element at the given index from the vector
    void remove(long int index) {
        igraph_vector_bool_remove(&m_vector, index);
    }

    /// Removes a section of the vector
    void remove_section(long int from, long int to) {
        igraph_vector_bool_remove_section(&m_vector, from, to);
    }

    /// Reserves space for the given number of elements in the vector
    void reserve(size_type newsize) {
        IGRAPH_TRY(igraph_vector_bool_reserve(&m_vector, newsize));
    }

    /// Resizes the vector
    void resize(size_type newsize) {
        IGRAPH_TRY(igraph_vector_bool_resize(&m_vector, newsize));
    }

    /// Returns the size of the vector
    size_type size() const {
        return igraph_vector_bool_size(&m_vector);
    }

    /// Returns the sum of the elements of the vector
    value_type sum() const {
        return igraph_vector_bool_sum(&m_vector);
    }

    /// Swaps the elements of this vector with another one if they are of equal length
    void swap(VectorBool& v2) {
        IGRAPH_TRY(igraph_vector_bool_swap(&m_vector, &v2.m_vector));
    }

    /*************/
    /* Operators */
    /*************/

    /// Assignment operator: copies the given vector to this one
    VectorBool& operator=(const VectorBool& other) {
        IGRAPH_TRY(igraph_vector_bool_update(&m_vector, &other.m_vector));
        return *this;
    }

    /// Assignment operator: copies the given array to this vector
    /**
     * It is assumed that the array has the required size.
     */
    VectorBool& operator=(const pointer other) {
        memcpy(m_vector.stor_begin, other, size());
        return *this;
    }

    /// Equality check: returns true if the two vectors are equal
    bool operator==(const VectorBool& other) const {
        return igraph_vector_bool_is_equal(&m_vector, &other.m_vector);
    }

    /// Nonequality check: returns true if the two vectors are not equal
    bool operator!=(const VectorBool& other) const {
        return !((*this) == other);
    }

    /// Returns the element with the given index
    reference operator[](long int index) {
        return VECTOR(m_vector)[index];
    }

    /// Returns the element with the given index (const variant)
    value_type operator[](long int index) const {
        return VECTOR(m_vector)[index];
    }

    /// In-place addition of a vector
    VectorBool& operator+=(const VectorBool& v2) {
        IGRAPH_TRY(igraph_vector_bool_add(&m_vector, &v2.m_vector));
        return *this;
    }

    /// In-place subtraction of a vector
    VectorBool& operator-=(const VectorBool& v2) {
        IGRAPH_TRY(igraph_vector_bool_sub(&m_vector, &v2.m_vector));
        return *this;
    }

    /// Vector-vector scalar product
    long int operator*(const VectorBool& vector) const;
};

}       // end of namespaces

#endif  // IGRAPHPP_VECTOR_BOOL_H

