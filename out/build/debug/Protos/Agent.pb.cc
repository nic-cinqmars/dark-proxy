// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: Agent.proto
// Protobuf C++ Version: 5.29.0-dev

#include "Agent.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace DC {
namespace Packet {

inline constexpr Agent_ServiceList::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : ipaddress_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        port_{0u},
        processid_{0u},
        usercount_{0u},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Agent_ServiceList::Agent_ServiceList(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct Agent_ServiceListDefaultTypeInternal {
  PROTOBUF_CONSTEXPR Agent_ServiceListDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~Agent_ServiceListDefaultTypeInternal() {}
  union {
    Agent_ServiceList _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 Agent_ServiceListDefaultTypeInternal _Agent_ServiceList_default_instance_;
}  // namespace Packet
}  // namespace DC
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_Agent_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_Agent_2eproto = nullptr;
const ::uint32_t
    TableStruct_Agent_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::DC::Packet::Agent_ServiceList, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::DC::Packet::Agent_ServiceList, _impl_.ipaddress_),
        PROTOBUF_FIELD_OFFSET(::DC::Packet::Agent_ServiceList, _impl_.port_),
        PROTOBUF_FIELD_OFFSET(::DC::Packet::Agent_ServiceList, _impl_.processid_),
        PROTOBUF_FIELD_OFFSET(::DC::Packet::Agent_ServiceList, _impl_.usercount_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::DC::Packet::Agent_ServiceList)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::DC::Packet::_Agent_ServiceList_default_instance_._instance,
};
const char descriptor_table_protodef_Agent_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\013Agent.proto\022\tDC.Packet\"Z\n\021Agent_Servic"
    "eList\022\021\n\tipAddress\030\001 \001(\t\022\014\n\004port\030\002 \001(\r\022\021"
    "\n\tprocessId\030\003 \001(\r\022\021\n\tuserCount\030\004 \001(\rB\034\n\021"
    "com.packets.agentB\005agentP\000b\006proto3"
};
static ::absl::once_flag descriptor_table_Agent_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_Agent_2eproto = {
    false,
    false,
    154,
    descriptor_table_protodef_Agent_2eproto,
    "Agent.proto",
    &descriptor_table_Agent_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_Agent_2eproto::offsets,
    file_level_enum_descriptors_Agent_2eproto,
    file_level_service_descriptors_Agent_2eproto,
};
namespace DC {
namespace Packet {
// ===================================================================

class Agent_ServiceList::_Internal {
 public:
};

Agent_ServiceList::Agent_ServiceList(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:DC.Packet.Agent_ServiceList)
}
inline PROTOBUF_NDEBUG_INLINE Agent_ServiceList::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::DC::Packet::Agent_ServiceList& from_msg)
      : ipaddress_(arena, from.ipaddress_),
        _cached_size_{0} {}

Agent_ServiceList::Agent_ServiceList(
    ::google::protobuf::Arena* arena,
    const Agent_ServiceList& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  Agent_ServiceList* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, port_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, port_),
           offsetof(Impl_, usercount_) -
               offsetof(Impl_, port_) +
               sizeof(Impl_::usercount_));

  // @@protoc_insertion_point(copy_constructor:DC.Packet.Agent_ServiceList)
}
inline PROTOBUF_NDEBUG_INLINE Agent_ServiceList::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : ipaddress_(arena),
        _cached_size_{0} {}

inline void Agent_ServiceList::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, port_),
           0,
           offsetof(Impl_, usercount_) -
               offsetof(Impl_, port_) +
               sizeof(Impl_::usercount_));
}
Agent_ServiceList::~Agent_ServiceList() {
  // @@protoc_insertion_point(destructor:DC.Packet.Agent_ServiceList)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Agent_ServiceList::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.ipaddress_.Destroy();
  _impl_.~Impl_();
}

PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::MessageLite::ClassDataFull
    Agent_ServiceList::_class_data_ = {
        ::google::protobuf::Message::ClassData{
            &_Agent_ServiceList_default_instance_._instance,
            &_table_.header,
            nullptr,  // OnDemandRegisterArenaDtor
            nullptr,  // IsInitialized
            &Agent_ServiceList::MergeImpl,
#if defined(PROTOBUF_CUSTOM_VTABLE)
            ::google::protobuf::Message::GetDeleteImpl<Agent_ServiceList>(),
            ::google::protobuf::Message::GetNewImpl<Agent_ServiceList>(),
            ::google::protobuf::Message::GetClearImpl<Agent_ServiceList>(), &Agent_ServiceList::ByteSizeLong,
                &Agent_ServiceList::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
            PROTOBUF_FIELD_OFFSET(Agent_ServiceList, _impl_._cached_size_),
            false,
        },
        &Agent_ServiceList::kDescriptorMethods,
        &descriptor_table_Agent_2eproto,
        nullptr,  // tracker
};
const ::google::protobuf::MessageLite::ClassData* Agent_ServiceList::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 4, 0, 45, 2> Agent_ServiceList::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    4, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967280,  // skipmap
    offsetof(decltype(_table_), field_entries),
    4,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::DC::Packet::Agent_ServiceList>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // uint32 userCount = 4;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Agent_ServiceList, _impl_.usercount_), 63>(),
     {32, 63, 0, PROTOBUF_FIELD_OFFSET(Agent_ServiceList, _impl_.usercount_)}},
    // string ipAddress = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Agent_ServiceList, _impl_.ipaddress_)}},
    // uint32 port = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Agent_ServiceList, _impl_.port_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(Agent_ServiceList, _impl_.port_)}},
    // uint32 processId = 3;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Agent_ServiceList, _impl_.processid_), 63>(),
     {24, 63, 0, PROTOBUF_FIELD_OFFSET(Agent_ServiceList, _impl_.processid_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string ipAddress = 1;
    {PROTOBUF_FIELD_OFFSET(Agent_ServiceList, _impl_.ipaddress_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // uint32 port = 2;
    {PROTOBUF_FIELD_OFFSET(Agent_ServiceList, _impl_.port_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt32)},
    // uint32 processId = 3;
    {PROTOBUF_FIELD_OFFSET(Agent_ServiceList, _impl_.processid_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt32)},
    // uint32 userCount = 4;
    {PROTOBUF_FIELD_OFFSET(Agent_ServiceList, _impl_.usercount_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt32)},
  }},
  // no aux_entries
  {{
    "\33\11\0\0\0\0\0\0"
    "DC.Packet.Agent_ServiceList"
    "ipAddress"
  }},
};

PROTOBUF_NOINLINE void Agent_ServiceList::Clear() {
// @@protoc_insertion_point(message_clear_start:DC.Packet.Agent_ServiceList)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.ipaddress_.ClearToEmpty();
  ::memset(&_impl_.port_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.usercount_) -
      reinterpret_cast<char*>(&_impl_.port_)) + sizeof(_impl_.usercount_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* Agent_ServiceList::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const Agent_ServiceList& this_ = static_cast<const Agent_ServiceList&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* Agent_ServiceList::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const Agent_ServiceList& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:DC.Packet.Agent_ServiceList)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // string ipAddress = 1;
          if (!this_._internal_ipaddress().empty()) {
            const std::string& _s = this_._internal_ipaddress();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "DC.Packet.Agent_ServiceList.ipAddress");
            target = stream->WriteStringMaybeAliased(1, _s, target);
          }

          // uint32 port = 2;
          if (this_._internal_port() != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteUInt32ToArray(
                2, this_._internal_port(), target);
          }

          // uint32 processId = 3;
          if (this_._internal_processid() != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteUInt32ToArray(
                3, this_._internal_processid(), target);
          }

          // uint32 userCount = 4;
          if (this_._internal_usercount() != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteUInt32ToArray(
                4, this_._internal_usercount(), target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:DC.Packet.Agent_ServiceList)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t Agent_ServiceList::ByteSizeLong(const MessageLite& base) {
          const Agent_ServiceList& this_ = static_cast<const Agent_ServiceList&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t Agent_ServiceList::ByteSizeLong() const {
          const Agent_ServiceList& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:DC.Packet.Agent_ServiceList)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // string ipAddress = 1;
            if (!this_._internal_ipaddress().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_ipaddress());
            }
            // uint32 port = 2;
            if (this_._internal_port() != 0) {
              total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(
                  this_._internal_port());
            }
            // uint32 processId = 3;
            if (this_._internal_processid() != 0) {
              total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(
                  this_._internal_processid());
            }
            // uint32 userCount = 4;
            if (this_._internal_usercount() != 0) {
              total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(
                  this_._internal_usercount());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void Agent_ServiceList::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Agent_ServiceList*>(&to_msg);
  auto& from = static_cast<const Agent_ServiceList&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:DC.Packet.Agent_ServiceList)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_ipaddress().empty()) {
    _this->_internal_set_ipaddress(from._internal_ipaddress());
  }
  if (from._internal_port() != 0) {
    _this->_impl_.port_ = from._impl_.port_;
  }
  if (from._internal_processid() != 0) {
    _this->_impl_.processid_ = from._impl_.processid_;
  }
  if (from._internal_usercount() != 0) {
    _this->_impl_.usercount_ = from._impl_.usercount_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Agent_ServiceList::CopyFrom(const Agent_ServiceList& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:DC.Packet.Agent_ServiceList)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Agent_ServiceList::InternalSwap(Agent_ServiceList* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.ipaddress_, &other->_impl_.ipaddress_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Agent_ServiceList, _impl_.usercount_)
      + sizeof(Agent_ServiceList::_impl_.usercount_)
      - PROTOBUF_FIELD_OFFSET(Agent_ServiceList, _impl_.port_)>(
          reinterpret_cast<char*>(&_impl_.port_),
          reinterpret_cast<char*>(&other->_impl_.port_));
}

::google::protobuf::Metadata Agent_ServiceList::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace Packet
}  // namespace DC
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_Agent_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"