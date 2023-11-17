#ifndef ARRAYCLASS_ARRAYCLASS_H
#define ARRAYCLASS_ARRAYCLASS_H

#include <cstddef>

namespace pelipeychenko {
  struct Array {
    Array(const char *path);

    Array(std::size_t size);

    ~Array();

    std::size_t getFileSize(const char *path);

    void fillFromFile(const char *path) const;

    void fillWithRandom() const;

    int findCountLeftToMin() const;

    std::size_t size_;
    int *data_;
  };
}

#endif
