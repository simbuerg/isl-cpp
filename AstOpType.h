#ifndef ISL_CXX_AstOpType_H
#define ISL_CXX_AstOpType_H

namespace isl {
enum class AstOpType {
  OpAccess = 23,
  OpAdd = 7,
  OpAddressOf = 25,
  OpAnd = 0,
  OpAndThen = 1,
  OpCall = 22,
  OpCond = 15,
  OpDiv = 10,
  OpEq = 17,
  OpError = -1,
  OpFdivQ = 11,
  OpGe = 20,
  OpGt = 21,
  OpLe = 18,
  OpLt = 19,
  OpMax = 4,
  OpMember = 24,
  OpMin = 5,
  OpMinus = 6,
  OpMul = 9,
  OpOr = 2,
  OpOrElse = 3,
  OpPdivQ = 12,
  OpPdivR = 13,
  OpSelect = 16,
  OpSub = 8,
  OpZdivR = 14,
};
} // namespace isl
#endif //ISL_CXX_AstOpType_H
