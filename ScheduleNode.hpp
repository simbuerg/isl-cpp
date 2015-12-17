#ifndef ISL_CXX_ScheduleNode_IMPL_H
#define ISL_CXX_ScheduleNode_IMPL_H

#include "isl/ScheduleNode.h"

#include "isl/Id.hpp"
#include "isl/MultiUnionPwAff.hpp"
#include "isl/MultiVal.hpp"
#include "isl/Schedule.hpp"
#include "isl/Set.hpp"
#include "isl/Space.hpp"
#include "isl/UnionMap.hpp"
#include "isl/UnionPwMultiAff.hpp"
#include "isl/UnionSet.hpp"
#include "isl/UnionSetList.hpp"
#include "isl/Bool.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/ScheduleNodeType.h"
#include "isl/Stat.h"
#include <string>
#include <ostream>

#include <cassert>

namespace isl {
inline isl_schedule_node *ScheduleNode::GetCopy() const {
  return isl_schedule_node_copy((isl_schedule_node *)This);
}
inline ScheduleNode &ScheduleNode::operator=(const ScheduleNode &Other) {
  isl_schedule_node *New = Other.GetCopy();
  isl_schedule_node_free((isl_schedule_node *)This);
  This = New;
  return *this;
}
inline ScheduleNode ScheduleNode::fromDomain(const UnionSet &domain) {
  const Ctx &_ctx = domain.Context();
  _ctx.lock();
  UnionSet _cast_domain = domain.asUnionSet();
  isl_schedule_node *That = isl_schedule_node_from_domain((_cast_domain).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_schedule_node_from_domain returned a NULL pointer.");
  }

  return ScheduleNode(_ctx, That);
}

inline ScheduleNode ScheduleNode::fromExtension(const UnionMap &extension) {
  const Ctx &_ctx = extension.Context();
  _ctx.lock();
  UnionMap _cast_extension = extension.asUnionMap();
  isl_schedule_node *That = isl_schedule_node_from_extension((_cast_extension).Give());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_schedule_node_from_extension returned a NULL pointer.");
  }

  return ScheduleNode(_ctx, That);
}
inline ScheduleNode::~ScheduleNode() {
  isl_schedule_node_free((isl_schedule_node *)This);
  This = nullptr;
}
/// rief Release ownership of the wrapped object.
///
/// You are on your own now buddy.
/// The wrapper cannot be used anymore after calling Give()
///
///@return the wrapped isl object.
inline isl_schedule_node *ScheduleNode::Give() {
  isl_schedule_node *res = (isl_schedule_node *)This;
  This = nullptr;
  return res;
}
/// \brief Unwrap the stored isl object.
/// \returns A the wrapped isl object.
inline isl_schedule_node *ScheduleNode::Get() const {  return (isl_schedule_node *)This;
}

inline ScheduleNode ScheduleNode::asScheduleNode() const {
  return ScheduleNode(ctx, GetCopy());
}

