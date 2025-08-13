
Este projeto foi desenvolvido como parte do common core da 42 LIsboa para praticar a leitura de ficheiros linha a linha em C. O objetivo é implementar uma função chamada get_next_line que devolve a próxima linha lida de um file descriptor.

**🧠 Objetivo**
Criar uma função que retorna uma linha de um file descriptor por chamada.

Trabalhar com buffers de leitura de tamanho variável.

Explorar o uso de variáveis estáticas para manter estado entre chamadas.

**(Bónus)** Suportar múltiplos file descriptors simultaneamente.

**🔧 Compilação**
A função deve ser compilada com a flag -D BUFFER_SIZE=n, onde n é o tamanho do buffer usado em cada leitura.

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

**📌 Regras**
A função deve retornar a linha lida incluindo o \n, exceto no final do ficheiro.

Se ocorrer um erro ou não houver mais nada a ler, deve retornar NULL.

A função não pode usar lseek(), variáveis globais nem a libft.

O projeto deve compilar sem erros e sem leaks de memória.

A leitura deve ser feita de forma incremental, linha a linha, e não o ficheiro todo de uma vez.

**💡 Bónus**
Se a parte obrigatória estiver 100% funcional, a parte bônus pode ser avaliada:

Utilização de apenas uma variável estática.

Suporte a vários file descriptors sem perder estado entre eles.
