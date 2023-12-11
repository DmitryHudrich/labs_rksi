#pragma once

#include <stdint.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

namespace Math {
template <typename T> using twodimensional_vector = std::vector<std::vector<T>>;

template <typename T> class SquareMatrix {
private:
    twodimensional_vector<T> data;
    uint16_t m_size;
    uint16_t n_size;
    uint32_t count;

public:
    SquareMatrix(uint16_t m, uint16_t n, bool isRandom = true);
    SquareMatrix(twodimensional_vector<T> matrix);
    SquareMatrix(const SquareMatrix& matrix);

#pragma region getters;
public:
    uint16_t mSize() const;
    uint16_t nSize() const;
    uint32_t getCount() const;
    twodimensional_vector<T> getData() const;
    void setValue(uint16_t i, uint16_t j, T value);

#pragma endregion getters
public:
    SquareMatrix<T> operator+(const SquareMatrix<T>& right_matrix) const;
    SquareMatrix<T> operator*(const SquareMatrix<T>& right_matrix) const;
    bool operator==(const SquareMatrix<T>& right_matrix) const;
};


template <typename T>
SquareMatrix<T> multiply(SquareMatrix<T> first, SquareMatrix<T> second);

template <typename T>
SquareMatrix<T> sum(SquareMatrix<T> first, SquareMatrix<T> second);

} // namespace Math

template <typename T> using twodimensional_vector = std::vector<std::vector<T>>;

template <typename T>
Math::SquareMatrix<T>::SquareMatrix(uint16_t m, uint16_t n, bool isRandom)
    : m_size(m), n_size(n) {
    this->count = m * n;
    if (isRandom) {
        srand(time(NULL));
        for (size_t i = 0; i < m; i++) {
            this->data.push_back(std::vector<T>());
            for (size_t j = 0; j < n; j++) {
                this->data[i].push_back(rand() % 200 - 100);
            }
        }
    } else {
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                this->data[i].push_back(0);
            }
        }
    }
}

template <typename T>
Math::SquareMatrix<T>::SquareMatrix(twodimensional_vector<T> matrix)
    : data(matrix), n_size(matrix.size()), m_size(matrix[0].size()),
      count(this->n_size * this->m_size) {
}

template <typename T>
Math::SquareMatrix<T>::SquareMatrix(const SquareMatrix& matrix)
    : count(matrix.getCount()), n_size(matrix.nSize()), m_size(matrix.mSize()),
      data(matrix.getData()) {
}

template <typename T>
Math::SquareMatrix<T> Math::SquareMatrix<T>::operator+(
    const SquareMatrix<T>& other) const {
    return Math::sum(*this, other);
}

template <typename T>
Math::SquareMatrix<T> Math::SquareMatrix<T>::operator*(
    const SquareMatrix<T>& other) const {
    return Math::multiply(*this, other);
}

template <typename T> uint32_t Math::SquareMatrix<T>::getCount() const {
    return this->count;
}

template <typename T> uint16_t Math::SquareMatrix<T>::nSize() const {
    return this->n_size;
}

template <typename T> uint16_t Math::SquareMatrix<T>::mSize() const {
    return this->m_size;
}

template <typename T>
twodimensional_vector<T> Math::SquareMatrix<T>::getData() const {
    return this->data;
}

template <typename T>
Math::SquareMatrix<T> Math::multiply(SquareMatrix<T> first,
                                     SquareMatrix<T> second) {
    if (first.mSize() != second.nSize()) {
        throw "Matrices cannot be multiplied!";
    }

    twodimensional_vector<T> result(first.mSize(),
                                    std::vector<T>(second.nSize()));

    for (uint16_t i = 0; i < first.mSize(); i++) {
        for (uint16_t j = 0; j < second.nSize(); j++) {
            result[i][j] = 0;
            for (uint16_t k = 0; k < first.nSize(); k++) {
                result[i][j] += first.getData()[i][k] * second.getData()[k][j];
            }
        }
    }

    return SquareMatrix<T>(result);
}

template <typename T>
Math::SquareMatrix<T> Math::sum(SquareMatrix<T> first, SquareMatrix<T> second) {
    if (first.mSize() != second.mSize() || first.nSize() != second.nSize()) {
        throw "Matrices dimensions must match!";
    }

    twodimensional_vector<T> result(first.mSize(),
                                    std::vector<T>(first.nSize()));

    for (uint16_t i = 0; i < first.mSize(); i++) {
        for (uint16_t j = 0; j < first.nSize(); j++) {
            result[i][j] = first.getData()[i][j] + second.getData()[i][j];
        }
    }

    return SquareMatrix<T>(result);
}

template <typename T>
bool Math::SquareMatrix<T>::operator==(const SquareMatrix<T>& right_matrix) const {
  if(this->mSize() != right_matrix.mSize() || this->nSize() != right_matrix.nSize()) {
    return false;
  }

  for(uint16_t i = 0; i < this->mSize(); i++) {
    for(uint16_t j = 0; j < this->nSize(); j++) {
      if(this->getData()[i][j] != right_matrix.getData()[i][j]) {
        return false;
      }
    }
  }

  return true;
}

template <typename T>
void Math::SquareMatrix<T>::setValue(uint16_t i, uint16_t j, T value) {
    data[i][j] = value;
}