inline ScheduleNode ScheduleNode::alignParams(const Space &space) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  Space _cast_space = space.asSpace();
  // Call isl_schedule_node_align_params
  isl_schedule_node * res =  isl_schedule_node_align_params((self).Give(), (_cast_space).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_align_params returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::ancestor(int generation) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_ancestor
  isl_schedule_node * res =  isl_schedule_node_ancestor((self).Give(), generation);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_ancestor returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline UnionSet ScheduleNode::bandGetAstBuildOptions() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_get_ast_build_options
  isl_union_set * res =  isl_schedule_node_band_get_ast_build_options((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_get_ast_build_options returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline MultiUnionPwAff ScheduleNode::bandGetPartialSchedule() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_get_partial_schedule
  isl_multi_union_pw_aff * res =  isl_schedule_node_band_get_partial_schedule((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_get_partial_schedule returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline UnionMap ScheduleNode::bandGetPartialScheduleUnionMap() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_get_partial_schedule_union_map
  isl_union_map * res =  isl_schedule_node_band_get_partial_schedule_union_map((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_get_partial_schedule_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline Bool ScheduleNode::bandGetPermutable() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_get_permutable
  isl_bool res =  isl_schedule_node_band_get_permutable((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Space ScheduleNode::bandGetSpace() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_get_space
  isl_space * res =  isl_schedule_node_band_get_space((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline enum isl_ast_loop_type ScheduleNode::bandMemberGetAstLoopType(int pos) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_member_get_ast_loop_type
  enum isl_ast_loop_type res =  isl_schedule_node_band_member_get_ast_loop_type((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline Bool ScheduleNode::bandMemberGetCoincident(int pos) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_member_get_coincident
  isl_bool res =  isl_schedule_node_band_member_get_coincident((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline enum isl_ast_loop_type ScheduleNode::bandMemberGetIsolateAstLoopType(int pos) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_member_get_isolate_ast_loop_type
  enum isl_ast_loop_type res =  isl_schedule_node_band_member_get_isolate_ast_loop_type((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline ScheduleNode ScheduleNode::bandMemberSetAstLoopType(int pos, enum isl_ast_loop_type type) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_member_set_ast_loop_type
  isl_schedule_node * res =  isl_schedule_node_band_member_set_ast_loop_type((self).Give(), pos, type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_member_set_ast_loop_type returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandMemberSetCoincident(int pos, int coincident) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_member_set_coincident
  isl_schedule_node * res =  isl_schedule_node_band_member_set_coincident((self).Give(), pos, coincident);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_member_set_coincident returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandMemberSetIsolateAstLoopType(int pos, enum isl_ast_loop_type type) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_member_set_isolate_ast_loop_type
  isl_schedule_node * res =  isl_schedule_node_band_member_set_isolate_ast_loop_type((self).Give(), pos, type);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_member_set_isolate_ast_loop_type returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandMod(const MultiVal &mv) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  MultiVal _cast_mv = mv.asMultiVal();
  // Call isl_schedule_node_band_mod
  isl_schedule_node * res =  isl_schedule_node_band_mod((self).Give(), (_cast_mv).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_mod returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline unsigned int ScheduleNode::bandNMember() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_n_member
  unsigned int res =  isl_schedule_node_band_n_member((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline ScheduleNode ScheduleNode::bandScale(const MultiVal &mv) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  MultiVal _cast_mv = mv.asMultiVal();
  // Call isl_schedule_node_band_scale
  isl_schedule_node * res =  isl_schedule_node_band_scale((self).Give(), (_cast_mv).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_scale returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandScaleDown(const MultiVal &mv) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  MultiVal _cast_mv = mv.asMultiVal();
  // Call isl_schedule_node_band_scale_down
  isl_schedule_node * res =  isl_schedule_node_band_scale_down((self).Give(), (_cast_mv).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_scale_down returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandSetAstBuildOptions(const UnionSet &options) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  UnionSet _cast_options = options.asUnionSet();
  // Call isl_schedule_node_band_set_ast_build_options
  isl_schedule_node * res =  isl_schedule_node_band_set_ast_build_options((self).Give(), (_cast_options).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_set_ast_build_options returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandSetPermutable(int permutable) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_set_permutable
  isl_schedule_node * res =  isl_schedule_node_band_set_permutable((self).Give(), permutable);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_set_permutable returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandShift(const MultiUnionPwAff &shift) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  MultiUnionPwAff _cast_shift = shift.asMultiUnionPwAff();
  // Call isl_schedule_node_band_shift
  isl_schedule_node * res =  isl_schedule_node_band_shift((self).Give(), (_cast_shift).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_shift returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandSink() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_sink
  isl_schedule_node * res =  isl_schedule_node_band_sink((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_sink returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandSplit(int pos) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_band_split
  isl_schedule_node * res =  isl_schedule_node_band_split((self).Give(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_split returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandTile(const MultiVal &sizes) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  MultiVal _cast_sizes = sizes.asMultiVal();
  // Call isl_schedule_node_band_tile
  isl_schedule_node * res =  isl_schedule_node_band_tile((self).Give(), (_cast_sizes).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_tile returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::child(int pos) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_child
  isl_schedule_node * res =  isl_schedule_node_child((self).Give(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_child returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline Set ScheduleNode::contextGetContext() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_context_get_context
  isl_set * res =  isl_schedule_node_context_get_context((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_context_get_context returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline ScheduleNode ScheduleNode::copy() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_copy
  isl_schedule_node * res =  isl_schedule_node_copy((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_copy returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::cut() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_cut
  isl_schedule_node * res =  isl_schedule_node_cut((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_cut returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::delete_() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_delete
  isl_schedule_node * res =  isl_schedule_node_delete((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_delete returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline UnionSet ScheduleNode::domainGetDomain() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_domain_get_domain
  isl_union_set * res =  isl_schedule_node_domain_get_domain((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_domain_get_domain returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline void ScheduleNode::dump() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_dump
   isl_schedule_node_dump((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
}

inline UnionPwMultiAff ScheduleNode::expansionGetContraction() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_expansion_get_contraction
  isl_union_pw_multi_aff * res =  isl_schedule_node_expansion_get_contraction((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_expansion_get_contraction returned a NULL pointer.");
  }
  return UnionPwMultiAff(ctx, res);
}

inline UnionMap ScheduleNode::expansionGetExpansion() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_expansion_get_expansion
  isl_union_map * res =  isl_schedule_node_expansion_get_expansion((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_expansion_get_expansion returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap ScheduleNode::extensionGetExtension() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_extension_get_extension
  isl_union_map * res =  isl_schedule_node_extension_get_extension((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_extension_get_extension returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet ScheduleNode::filterGetFilter() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_filter_get_filter
  isl_union_set * res =  isl_schedule_node_filter_get_filter((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_filter_get_filter returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline ScheduleNode ScheduleNode::firstChild() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_first_child
  isl_schedule_node * res =  isl_schedule_node_first_child((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_first_child returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline Stat ScheduleNode::foreachAncestorTopDown(const std::function<isl_stat(isl_schedule_node *, void *)> && fn, void * user) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_foreach_ancestor_top_down
  isl_stat res =  isl_schedule_node_foreach_ancestor_top_down((self).Get(), get_fn_ptr<19>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline Stat ScheduleNode::foreachDescendantTopDown(const std::function<isl_bool(isl_schedule_node *, void *)> && fn, void * user) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_foreach_descendant_top_down
  isl_stat res =  isl_schedule_node_foreach_descendant_top_down((self).Get(), get_fn_ptr<20>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Stat)res;
}

inline int ScheduleNode::getAncestorChildPosition(const ScheduleNode &ancestor) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  ScheduleNode _cast_ancestor = ancestor.asScheduleNode();
  // Call isl_schedule_node_get_ancestor_child_position
  int res =  isl_schedule_node_get_ancestor_child_position((self).Get(), (_cast_ancestor).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline ScheduleNode ScheduleNode::getChild(int pos) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_child
  isl_schedule_node * res =  isl_schedule_node_get_child((self).Get(), pos);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_child returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline int ScheduleNode::getChildPosition() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_child_position
  int res =  isl_schedule_node_get_child_position((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline ScheduleNodeType ScheduleNode::getParentType() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_parent_type
  enum isl_schedule_node_type res =  isl_schedule_node_get_parent_type((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (ScheduleNodeType)res;
}

inline MultiUnionPwAff ScheduleNode::getPrefixScheduleMultiUnionPwAff() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_prefix_schedule_multi_union_pw_aff
  isl_multi_union_pw_aff * res =  isl_schedule_node_get_prefix_schedule_multi_union_pw_aff((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_prefix_schedule_multi_union_pw_aff returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline UnionMap ScheduleNode::getPrefixScheduleRelation() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_prefix_schedule_relation
  isl_union_map * res =  isl_schedule_node_get_prefix_schedule_relation((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_prefix_schedule_relation returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap ScheduleNode::getPrefixScheduleUnionMap() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_prefix_schedule_union_map
  isl_union_map * res =  isl_schedule_node_get_prefix_schedule_union_map((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_prefix_schedule_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionPwMultiAff ScheduleNode::getPrefixScheduleUnionPwMultiAff() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_prefix_schedule_union_pw_multi_aff
  isl_union_pw_multi_aff * res =  isl_schedule_node_get_prefix_schedule_union_pw_multi_aff((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_prefix_schedule_union_pw_multi_aff returned a NULL pointer.");
  }
  return UnionPwMultiAff(ctx, res);
}

inline Schedule ScheduleNode::getSchedule() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_schedule
  isl_schedule * res =  isl_schedule_node_get_schedule((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_schedule returned a NULL pointer.");
  }
  return Schedule(ctx, res);
}

inline int ScheduleNode::getScheduleDepth() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_schedule_depth
  int res =  isl_schedule_node_get_schedule_depth((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline ScheduleNode ScheduleNode::getSharedAncestor(const ScheduleNode &node2) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  ScheduleNode _cast_node2 = node2.asScheduleNode();
  // Call isl_schedule_node_get_shared_ancestor
  isl_schedule_node * res =  isl_schedule_node_get_shared_ancestor((self).Get(), (_cast_node2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_shared_ancestor returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline UnionPwMultiAff ScheduleNode::getSubtreeContraction() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_subtree_contraction
  isl_union_pw_multi_aff * res =  isl_schedule_node_get_subtree_contraction((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_subtree_contraction returned a NULL pointer.");
  }
  return UnionPwMultiAff(ctx, res);
}

inline UnionMap ScheduleNode::getSubtreeExpansion() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_subtree_expansion
  isl_union_map * res =  isl_schedule_node_get_subtree_expansion((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_subtree_expansion returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap ScheduleNode::getSubtreeScheduleUnionMap() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_subtree_schedule_union_map
  isl_union_map * res =  isl_schedule_node_get_subtree_schedule_union_map((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_subtree_schedule_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline int ScheduleNode::getTreeDepth() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_tree_depth
  int res =  isl_schedule_node_get_tree_depth((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline ScheduleNodeType ScheduleNode::getType() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_type
  enum isl_schedule_node_type res =  isl_schedule_node_get_type((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (ScheduleNodeType)res;
}

inline UnionSet ScheduleNode::getUniverseDomain() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_get_universe_domain
  isl_union_set * res =  isl_schedule_node_get_universe_domain((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_universe_domain returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline ScheduleNode ScheduleNode::graftAfter(const ScheduleNode &graft) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  ScheduleNode _cast_graft = graft.asScheduleNode();
  // Call isl_schedule_node_graft_after
  isl_schedule_node * res =  isl_schedule_node_graft_after((self).Give(), (_cast_graft).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_graft_after returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::graftBefore(const ScheduleNode &graft) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  ScheduleNode _cast_graft = graft.asScheduleNode();
  // Call isl_schedule_node_graft_before
  isl_schedule_node * res =  isl_schedule_node_graft_before((self).Give(), (_cast_graft).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_graft_before returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::group(const Id &group_id) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  Id _cast_group_id = group_id.asId();
  // Call isl_schedule_node_group
  isl_schedule_node * res =  isl_schedule_node_group((self).Give(), (_cast_group_id).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_group returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline Set ScheduleNode::guardGetGuard() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_guard_get_guard
  isl_set * res =  isl_schedule_node_guard_get_guard((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_guard_get_guard returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Bool ScheduleNode::hasChildren() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_has_children
  isl_bool res =  isl_schedule_node_has_children((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool ScheduleNode::hasNextSibling() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_has_next_sibling
  isl_bool res =  isl_schedule_node_has_next_sibling((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool ScheduleNode::hasParent() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_has_parent
  isl_bool res =  isl_schedule_node_has_parent((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool ScheduleNode::hasPreviousSibling() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_has_previous_sibling
  isl_bool res =  isl_schedule_node_has_previous_sibling((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline ScheduleNode ScheduleNode::insertContext(const Set &context) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_schedule_node_insert_context
  isl_schedule_node * res =  isl_schedule_node_insert_context((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_context returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertFilter(const UnionSet &filter) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  UnionSet _cast_filter = filter.asUnionSet();
  // Call isl_schedule_node_insert_filter
  isl_schedule_node * res =  isl_schedule_node_insert_filter((self).Give(), (_cast_filter).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_filter returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertGuard(const Set &context) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  Set _cast_context = context.asSet();
  // Call isl_schedule_node_insert_guard
  isl_schedule_node * res =  isl_schedule_node_insert_guard((self).Give(), (_cast_context).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_guard returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertMark(const Id &mark) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  Id _cast_mark = mark.asId();
  // Call isl_schedule_node_insert_mark
  isl_schedule_node * res =  isl_schedule_node_insert_mark((self).Give(), (_cast_mark).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_mark returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertPartialSchedule(const MultiUnionPwAff &schedule) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  MultiUnionPwAff _cast_schedule = schedule.asMultiUnionPwAff();
  // Call isl_schedule_node_insert_partial_schedule
  isl_schedule_node * res =  isl_schedule_node_insert_partial_schedule((self).Give(), (_cast_schedule).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_partial_schedule returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertSequence(const UnionSetList &filters) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  UnionSetList _cast_filters = filters.asUnionSetList();
  // Call isl_schedule_node_insert_sequence
  isl_schedule_node * res =  isl_schedule_node_insert_sequence((self).Give(), (_cast_filters).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_sequence returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertSet(const UnionSetList &filters) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  UnionSetList _cast_filters = filters.asUnionSetList();
  // Call isl_schedule_node_insert_set
  isl_schedule_node * res =  isl_schedule_node_insert_set((self).Give(), (_cast_filters).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_set returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline Bool ScheduleNode::isEqual(const ScheduleNode &node2) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  ScheduleNode _cast_node2 = node2.asScheduleNode();
  // Call isl_schedule_node_is_equal
  isl_bool res =  isl_schedule_node_is_equal((self).Get(), (_cast_node2).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline Bool ScheduleNode::isSubtreeAnchored() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_is_subtree_anchored
  isl_bool res =  isl_schedule_node_is_subtree_anchored((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return (Bool)res;
}

inline ScheduleNode ScheduleNode::mapDescendantBottomUp(const std::function<isl_schedule_node *(isl_schedule_node *, void *)> && fn, void * user) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_map_descendant_bottom_up
  isl_schedule_node * res =  isl_schedule_node_map_descendant_bottom_up((self).Give(), get_fn_ptr<21>(fn), user);
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_map_descendant_bottom_up returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline Id ScheduleNode::markGetId() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_mark_get_id
  isl_id * res =  isl_schedule_node_mark_get_id((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_mark_get_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline int ScheduleNode::nChildren() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_n_children
  int res =  isl_schedule_node_n_children((self).Get());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  return res;
}

inline ScheduleNode ScheduleNode::nextSibling() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_next_sibling
  isl_schedule_node * res =  isl_schedule_node_next_sibling((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_next_sibling returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::orderAfter(const UnionSet &filter) const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  UnionSet _cast_filter = filter.asUnionSet();
  // Call isl_schedule_node_order_after
  isl_schedule_node * res =  isl_schedule_node_order_after((self).Give(), (_cast_filter).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_order_after returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::parent() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_parent
  isl_schedule_node * res =  isl_schedule_node_parent((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_parent returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::previousSibling() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_previous_sibling
  isl_schedule_node * res =  isl_schedule_node_previous_sibling((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_previous_sibling returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::resetUser() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_reset_user
  isl_schedule_node * res =  isl_schedule_node_reset_user((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_reset_user returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::root() const {
  ctx.lock();
  ScheduleNode self = asScheduleNode();
  // Prepare arguments
  // Call isl_schedule_node_root
  isl_schedule_node * res =  isl_schedule_node_root((self).Give());
  // Handle result argument(s)
  ctx.unlock();
  // Handle return
  if (ctx.hasError()) {
    handleError("isl_schedule_node_root returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_ScheduleNode_IMPL_H
