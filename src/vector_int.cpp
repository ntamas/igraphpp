/* vim:set ts=4 sw=4 sts=4 et: */

#include <cassert>
#include <igraph/cpp/vector_int.h>

namespace igraph {

integer_t VectorInt::operator*(const VectorInt& vector) const {
    VectorInt::value_type result = VectorInt::value_type();

    assert(vector.size() == size());

    VectorInt::const_iterator it1 = begin(), it2 = vector.begin(), it3 = end();
    while (it1 != it3) {
        result += (*it1) * (*it2);
        it1++; it2++;
    }
    return result;
}

VectorInt operator+(integer_t plus, const VectorInt& vector) {
    return vector * plus;
}

VectorInt operator-(integer_t minus, const VectorInt& vector) {
    return (-vector) + minus;
}

VectorInt operator*(real_t by, const VectorInt& vector) {
    return vector * by;
}

}         // end of namespaces
