#ifndef ISL_CXX_ScheduleNode_H
#define ISL_CXX_ScheduleNode_H


#include "isl/schedule_node.h"
#include "isl/Bool.h"
#include "isl/Format.h"
#include "isl/IslBase.h"
#include "isl/IslException.h"
#include "isl/ScheduleNodeType.h"
#include "isl/Stat.h"
#include <string>

#include "isl/IslFnPtr.h"

namespace isl {
class Id;
class MultiUnionPwAff;
class MultiVal;
class Schedule;
class Set;
class Space;
class UnionMap;
class UnionPwMultiAff;
class UnionSet;
class UnionSetList;

class ScheduleNode {
protected:
  Ctx ctx;
  void * This;
public:
  explicit ScheduleNode(Ctx ctx, isl_schedule_node *That) : ctx(ctx), This(That) {}

  const Ctx &Context() const { return ctx; }

  __isl_give isl_schedule_node *GetCopy() const;
  /// \brief Release ownership of the wrapped object.
  ///
  /// You are on your own now buddy.
  /// The wrapper cannot be used anymore after calling Give()
  ///
  /// \returns the wrapped isl object.
  __isl_give isl_schedule_node *Give();
  /// \brief unwrap the stored isl object.
  /// \return a the wrapped isl object.
  __isl_give isl_schedule_node *Get() const;


  /// \brief Constructor for isl_schedule_node_from_domain
  ///
  /// \param domain
  static ScheduleNode fromDomain(const UnionSet &domain);


  /// \brief Constructor for isl_schedule_node_from_extension
  ///
  /// \param extension
  static ScheduleNode fromExtension(const UnionMap &extension);
public:
  virtual ~ScheduleNode();
  /// \brief Generated from  ::<isl_schedule_node_align_params>
  ///
  /// \param [in] space
  ///
  /// \returns A new ScheduleNode
  ScheduleNode alignParams(const Space &space) const;

  /// \brief Generated from  ::<isl_schedule_node_ancestor>
  ///
  /// \param [in] generation
  ///
  /// \returns A new ScheduleNode
  ScheduleNode ancestor(int generation) const;

  /// \brief Generated from  ::<isl_schedule_node_band_get_ast_build_options>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet bandGetAstBuildOptions() const;

  /// \brief Generated from  ::<isl_schedule_node_band_get_partial_schedule>
  ///
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff bandGetPartialSchedule() const;

  /// \brief Generated from  ::<isl_schedule_node_band_get_partial_schedule_union_map>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap bandGetPartialScheduleUnionMap() const;

  /// \brief Generated from  ::<isl_schedule_node_band_get_permutable>
  ///
  ///
  /// \returns A new Bool
  Bool bandGetPermutable() const;

  /// \brief Generated from  ::<isl_schedule_node_band_get_space>
  ///
  ///
  /// \returns A new Space
  Space bandGetSpace() const;

  /// \brief Generated from  ::<isl_schedule_node_band_member_get_ast_loop_type>
  ///
  /// \param [in] pos
  ///
  /// \returns A new enum isl_ast_loop_type
  enum isl_ast_loop_type bandMemberGetAstLoopType(int pos) const;

  /// \brief Generated from  ::<isl_schedule_node_band_member_get_coincident>
  ///
  /// \param [in] pos
  ///
  /// \returns A new Bool
  Bool bandMemberGetCoincident(int pos) const;

  /// \brief Generated from  ::<isl_schedule_node_band_member_get_isolate_ast_loop_type>
  ///
  /// \param [in] pos
  ///
  /// \returns A new enum isl_ast_loop_type
  enum isl_ast_loop_type bandMemberGetIsolateAstLoopType(int pos) const;

  /// \brief Generated from  ::<isl_schedule_node_band_member_set_ast_loop_type>
  ///
  /// \param [in] pos
  /// \param [in] type
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandMemberSetAstLoopType(int pos, enum isl_ast_loop_type type) const;

  /// \brief Generated from  ::<isl_schedule_node_band_member_set_coincident>
  ///
  /// \param [in] pos
  /// \param [in] coincident
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandMemberSetCoincident(int pos, int coincident) const;

  /// \brief Generated from  ::<isl_schedule_node_band_member_set_isolate_ast_loop_type>
  ///
  /// \param [in] pos
  /// \param [in] type
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandMemberSetIsolateAstLoopType(int pos, enum isl_ast_loop_type type) const;

