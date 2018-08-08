#ifndef TYPES_H_
#define TYPES_H_

#include <string>

enum DataType {
  DT_INVALID = 0,
  DT_FLOAT = 1,
  DT_DOUBLE = 2,
  DT_INT32 = 3,
  DT_UINT8 = 4,
  DT_INT16 = 5,
  DT_INT8 = 6,
  DT_STRING = 7,

  DT_INT64 = 9,
  DT_BOOL = 10,

  DT_UINT32 = 22,
  DT_UINT64 = 23,

  DT_FLOAT_REF = 101,
  DT_DOUBLE_REF = 102,
  DT_INT32_REF = 103,
  DT_UINT8_REF = 104,
  DT_INT16_REF = 105,
  DT_INT8_REF = 106,
  DT_STRING_REF = 107,

  DT_INT64_REF = 109,
  DT_BOOL_REF = 110,

  DT_UINT32_REF = 122,
  DT_UINT64_REF = 123,
};

enum { kDataTypeRefOffset = 100 };

inline bool IsRefType(DataType dtype) {
  return dtype > static_cast<DataType>(kDataTypeRefOffset);
}

inline DataType MakeRefType(DataType dtype) {
  assert(!IsRefType(dtype));
  return static_cast<DataType>(dtype + kDataTypeRefOffset);
}

template <class T>
struct IsValidDataType;

template <class T>
struct DataTypeToEnum {
  static_assert(IsValidDataType<T>::value, "Specified Data Type not supported");
};

template <DataType Value>
struct EnumToDataType {};

#define MATCH_TYPE_AND_ENUM(TYPE, ENUM)                 \
  template <>                                           \
  struct DataTypeToEnum<TYPE> {                         \
    static DataType v() { return ENUM; }                \
    static DataType ref() { return MakeRefType(ENUM); } \
    static constexpr DataType value = ENUM;             \
  };                                                    \
  template <>                                           \
  struct IsValidDataType<TYPE> {                        \
    static constexpr bool value = true;                 \
  };                                                    \
  template <>                                           \
  struct EnumToDataType<ENUM> {                         \
    typedef TYPE Type;                                  \
  }

MATCH_TYPE_AND_ENUM(float, DT_FLOAT);
MATCH_TYPE_AND_ENUM(double, DT_DOUBLE);
MATCH_TYPE_AND_ENUM(int32_t, DT_INT32);
MATCH_TYPE_AND_ENUM(uint8_t, DT_UINT8);
MATCH_TYPE_AND_ENUM(int16_t, DT_INT16);
MATCH_TYPE_AND_ENUM(int8_t, DT_INT8);
MATCH_TYPE_AND_ENUM(std::string, DT_STRING);
MATCH_TYPE_AND_ENUM(int64_t, DT_INT64);
MATCH_TYPE_AND_ENUM(bool, DT_BOOL);
MATCH_TYPE_AND_ENUM(uint32_t, DT_UINT32);
MATCH_TYPE_AND_ENUM(uint64_t, DT_UINT64);

#undef MATCH_TYPE_AND_ENUM

template <class T>
struct IsValidDataType {
  static constexpr bool value = false;
};

#endif
