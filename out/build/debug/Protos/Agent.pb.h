// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: Agent.proto
// Protobuf C++ Version: 5.29.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_Agent_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_Agent_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5029000
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_Agent_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_Agent_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_Agent_2eproto;
namespace DC {
namespace Packet {
class Agent_ServiceList;
struct Agent_ServiceListDefaultTypeInternal;
extern Agent_ServiceListDefaultTypeInternal _Agent_ServiceList_default_instance_;
}  // namespace Packet
}  // namespace DC
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace DC {
namespace Packet {

// ===================================================================


// -------------------------------------------------------------------

class Agent_ServiceList final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:DC.Packet.Agent_ServiceList) */ {
 public:
  inline Agent_ServiceList() : Agent_ServiceList(nullptr) {}
  ~Agent_ServiceList() PROTOBUF_FINAL;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Agent_ServiceList(
      ::google::protobuf::internal::ConstantInitialized);

  inline Agent_ServiceList(const Agent_ServiceList& from) : Agent_ServiceList(nullptr, from) {}
  inline Agent_ServiceList(Agent_ServiceList&& from) noexcept
      : Agent_ServiceList(nullptr, std::move(from)) {}
  inline Agent_ServiceList& operator=(const Agent_ServiceList& from) {
    CopyFrom(from);
    return *this;
  }
  inline Agent_ServiceList& operator=(Agent_ServiceList&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Agent_ServiceList& default_instance() {
    return *internal_default_instance();
  }
  static inline const Agent_ServiceList* internal_default_instance() {
    return reinterpret_cast<const Agent_ServiceList*>(
        &_Agent_ServiceList_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Agent_ServiceList& a, Agent_ServiceList& b) { a.Swap(&b); }
  inline void Swap(Agent_ServiceList* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Agent_ServiceList* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Agent_ServiceList* New(::google::protobuf::Arena* arena = nullptr) const PROTOBUF_FINAL {
    return ::google::protobuf::Message::DefaultConstruct<Agent_ServiceList>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Agent_ServiceList& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Agent_ServiceList& from) { Agent_ServiceList::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Agent_ServiceList* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "DC.Packet.Agent_ServiceList"; }

 protected:
  explicit Agent_ServiceList(::google::protobuf::Arena* arena);
  Agent_ServiceList(::google::protobuf::Arena* arena, const Agent_ServiceList& from);
  Agent_ServiceList(::google::protobuf::Arena* arena, Agent_ServiceList&& from) noexcept
      : Agent_ServiceList(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const PROTOBUF_FINAL;
  static const ::google::protobuf::Message::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kIpAddressFieldNumber = 1,
    kPortFieldNumber = 2,
    kProcessIdFieldNumber = 3,
    kUserCountFieldNumber = 4,
  };
  // string ipAddress = 1;
  void clear_ipaddress() ;
  const std::string& ipaddress() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_ipaddress(Arg_&& arg, Args_... args);
  std::string* mutable_ipaddress();
  PROTOBUF_NODISCARD std::string* release_ipaddress();
  void set_allocated_ipaddress(std::string* value);

  private:
  const std::string& _internal_ipaddress() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_ipaddress(
      const std::string& value);
  std::string* _internal_mutable_ipaddress();

  public:
  // uint32 port = 2;
  void clear_port() ;
  ::uint32_t port() const;
  void set_port(::uint32_t value);

  private:
  ::uint32_t _internal_port() const;
  void _internal_set_port(::uint32_t value);

  public:
  // uint32 processId = 3;
  void clear_processid() ;
  ::uint32_t processid() const;
  void set_processid(::uint32_t value);

  private:
  ::uint32_t _internal_processid() const;
  void _internal_set_processid(::uint32_t value);

  public:
  // uint32 userCount = 4;
  void clear_usercount() ;
  ::uint32_t usercount() const;
  void set_usercount(::uint32_t value);

  private:
  ::uint32_t _internal_usercount() const;
  void _internal_set_usercount(::uint32_t value);

  public:
  // @@protoc_insertion_point(class_scope:DC.Packet.Agent_ServiceList)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 4, 0,
      45, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_Agent_ServiceList_default_instance_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const Agent_ServiceList& from_msg);
    ::google::protobuf::internal::ArenaStringPtr ipaddress_;
    ::uint32_t port_;
    ::uint32_t processid_;
    ::uint32_t usercount_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Agent_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Agent_ServiceList

// string ipAddress = 1;
inline void Agent_ServiceList::clear_ipaddress() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.ipaddress_.ClearToEmpty();
}
inline const std::string& Agent_ServiceList::ipaddress() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:DC.Packet.Agent_ServiceList.ipAddress)
  return _internal_ipaddress();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Agent_ServiceList::set_ipaddress(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.ipaddress_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:DC.Packet.Agent_ServiceList.ipAddress)
}
inline std::string* Agent_ServiceList::mutable_ipaddress() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_ipaddress();
  // @@protoc_insertion_point(field_mutable:DC.Packet.Agent_ServiceList.ipAddress)
  return _s;
}
inline const std::string& Agent_ServiceList::_internal_ipaddress() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.ipaddress_.Get();
}
inline void Agent_ServiceList::_internal_set_ipaddress(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.ipaddress_.Set(value, GetArena());
}
inline std::string* Agent_ServiceList::_internal_mutable_ipaddress() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.ipaddress_.Mutable( GetArena());
}
inline std::string* Agent_ServiceList::release_ipaddress() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:DC.Packet.Agent_ServiceList.ipAddress)
  return _impl_.ipaddress_.Release();
}
inline void Agent_ServiceList::set_allocated_ipaddress(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.ipaddress_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.ipaddress_.IsDefault()) {
          _impl_.ipaddress_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:DC.Packet.Agent_ServiceList.ipAddress)
}

