/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Mensagem"
 * 	found in "../teste1.asn1"
 */

#ifndef	_Login_H_
#define	_Login_H_


#include <asn_application.h>

/* Including external dependencies */
#include <PrintableString.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Login */
typedef struct Login {
	PrintableString_t	 usuario;
	PrintableString_t	 senha;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Login_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Login;

#ifdef __cplusplus
}
#endif

#endif	/* _Login_H_ */
#include <asn_internal.h>