  /// \brief Generated from  ::<isl_schedule_node_band_mod>
  ///
  /// \param [in] mv
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandMod(const MultiVal &mv) const;

  /// \brief Generated from  ::<isl_schedule_node_band_n_member>
  ///
  ///
  /// \returns A new unsigned int
  unsigned int bandNMember() const;

  /// \brief Generated from  ::<isl_schedule_node_band_scale>
  ///
  /// \param [in] mv
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandScale(const MultiVal &mv) const;

  /// \brief Generated from  ::<isl_schedule_node_band_scale_down>
  ///
  /// \param [in] mv
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandScaleDown(const MultiVal &mv) const;

  /// \brief Generated from  ::<isl_schedule_node_band_set_ast_build_options>
  ///
  /// \param [in] options
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandSetAstBuildOptions(const UnionSet &options) const;

  /// \brief Generated from  ::<isl_schedule_node_band_set_permutable>
  ///
  /// \param [in] permutable
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandSetPermutable(int permutable) const;

  /// \brief Generated from  ::<isl_schedule_node_band_shift>
  ///
  /// \param [in] shift
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandShift(const MultiUnionPwAff &shift) const;

  /// \brief Generated from  ::<isl_schedule_node_band_sink>
  ///
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandSink() const;

  /// \brief Generated from  ::<isl_schedule_node_band_split>
  ///
  /// \param [in] pos
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandSplit(int pos) const;

  /// \brief Generated from  ::<isl_schedule_node_band_tile>
  ///
  /// \param [in] sizes
  ///
  /// \returns A new ScheduleNode
  ScheduleNode bandTile(const MultiVal &sizes) const;

  /// \brief Generated from  ::<isl_schedule_node_child>
  ///
  /// \param [in] pos
  ///
  /// \returns A new ScheduleNode
  ScheduleNode child(int pos) const;

  /// \brief Generated from  ::<isl_schedule_node_context_get_context>
  ///
  ///
  /// \returns A new Set
  Set contextGetContext() const;

  /// \brief Generated from  ::<isl_schedule_node_copy>
  ///
  ///
  /// \returns A new ScheduleNode
  ScheduleNode copy() const;

  /// \brief Generated from  ::<isl_schedule_node_cut>
  ///
  ///
  /// \returns A new ScheduleNode
  ScheduleNode cut() const;

  /// \brief Generated from  ::<isl_schedule_node_delete>
  ///
  ///
  /// \returns A new ScheduleNode
  ScheduleNode delete_() const;

  /// \brief Generated from  ::<isl_schedule_node_domain_get_domain>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet domainGetDomain() const;

  /// \brief Generated from  ::<isl_schedule_node_dump>
  ///
  ///
  /// \returns A new void
  void dump() const;

  /// \brief Generated from  ::<isl_schedule_node_expansion_get_contraction>
  ///
  ///
  /// \returns A new UnionPwMultiAff
  UnionPwMultiAff expansionGetContraction() const;

  /// \brief Generated from  ::<isl_schedule_node_expansion_get_expansion>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap expansionGetExpansion() const;

  /// \brief Generated from  ::<isl_schedule_node_extension_get_extension>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap extensionGetExtension() const;

  /// \brief Generated from  ::<isl_schedule_node_filter_get_filter>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet filterGetFilter() const;

  /// \brief Generated from  ::<isl_schedule_node_first_child>
  ///
  ///
  /// \returns A new ScheduleNode
  ScheduleNode firstChild() const;

