#ifndef ISL_CXX_ScheduleNodeType_H
#define ISL_CXX_ScheduleNodeType_H

namespace isl {
enum class ScheduleNodeType {
  NodeBand = 0,
  NodeContext = 1,
  NodeDomain = 2,
  NodeError = -1,
  NodeExpansion = 3,
  NodeExtension = 4,
  NodeFilter = 5,
  NodeGuard = 7,
  NodeLeaf = 6,
  NodeMark = 8,
  NodeSequence = 9,
  NodeSet = 10,
};
} // namespace isl
#endif //ISL_CXX_ScheduleNodeType_H
