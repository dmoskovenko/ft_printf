	TYPES:

	d, i	- dec signed;		[%d and %i are synonymous for output, but are different when used with scanf() for input]
	o		- oct unsigned;
	u		- dec unsigned;
	x		- hex unsigned;
	X		- HEX UNSIGNED;
	_______________________

	c		- char;
	s		- NTS;
	p		- void * (pointer to void) in an implementation-defined format;
	_______________________

	f		- float;
	

	LENGTH FIELD:

	hh		- For integer types, causes printf to expect an int-sized integer argument which was promoted from a char;
	h		- For integer types, causes printf to expect an int-sized integer argument which was promoted from a short;
	l		- For integer types, causes printf to expect a long-sized integer argument;
			  For floating point types, this has no effect.[????????];
	ll		- For integer types, causes printf to expect a long long-sized integer argument;
	L		- For floating point types, causes printf to expect a long double argument;