/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: opentelemetry/proto/resource/v1/resource.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "resource.pb-c.h"
void opentelemetry__proto__resource__v1__resource__init(
    Opentelemetry__Proto__Resource__V1__Resource *message)
{
    static const Opentelemetry__Proto__Resource__V1__Resource init_value =
        OPENTELEMETRY__PROTO__RESOURCE__V1__RESOURCE__INIT;
    *message = init_value;
}
size_t opentelemetry__proto__resource__v1__resource__get_packed_size(
    const Opentelemetry__Proto__Resource__V1__Resource *message)
{
    assert(message->base.descriptor ==
           &opentelemetry__proto__resource__v1__resource__descriptor);
    return protobuf_c_message_get_packed_size(
        (const ProtobufCMessage *) (message));
}
size_t opentelemetry__proto__resource__v1__resource__pack(
    const Opentelemetry__Proto__Resource__V1__Resource *message, uint8_t *out)
{
    assert(message->base.descriptor ==
           &opentelemetry__proto__resource__v1__resource__descriptor);
    return protobuf_c_message_pack((const ProtobufCMessage *) message, out);
}
size_t opentelemetry__proto__resource__v1__resource__pack_to_buffer(
    const Opentelemetry__Proto__Resource__V1__Resource *message,
    ProtobufCBuffer *                                   buffer)
{
    assert(message->base.descriptor ==
           &opentelemetry__proto__resource__v1__resource__descriptor);
    return protobuf_c_message_pack_to_buffer((const ProtobufCMessage *) message,
                                             buffer);
}
Opentelemetry__Proto__Resource__V1__Resource *
opentelemetry__proto__resource__v1__resource__unpack(
    ProtobufCAllocator *allocator, size_t len, const uint8_t *data)
{
    return (Opentelemetry__Proto__Resource__V1__Resource *)
        protobuf_c_message_unpack(
            &opentelemetry__proto__resource__v1__resource__descriptor,
            allocator, len, data);
}
void opentelemetry__proto__resource__v1__resource__free_unpacked(
    Opentelemetry__Proto__Resource__V1__Resource *message,
    ProtobufCAllocator *                          allocator)
{
    if (!message)
        return;
    assert(message->base.descriptor ==
           &opentelemetry__proto__resource__v1__resource__descriptor);
    protobuf_c_message_free_unpacked((ProtobufCMessage *) message, allocator);
}
static const ProtobufCFieldDescriptor
    opentelemetry__proto__resource__v1__resource__field_descriptors[2] = {
        {
            "attributes", 1, PROTOBUF_C_LABEL_REPEATED, PROTOBUF_C_TYPE_MESSAGE,
            offsetof(Opentelemetry__Proto__Resource__V1__Resource,
                     n_attributes),
            offsetof(Opentelemetry__Proto__Resource__V1__Resource, attributes),
            &opentelemetry__proto__common__v1__key_value__descriptor, NULL,
            0,            /* flags */
            0, NULL, NULL /* reserved1,reserved2, etc */
        },
        {
            "dropped_attributes_count", 2, PROTOBUF_C_LABEL_NONE,
            PROTOBUF_C_TYPE_UINT32, 0, /* quantifier_offset */
            offsetof(Opentelemetry__Proto__Resource__V1__Resource,
                     dropped_attributes_count),
            NULL, NULL, 0, /* flags */
            0, NULL, NULL  /* reserved1,reserved2, etc */
        },
    };
static const unsigned
    opentelemetry__proto__resource__v1__resource__field_indices_by_name[] = {
        0, /* field[0] = attributes */
        1, /* field[1] = dropped_attributes_count */
    };
static const ProtobufCIntRange
    opentelemetry__proto__resource__v1__resource__number_ranges[1 + 1] = {
        { 1, 0 }, { 0, 2 }
    };
const ProtobufCMessageDescriptor
    opentelemetry__proto__resource__v1__resource__descriptor = {
        PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
        "opentelemetry.proto.resource.v1.Resource",
        "Resource",
        "Opentelemetry__Proto__Resource__V1__Resource",
        "opentelemetry.proto.resource.v1",
        sizeof(Opentelemetry__Proto__Resource__V1__Resource),
        2,
        opentelemetry__proto__resource__v1__resource__field_descriptors,
        opentelemetry__proto__resource__v1__resource__field_indices_by_name,
        1,
        opentelemetry__proto__resource__v1__resource__number_ranges,
        (ProtobufCMessageInit)
            opentelemetry__proto__resource__v1__resource__init,
        NULL,
        NULL,
        NULL /* reserved[123] */
    };
