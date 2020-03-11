# ft_printf

	TYPES:

	d, i		- dec signed;	[%d and %i are synonymous for output, but are different when used with scanf() for input]
	o		- oct unsigned;
	u		- dec unsigned;
	x		- hex unsigned;
	X		- HEX UNSIGNED;

	c		- char;
	s		- NTS;

	p		- void * (pointer to void) in an implementation-defined format;

	f		- float;
	

	LENGTH FIELD:

	hh		- For integer types, causes printf to expect an int-sized integer argument which was promoted from a char;
	h		- For integer types, causes printf to expect an int-sized integer argument which was promoted from a short;
	l		- For integer types, causes printf to expect a long-sized integer argument;
			  For floating point types, this has no effect;
	ll		- For integer types, causes printf to expect a long long-sized integer argument;
	L		- For floating point types, causes printf to expect a long double argument;


	FLAGS:

	#		- The value should be converted to an ``alternate form''.  For c, d, i, n, p, s, and u conver-
			sions, this option has no effect.  For o conversions, the precision of the number is
			increased to force the first character of the output string to a zero.  For x and X conver-
			sions, a non-zero result has the string `0x' (or `0X' for X conversions) prepended to it.
			For a, A, e, E, f, F, g, and G conversions, the result will always contain a decimal point,
			even if no digits follow it (normally, a decimal point appears in the results of those con-
			versions only if a digit follows).  For g and G conversions, trailing zeros are not removed
			from the result as they would otherwise be.

	0		- Zero padding.  For all conversions except n, the converted value is padded on the left with
			zeros rather than blanks.  If a precision is given with a numeric conversion (d, i, o, u, i,
			x, and X), the 0 flag is ignored.

	-		- A negative field width flag; the converted value is to be left adjusted on the field boundary.  Except for n conversions, the converted value is padded on the right with blanks,
			rather than on the left with blanks or zeros.  A - overrides a 0 if both are given.

	+		-   A sign must always be placed before a number produced by a signed conversion.  A + overrides
			a space if both are used.

	" "		-  A blank should be left before a positive number produced by a signed conversion (a, A, d, e,
			E, f, F, g, G, or i).