// uint32 port = 2;
inline void Agent_ServiceList::clear_port() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.port_ = 0u;
}
inline ::uint32_t Agent_ServiceList::port() const {
  // @@protoc_insertion_point(field_get:DC.Packet.Agent_ServiceList.port)
  return _internal_port();
}
inline void Agent_ServiceList::set_port(::uint32_t value) {
  _internal_set_port(value);
  // @@protoc_insertion_point(field_set:DC.Packet.Agent_ServiceList.port)
}
inline ::uint32_t Agent_ServiceList::_internal_port() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.port_;
}
inline void Agent_ServiceList::_internal_set_port(::uint32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.port_ = value;
}

// uint32 processId = 3;
inline void Agent_ServiceList::clear_processid() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.processid_ = 0u;
}
inline ::uint32_t Agent_ServiceList::processid() const {
  // @@protoc_insertion_point(field_get:DC.Packet.Agent_ServiceList.processId)
  return _internal_processid();
}
inline void Agent_ServiceList::set_processid(::uint32_t value) {
  _internal_set_processid(value);
  // @@protoc_insertion_point(field_set:DC.Packet.Agent_ServiceList.processId)
}
inline ::uint32_t Agent_ServiceList::_internal_processid() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.processid_;
}
inline void Agent_ServiceList::_internal_set_processid(::uint32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.processid_ = value;
}

// uint32 userCount = 4;
inline void Agent_ServiceList::clear_usercount() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.usercount_ = 0u;
}
inline ::uint32_t Agent_ServiceList::usercount() const {
  // @@protoc_insertion_point(field_get:DC.Packet.Agent_ServiceList.userCount)
  return _internal_usercount();
}
inline void Agent_ServiceList::set_usercount(::uint32_t value) {
  _internal_set_usercount(value);
  // @@protoc_insertion_point(field_set:DC.Packet.Agent_ServiceList.userCount)
}
inline ::uint32_t Agent_ServiceList::_internal_usercount() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.usercount_;
}
inline void Agent_ServiceList::_internal_set_usercount(::uint32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.usercount_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace Packet
}  // namespace DC


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_Agent_2eproto_2epb_2eh