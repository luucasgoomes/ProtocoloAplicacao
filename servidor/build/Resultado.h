/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Mensagem"
 * 	found in "../teste1.asn1"
 */

#ifndef	_Resultado_H_
#define	_Resultado_H_


#include <asn_application.h>

/* Including external dependencies */
#include <PrintableString.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Resultado */
typedef struct Resultado {
	PrintableString_t	 resultado;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Resultado_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Resultado;

#ifdef __cplusplus
}
#endif

#endif	/* _Resultado_H_ */
#include <asn_internal.h>
