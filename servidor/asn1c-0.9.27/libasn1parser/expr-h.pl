#!/usr/bin/env perl


print<<EOM;
/*
 * This file is automatically generated by $0
 * DO NOT EDIT MANUALLY, fix the $0 instead if necessary.
 */
#ifndef	ASN1_PARSER_EXPR_STR_H
#define	ASN1_PARSER_EXPR_STR_H

#ifndef	__GNUC__
#define	__attribute__(x)	/* unused */
#endif

static char *asn1p_expr_type2str[] __attribute__ ((unused)) = {
EOM

while(<>) {
	chomp;
	next if(/TYPE_MAX/);
	next unless(/^[ \t]+(ASN_[A-Z]+_([A-Za-z0-9_]+))/);

	print "\t[ $1 ]\t = ";

	$_ = $2;
	if($_ eq "RELATIVE_OID") {
		print '"RELATIVE-OID"';
	} else {
		s/_/ /;
		print '"'.$_.'"';
	}

	print ",\n";
}

print<<EOM;
};

/*
 * Convert the ASN.1 expression type back into the string representation.
 */
#define	ASN_EXPR_TYPE2STR(type)					\\
	(							\\
	(((ssize_t)(type)) < 0					\\
	|| ((size_t)(type)) >= sizeof(asn1p_expr_type2str)	\\
		/ sizeof(asn1p_expr_type2str[0]))		\\
		? (char *)0					\\
		: asn1p_expr_type2str[(int)(type)]		\\
	)

#endif	/* ASN1_PARSER_EXPR_STR_H */
EOM
