p = mat + 1;	-> Válido, pois adiciona mais quatro bytes no ponteiro para o primeiro elemento do array, ou seja aponta para o segundo elemrnto do array
p = mat++;	-> Inválido, pois não incrementa o ponteiro corretamente
p = ++mat;	-> Inválido, pois não incrementa o ponteiro corretamente
x = (*mat)++;	-> Válido, desrefêrencia o ponteiro para o primeiro elemento recupenrando o valor e soma um a ele


