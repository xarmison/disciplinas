printf("%x %d %d %d %d", p,*p+2,**&p,3**p,**&p+4); -> Erro no '%x' para imprimir o ponteiro

printf("\n%p %d %d %d %d\n", p,*p+2,**&p,3**p,**&p+4); -> 4094 7 5(o que estiver em i) 15(3*o que estiver em i) 9(contedudo de i mais 4)
