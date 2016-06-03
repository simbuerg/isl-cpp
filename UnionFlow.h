#ifndef ISL_CXX_UnionFlow_H
#define ISL_CXX_UnionFlow_H


#include "isl/union_flow.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class UnionMap;

class UnionFlow {
protected:
  Ctx ctx;
  void * This;
public:
  explicit UnionFlow(Ctx ctx, isl_union_flow *That) : ctx(ctx), This(That) {}
  UnionFlow() : ctx(Ctx(nullptr)), This(nullptr) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_union_flow *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_union_flow *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_union_flow *Get() const;
public:
  virtual ~UnionFlow();
  /// \brief Generated from  ::<isl_union_flow_get_full_may_dependence>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getFullMayDependence() const;

  /// \brief Generated from  ::<isl_union_flow_get_full_must_dependence>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getFullMustDependence() const;

  /// \brief Generated from  ::<isl_union_flow_get_may_dependence>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getMayDependence() const;

  /// \brief Generated from  ::<isl_union_flow_get_may_no_source>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getMayNoSource() const;

  /// \brief Generated from  ::<isl_union_flow_get_must_dependence>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getMustDependence() const;

  /// \brief Generated from  ::<isl_union_flow_get_must_no_source>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getMustNoSource() const;

  /// \brief Generated from  ::<isl_union_flow_to_str>
  ///
  ///
  /// \returns A new std::string
  std::string toStr() const;

  UnionFlow(const UnionFlow &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  UnionFlow &operator=(const UnionFlow &Other);
  UnionFlow (UnionFlow && Other) : ctx(Other.Context()), This(Other.Give()) {}
  UnionFlow &operator=(UnionFlow && Other) {
    isl_union_flow *New = Other.Give();
    isl_union_flow_free((isl_union_flow *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const UnionFlow &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_UnionFlow_H
