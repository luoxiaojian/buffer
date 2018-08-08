#ifndef BUFFER_H_
#define BUFFER_H_

#include <assert.h>

#include <vector>

#include "src/types.h"

class BufferBase {
 public:
  virtual ~BufferBase() {}

  virtual void* data() = 0;
  virtual size_t size() = 0;
  virtual DataType type() = 0;

  template <typename T>
  T* base() {
    return reinterpret_cast<T*>(data());
  }
};

template <typename T>
class Buffer : public BufferBase {
 public:
  Buffer() {}
  Buffer(size_t size) : data_(size), updated_(size, false) {}

  void* data() { return reinterpret_cast<void*>(&data_[0]); }
  size_t size() { return data_.size(); }
  DataType type() { return DataTypeToEnum<T>::value; }

  void SetValue(int index, const T& value) {
    data_[index] = value;
    updated_[index] = true;
  }

  const T& GetValue(int index) { return data_[index]; }

  bool IsUpdated(int index) { return updated_[index]; }

  void Reset(int index) { updated_[index] = false; }

  void Reset() { std::fill(updated_.begin(), updated_.end(), false); }

  void Clear() {
    data_.clear();
    updated_.clear();
  }

 private:
  std::vector<T> data_;
  std::vector<bool> updated_;
};

#endif  // BUFFER_H_
