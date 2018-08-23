// O endereço 4092 será tratado como hexadecimal

* x+1 == 4093; x+2 == 4094; x+4 == 4095; // pula-se um byte para cada elemento do array


* x+1 == 4094; x+2 == 4096; x+4 == 4098; // pula-se dois byte para cada elemento do array


* x+1 == 4096; x+2 == 409a; x+4 == 409e; // pula-se quatro byte para cada elemento do array


* x+1 == 409a; x+2 == 40a2; x+4 == 40aa; // pula-se oito byte para cada elemento do array
