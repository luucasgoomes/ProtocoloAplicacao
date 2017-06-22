/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0310"
 * 	found in "../tap3.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#include "IpAddress.h"

static asn_TYPE_member_t asn_MBR_IpAddress_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct IpAddress, choice.iPTextV4Address),
		(ASN_TAG_CLASS_APPLICATION | (131 << 2)),
		0,
		&asn_DEF_IPTextV4Address,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"iPTextV4Address"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct IpAddress, choice.iPTextV6Address),
		(ASN_TAG_CLASS_APPLICATION | (132 << 2)),
		0,
		&asn_DEF_IPTextV6Address,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"iPTextV6Address"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_IpAddress_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (131 << 2)), 0, 0, 0 }, /* iPTextV4Address */
    { (ASN_TAG_CLASS_APPLICATION | (132 << 2)), 1, 0, 0 } /* iPTextV6Address */
};
static asn_CHOICE_specifics_t asn_SPC_IpAddress_specs_1 = {
	sizeof(struct IpAddress),
	offsetof(struct IpAddress, _asn_ctx),
	offsetof(struct IpAddress, present),
	sizeof(((struct IpAddress *)0)->present),
	asn_MAP_IpAddress_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_IpAddress = {
	"IpAddress",
	"IpAddress",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	0,	/* No PER visible constraints */
	asn_MBR_IpAddress_1,
	2,	/* Elements count */
	&asn_SPC_IpAddress_specs_1	/* Additional specs */
};