  /// \brief Generated from  ::<isl_schedule_node_foreach_ancestor_top_down>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachAncestorTopDown(const std::function<isl_stat(isl_schedule_node *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_schedule_node_foreach_descendant_top_down>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new Stat
  Stat foreachDescendantTopDown(const std::function<isl_bool(isl_schedule_node *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_schedule_node_get_ancestor_child_position>
  ///
  /// \param [in] ancestor
  ///
  /// \returns A new int
  int getAncestorChildPosition(const ScheduleNode &ancestor) const;

  /// \brief Generated from  ::<isl_schedule_node_get_child>
  ///
  /// \param [in] pos
  ///
  /// \returns A new ScheduleNode
  ScheduleNode getChild(int pos) const;

  /// \brief Generated from  ::<isl_schedule_node_get_child_position>
  ///
  ///
  /// \returns A new int
  int getChildPosition() const;

  /// \brief Generated from  ::<isl_schedule_node_get_parent_type>
  ///
  ///
  /// \returns A new ScheduleNodeType
  ScheduleNodeType getParentType() const;

  /// \brief Generated from  ::<isl_schedule_node_get_prefix_schedule_multi_union_pw_aff>
  ///
  ///
  /// \returns A new MultiUnionPwAff
  MultiUnionPwAff getPrefixScheduleMultiUnionPwAff() const;

  /// \brief Generated from  ::<isl_schedule_node_get_prefix_schedule_relation>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getPrefixScheduleRelation() const;

  /// \brief Generated from  ::<isl_schedule_node_get_prefix_schedule_union_map>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getPrefixScheduleUnionMap() const;

  /// \brief Generated from  ::<isl_schedule_node_get_prefix_schedule_union_pw_multi_aff>
  ///
  ///
  /// \returns A new UnionPwMultiAff
  UnionPwMultiAff getPrefixScheduleUnionPwMultiAff() const;

  /// \brief Generated from  ::<isl_schedule_node_get_schedule>
  ///
  ///
  /// \returns A new Schedule
  Schedule getSchedule() const;

  /// \brief Generated from  ::<isl_schedule_node_get_schedule_depth>
  ///
  ///
  /// \returns A new int
  int getScheduleDepth() const;

  /// \brief Generated from  ::<isl_schedule_node_get_shared_ancestor>
  ///
  /// \param [in] node2
  ///
  /// \returns A new ScheduleNode
  ScheduleNode getSharedAncestor(const ScheduleNode &node2) const;

  /// \brief Generated from  ::<isl_schedule_node_get_subtree_contraction>
  ///
  ///
  /// \returns A new UnionPwMultiAff
  UnionPwMultiAff getSubtreeContraction() const;

  /// \brief Generated from  ::<isl_schedule_node_get_subtree_expansion>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getSubtreeExpansion() const;

  /// \brief Generated from  ::<isl_schedule_node_get_subtree_schedule_union_map>
  ///
  ///
  /// \returns A new UnionMap
  UnionMap getSubtreeScheduleUnionMap() const;

  /// \brief Generated from  ::<isl_schedule_node_get_tree_depth>
  ///
  ///
  /// \returns A new int
  int getTreeDepth() const;

  /// \brief Generated from  ::<isl_schedule_node_get_type>
  ///
  ///
  /// \returns A new ScheduleNodeType
  ScheduleNodeType getType() const;

  /// \brief Generated from  ::<isl_schedule_node_get_universe_domain>
  ///
  ///
  /// \returns A new UnionSet
  UnionSet getUniverseDomain() const;

  /// \brief Generated from  ::<isl_schedule_node_graft_after>
  ///
  /// \param [in] graft
  ///
  /// \returns A new ScheduleNode
  ScheduleNode graftAfter(const ScheduleNode &graft) const;

  /// \brief Generated from  ::<isl_schedule_node_graft_before>
  ///
  /// \param [in] graft
  ///
  /// \returns A new ScheduleNode
  ScheduleNode graftBefore(const ScheduleNode &graft) const;

  /// \brief Generated from  ::<isl_schedule_node_group>
  ///
  /// \param [in] group_id
  ///
  /// \returns A new ScheduleNode
  ScheduleNode group(const Id &group_id) const;

  /// \brief Generated from  ::<isl_schedule_node_guard_get_guard>
  ///
  ///
  /// \returns A new Set
  Set guardGetGuard() const;

  /// \brief Generated from  ::<isl_schedule_node_has_children>
  ///
  ///
  /// \returns A new Bool
  Bool hasChildren() const;

  /// \brief Generated from  ::<isl_schedule_node_has_next_sibling>
  ///
  ///
  /// \returns A new Bool
  Bool hasNextSibling() const;

  /// \brief Generated from  ::<isl_schedule_node_has_parent>
  ///
  ///
  /// \returns A new Bool
  Bool hasParent() const;

  /// \brief Generated from  ::<isl_schedule_node_has_previous_sibling>
  ///
  ///
  /// \returns A new Bool
  Bool hasPreviousSibling() const;

  /// \brief Generated from  ::<isl_schedule_node_insert_context>
  ///
  /// \param [in] context
  ///
  /// \returns A new ScheduleNode
  ScheduleNode insertContext(const Set &context) const;

  /// \brief Generated from  ::<isl_schedule_node_insert_filter>
  ///
  /// \param [in] filter
  ///
  /// \returns A new ScheduleNode
  ScheduleNode insertFilter(const UnionSet &filter) const;

  /// \brief Generated from  ::<isl_schedule_node_insert_guard>
  ///
  /// \param [in] context
  ///
  /// \returns A new ScheduleNode
  ScheduleNode insertGuard(const Set &context) const;

  /// \brief Generated from  ::<isl_schedule_node_insert_mark>
  ///
  /// \param [in] mark
  ///
  /// \returns A new ScheduleNode
  ScheduleNode insertMark(const Id &mark) const;

  /// \brief Generated from  ::<isl_schedule_node_insert_partial_schedule>
  ///
  /// \param [in] schedule
  ///
  /// \returns A new ScheduleNode
  ScheduleNode insertPartialSchedule(const MultiUnionPwAff &schedule) const;

  /// \brief Generated from  ::<isl_schedule_node_insert_sequence>
  ///
  /// \param [in] filters
  ///
  /// \returns A new ScheduleNode
  ScheduleNode insertSequence(const UnionSetList &filters) const;

  /// \brief Generated from  ::<isl_schedule_node_insert_set>
  ///
  /// \param [in] filters
  ///
  /// \returns A new ScheduleNode
  ScheduleNode insertSet(const UnionSetList &filters) const;

  /// \brief Generated from  ::<isl_schedule_node_is_equal>
  ///
  /// \param [in] node2
  ///
  /// \returns A new Bool
  Bool isEqual(const ScheduleNode &node2) const;

  /// \brief Generated from  ::<isl_schedule_node_is_subtree_anchored>
  ///
  ///
  /// \returns A new Bool
  Bool isSubtreeAnchored() const;

  /// \brief Generated from  ::<isl_schedule_node_map_descendant_bottom_up>
  ///
  /// \param [in] fn
  /// \param [in] user
  ///
  /// \returns A new ScheduleNode
  ScheduleNode mapDescendantBottomUp(const std::function<isl_schedule_node *(isl_schedule_node *, void *)> && fn, void * user) const;

  /// \brief Generated from  ::<isl_schedule_node_mark_get_id>
  ///
  ///
  /// \returns A new Id
  Id markGetId() const;

  /// \brief Generated from  ::<isl_schedule_node_n_children>
  ///
  ///
  /// \returns A new int
  int nChildren() const;

  /// \brief Generated from  ::<isl_schedule_node_next_sibling>
  ///
  ///
  /// \returns A new ScheduleNode
  ScheduleNode nextSibling() const;

  /// \brief Generated from  ::<isl_schedule_node_order_after>
  ///
  /// \param [in] filter
  ///
  /// \returns A new ScheduleNode
  ScheduleNode orderAfter(const UnionSet &filter) const;

  /// \brief Generated from  ::<isl_schedule_node_parent>
  ///
  ///
  /// \returns A new ScheduleNode
  ScheduleNode parent() const;

  /// \brief Generated from  ::<isl_schedule_node_previous_sibling>
  ///
  ///
  /// \returns A new ScheduleNode
  ScheduleNode previousSibling() const;

  /// \brief Generated from  ::<isl_schedule_node_reset_user>
  ///
  ///
  /// \returns A new ScheduleNode
  ScheduleNode resetUser() const;

  /// \brief Generated from  ::<isl_schedule_node_root>
  ///
  ///
  /// \returns A new ScheduleNode
  ScheduleNode root() const;

  /// \brief Generated from  ::<isl_schedule_node_to_str>
  ///
  ///
  /// \returns A new std::string
  std::string toStr() const;

  ScheduleNode(const ScheduleNode &Other) : ctx(Other.Context()), This(Other.GetCopy()) {}
  ScheduleNode &operator=(const ScheduleNode &Other);
  ScheduleNode (ScheduleNode && Other) : ctx(Other.Context()), This(Other.Give()) {}
  ScheduleNode &operator=(ScheduleNode && Other) {
    isl_schedule_node *New = Other.Give();
    isl_schedule_node_free((isl_schedule_node *)This);
    This = New;
    return *this;
  }
  /// \brief Implement lt via pointer comparison of the
  ///         wrapped isl objects.
  bool operator<(const ScheduleNode &RHS) const { return This < RHS.This; }

};
} // namespace isl
#endif //ISL_CXX_ScheduleNode_H
