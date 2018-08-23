p = i;		 -> ilegal
q = &j;		 -> legal
p = &*&i;	 -> legal
i = (*&)j;	 -> ilegal
i = *&j;	 -> legal
i = *&*&j;	 -> legal
q = *p;		 -> ilegal
i = (*p)++ + *q; -> legal


