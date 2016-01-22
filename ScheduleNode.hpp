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
  isl_schedule_node *That = isl_schedule_node_from_domain((domain).GetCopy());

  _ctx.unlock();
  if (_ctx.hasError()) {
    handleError("isl_schedule_node_from_domain returned a NULL pointer.");
  }

  return ScheduleNode(_ctx, That);
}

inline ScheduleNode ScheduleNode::fromExtension(const UnionMap &extension) {
  const Ctx &_ctx = extension.Context();
  _ctx.lock();
  isl_schedule_node *That = isl_schedule_node_from_extension((extension).GetCopy());

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


inline ScheduleNode ScheduleNode::alignParams(const Space &space) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_align_params((*this).GetCopy(), (space).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_align_params returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::ancestor(int generation) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_ancestor((*this).GetCopy(), generation);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_ancestor returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline UnionSet ScheduleNode::bandGetAstBuildOptions() const {
  ctx.lock();
  isl_union_set * res =  isl_schedule_node_band_get_ast_build_options((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_get_ast_build_options returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline MultiUnionPwAff ScheduleNode::bandGetPartialSchedule() const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_schedule_node_band_get_partial_schedule((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_get_partial_schedule returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline UnionMap ScheduleNode::bandGetPartialScheduleUnionMap() const {
  ctx.lock();
  isl_union_map * res =  isl_schedule_node_band_get_partial_schedule_union_map((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_get_partial_schedule_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline Bool ScheduleNode::bandGetPermutable() const {
  ctx.lock();
  isl_bool res =  isl_schedule_node_band_get_permutable((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Space ScheduleNode::bandGetSpace() const {
  ctx.lock();
  isl_space * res =  isl_schedule_node_band_get_space((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_get_space returned a NULL pointer.");
  }
  return Space(ctx, res);
}

inline enum isl_ast_loop_type ScheduleNode::bandMemberGetAstLoopType(int pos) const {
  ctx.lock();
  enum isl_ast_loop_type res =  isl_schedule_node_band_member_get_ast_loop_type((*this).Get(), pos);
  ctx.unlock();
  return res;
}

inline Bool ScheduleNode::bandMemberGetCoincident(int pos) const {
  ctx.lock();
  isl_bool res =  isl_schedule_node_band_member_get_coincident((*this).Get(), pos);
  ctx.unlock();
  return (Bool)res;
}

inline enum isl_ast_loop_type ScheduleNode::bandMemberGetIsolateAstLoopType(int pos) const {
  ctx.lock();
  enum isl_ast_loop_type res =  isl_schedule_node_band_member_get_isolate_ast_loop_type((*this).Get(), pos);
  ctx.unlock();
  return res;
}

inline ScheduleNode ScheduleNode::bandMemberSetAstLoopType(int pos, enum isl_ast_loop_type type) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_member_set_ast_loop_type((*this).GetCopy(), pos, type);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_member_set_ast_loop_type returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandMemberSetCoincident(int pos, int coincident) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_member_set_coincident((*this).GetCopy(), pos, coincident);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_member_set_coincident returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandMemberSetIsolateAstLoopType(int pos, enum isl_ast_loop_type type) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_member_set_isolate_ast_loop_type((*this).GetCopy(), pos, type);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_member_set_isolate_ast_loop_type returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandMod(const MultiVal &mv) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_mod((*this).GetCopy(), (mv).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_mod returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline unsigned int ScheduleNode::bandNMember() const {
  ctx.lock();
  unsigned int res =  isl_schedule_node_band_n_member((*this).Get());
  ctx.unlock();
  return res;
}

inline ScheduleNode ScheduleNode::bandScale(const MultiVal &mv) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_scale((*this).GetCopy(), (mv).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_scale returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandScaleDown(const MultiVal &mv) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_scale_down((*this).GetCopy(), (mv).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_scale_down returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandSetAstBuildOptions(const UnionSet &options) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_set_ast_build_options((*this).GetCopy(), (options).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_set_ast_build_options returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandSetPermutable(int permutable) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_set_permutable((*this).GetCopy(), permutable);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_set_permutable returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandShift(const MultiUnionPwAff &shift) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_shift((*this).GetCopy(), (shift).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_shift returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandSink() const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_sink((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_sink returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandSplit(int pos) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_split((*this).GetCopy(), pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_split returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::bandTile(const MultiVal &sizes) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_band_tile((*this).GetCopy(), (sizes).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_band_tile returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::child(int pos) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_child((*this).GetCopy(), pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_child returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline Set ScheduleNode::contextGetContext() const {
  ctx.lock();
  isl_set * res =  isl_schedule_node_context_get_context((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_context_get_context returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline ScheduleNode ScheduleNode::copy() const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_copy((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_copy returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::cut() const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_cut((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_cut returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::delete_() const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_delete((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_delete returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline UnionSet ScheduleNode::domainGetDomain() const {
  ctx.lock();
  isl_union_set * res =  isl_schedule_node_domain_get_domain((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_domain_get_domain returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline void ScheduleNode::dump() const {
  ctx.lock();
   isl_schedule_node_dump((*this).Get());
  ctx.unlock();
}

inline UnionPwMultiAff ScheduleNode::expansionGetContraction() const {
  ctx.lock();
  isl_union_pw_multi_aff * res =  isl_schedule_node_expansion_get_contraction((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_expansion_get_contraction returned a NULL pointer.");
  }
  return UnionPwMultiAff(ctx, res);
}

inline UnionMap ScheduleNode::expansionGetExpansion() const {
  ctx.lock();
  isl_union_map * res =  isl_schedule_node_expansion_get_expansion((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_expansion_get_expansion returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap ScheduleNode::extensionGetExtension() const {
  ctx.lock();
  isl_union_map * res =  isl_schedule_node_extension_get_extension((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_extension_get_extension returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionSet ScheduleNode::filterGetFilter() const {
  ctx.lock();
  isl_union_set * res =  isl_schedule_node_filter_get_filter((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_filter_get_filter returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline ScheduleNode ScheduleNode::firstChild() const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_first_child((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_first_child returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline Stat ScheduleNode::foreachAncestorTopDown(const std::function<isl_stat(isl_schedule_node *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_schedule_node_foreach_ancestor_top_down((*this).Get(), get_fn_ptr<15>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline Stat ScheduleNode::foreachDescendantTopDown(const std::function<isl_bool(isl_schedule_node *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_stat res =  isl_schedule_node_foreach_descendant_top_down((*this).Get(), get_fn_ptr<16>(fn), user);
  ctx.unlock();
  return (Stat)res;
}

inline int ScheduleNode::getAncestorChildPosition(const ScheduleNode &ancestor) const {
  ctx.lock();
  int res =  isl_schedule_node_get_ancestor_child_position((*this).Get(), (ancestor).Get());
  ctx.unlock();
  return res;
}

inline ScheduleNode ScheduleNode::getChild(int pos) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_get_child((*this).Get(), pos);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_child returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline int ScheduleNode::getChildPosition() const {
  ctx.lock();
  int res =  isl_schedule_node_get_child_position((*this).Get());
  ctx.unlock();
  return res;
}

inline ScheduleNodeType ScheduleNode::getParentType() const {
  ctx.lock();
  enum isl_schedule_node_type res =  isl_schedule_node_get_parent_type((*this).Get());
  ctx.unlock();
  return (ScheduleNodeType)res;
}

inline MultiUnionPwAff ScheduleNode::getPrefixScheduleMultiUnionPwAff() const {
  ctx.lock();
  isl_multi_union_pw_aff * res =  isl_schedule_node_get_prefix_schedule_multi_union_pw_aff((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_prefix_schedule_multi_union_pw_aff returned a NULL pointer.");
  }
  return MultiUnionPwAff(ctx, res);
}

inline UnionMap ScheduleNode::getPrefixScheduleRelation() const {
  ctx.lock();
  isl_union_map * res =  isl_schedule_node_get_prefix_schedule_relation((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_prefix_schedule_relation returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap ScheduleNode::getPrefixScheduleUnionMap() const {
  ctx.lock();
  isl_union_map * res =  isl_schedule_node_get_prefix_schedule_union_map((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_prefix_schedule_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionPwMultiAff ScheduleNode::getPrefixScheduleUnionPwMultiAff() const {
  ctx.lock();
  isl_union_pw_multi_aff * res =  isl_schedule_node_get_prefix_schedule_union_pw_multi_aff((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_prefix_schedule_union_pw_multi_aff returned a NULL pointer.");
  }
  return UnionPwMultiAff(ctx, res);
}

inline Schedule ScheduleNode::getSchedule() const {
  ctx.lock();
  isl_schedule * res =  isl_schedule_node_get_schedule((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_schedule returned a NULL pointer.");
  }
  return Schedule(ctx, res);
}

inline int ScheduleNode::getScheduleDepth() const {
  ctx.lock();
  int res =  isl_schedule_node_get_schedule_depth((*this).Get());
  ctx.unlock();
  return res;
}

inline ScheduleNode ScheduleNode::getSharedAncestor(const ScheduleNode &node2) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_get_shared_ancestor((*this).Get(), (node2).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_shared_ancestor returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline UnionPwMultiAff ScheduleNode::getSubtreeContraction() const {
  ctx.lock();
  isl_union_pw_multi_aff * res =  isl_schedule_node_get_subtree_contraction((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_subtree_contraction returned a NULL pointer.");
  }
  return UnionPwMultiAff(ctx, res);
}

inline UnionMap ScheduleNode::getSubtreeExpansion() const {
  ctx.lock();
  isl_union_map * res =  isl_schedule_node_get_subtree_expansion((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_subtree_expansion returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline UnionMap ScheduleNode::getSubtreeScheduleUnionMap() const {
  ctx.lock();
  isl_union_map * res =  isl_schedule_node_get_subtree_schedule_union_map((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_subtree_schedule_union_map returned a NULL pointer.");
  }
  return UnionMap(ctx, res);
}

inline int ScheduleNode::getTreeDepth() const {
  ctx.lock();
  int res =  isl_schedule_node_get_tree_depth((*this).Get());
  ctx.unlock();
  return res;
}

inline ScheduleNodeType ScheduleNode::getType() const {
  ctx.lock();
  enum isl_schedule_node_type res =  isl_schedule_node_get_type((*this).Get());
  ctx.unlock();
  return (ScheduleNodeType)res;
}

inline UnionSet ScheduleNode::getUniverseDomain() const {
  ctx.lock();
  isl_union_set * res =  isl_schedule_node_get_universe_domain((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_get_universe_domain returned a NULL pointer.");
  }
  return UnionSet(ctx, res);
}

inline ScheduleNode ScheduleNode::graftAfter(const ScheduleNode &graft) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_graft_after((*this).GetCopy(), (graft).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_graft_after returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::graftBefore(const ScheduleNode &graft) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_graft_before((*this).GetCopy(), (graft).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_graft_before returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::group(const Id &group_id) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_group((*this).GetCopy(), (group_id).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_group returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline Set ScheduleNode::guardGetGuard() const {
  ctx.lock();
  isl_set * res =  isl_schedule_node_guard_get_guard((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_guard_get_guard returned a NULL pointer.");
  }
  return Set(ctx, res);
}

inline Bool ScheduleNode::hasChildren() const {
  ctx.lock();
  isl_bool res =  isl_schedule_node_has_children((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool ScheduleNode::hasNextSibling() const {
  ctx.lock();
  isl_bool res =  isl_schedule_node_has_next_sibling((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool ScheduleNode::hasParent() const {
  ctx.lock();
  isl_bool res =  isl_schedule_node_has_parent((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool ScheduleNode::hasPreviousSibling() const {
  ctx.lock();
  isl_bool res =  isl_schedule_node_has_previous_sibling((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline ScheduleNode ScheduleNode::insertContext(const Set &context) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_insert_context((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_context returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertFilter(const UnionSet &filter) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_insert_filter((*this).GetCopy(), (filter).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_filter returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertGuard(const Set &context) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_insert_guard((*this).GetCopy(), (context).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_guard returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertMark(const Id &mark) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_insert_mark((*this).GetCopy(), (mark).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_mark returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertPartialSchedule(const MultiUnionPwAff &schedule) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_insert_partial_schedule((*this).GetCopy(), (schedule).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_partial_schedule returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertSequence(const UnionSetList &filters) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_insert_sequence((*this).GetCopy(), (filters).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_sequence returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::insertSet(const UnionSetList &filters) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_insert_set((*this).GetCopy(), (filters).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_insert_set returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline Bool ScheduleNode::isEqual(const ScheduleNode &node2) const {
  ctx.lock();
  isl_bool res =  isl_schedule_node_is_equal((*this).Get(), (node2).Get());
  ctx.unlock();
  return (Bool)res;
}

inline Bool ScheduleNode::isSubtreeAnchored() const {
  ctx.lock();
  isl_bool res =  isl_schedule_node_is_subtree_anchored((*this).Get());
  ctx.unlock();
  return (Bool)res;
}

inline ScheduleNode ScheduleNode::mapDescendantBottomUp(const std::function<isl_schedule_node *(isl_schedule_node *, void *)> && fn, void * user) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_map_descendant_bottom_up((*this).GetCopy(), get_fn_ptr<17>(fn), user);
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_map_descendant_bottom_up returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline Id ScheduleNode::markGetId() const {
  ctx.lock();
  isl_id * res =  isl_schedule_node_mark_get_id((*this).Get());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_mark_get_id returned a NULL pointer.");
  }
  return Id(ctx, res);
}

inline int ScheduleNode::nChildren() const {
  ctx.lock();
  int res =  isl_schedule_node_n_children((*this).Get());
  ctx.unlock();
  return res;
}

inline ScheduleNode ScheduleNode::nextSibling() const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_next_sibling((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_next_sibling returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::orderAfter(const UnionSet &filter) const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_order_after((*this).GetCopy(), (filter).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_order_after returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::parent() const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_parent((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_parent returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::previousSibling() const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_previous_sibling((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_previous_sibling returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::resetUser() const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_reset_user((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_reset_user returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

inline ScheduleNode ScheduleNode::root() const {
  ctx.lock();
  isl_schedule_node * res =  isl_schedule_node_root((*this).GetCopy());
  ctx.unlock();
  if (ctx.hasError()) {
    handleError("isl_schedule_node_root returned a NULL pointer.");
  }
  return ScheduleNode(ctx, res);
}

} // namespace isl
#endif //ISL_CXX_ScheduleNode_IMPL_H
