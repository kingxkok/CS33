union ufloat {
	unsigned u;
	float f;
};

static float u2f(unsigned u) {
	ufloat uf;
	uf.u = u;
	return uf.f;
}

float fpwr4(int x) {
	/* Result exponent and fraction */
	unsigned exp, frac;
	unsigned u;

	if (x <  -74) {
		/* Too small. Return 0.0 */
		exp = 0;
		frac = 0;
	}
	else if (x < -63) {
		/* Denormalized result */
		exp = 0;
		frac = 1 << (149 + (x << 1));
	}
	else if (x <  64) {
		/* Normalized result. */
		exp = (x << 1) + 127;
		frac = 0;
	}
	else {
		/* Too big. Return +oo */
		exp = 0xFF;
		frac = 0;
	}

	/* Pack exp and frac into 32 bits */
	u = exp << 23 | frac;
	return u2f(u);
}
