#ifndef ISL_CXX_AstNodeType_H
#define ISL_CXX_AstNodeType_H

namespace isl {
enum AstNodeType {
  ANTNodeBlock = 3,
  ANTNodeError = -1,
  ANTNodeFor = 1,
  ANTNodeIf = 2,
  ANTNodeMark = 4,
  ANTNodeUser = 5,
};
} // namespace isl
#endif //ISL_CXX_AstNodeType_H
