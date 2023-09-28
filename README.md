PROJ1 - Concorrência

Bruno Roveri - 32231911
Lucas Farias - 32250193


- Requisitos:
Linux
Bibliotecas padrão
GCC (GNU Compiler Collection)

- Passo a Passo:
Primeiramente, usamos o aplicativo GitHub para criar um novo repositório para alocar o código.
Nisso, iremos instalar o Git na AWS pelo: "sudo apt update sudo apt install git".
Logo em seguida, solicitamos a chave para configurar o git pelo: "ssh-keygen";
Depois, disso sera clonado o repositório pelo: "git clone (REPOSITÓRIO)";
Logo, usamos o: "cd";
Depois de ter clonado o repositório com nome na AWS, será criada um arquivo para você poder digitar seu código;
Logo em seguida, você atualiza o nome dele pelo: "mv";
E com o comando: "vi", você consegue escrever seu código;
Para a compilação do seu progarama, use o: "gcc -o transferencia_program transferencia.c -lpthread -lrt"
O transferencia_program: esta opção permite nomear o executável como "transferencia_program".
Lpthread e -lrt são flags de vinculação para garantir que o programa seja vinculado às bibliotecas necessárias.
Uma vez que o código foi compilado com sucesso, você pode executar o programa utilizando o seguinte comando: "./transferencia_program"

- Explicação do Código:
Este código C implementa uma simulação de transferência de saldo entre duas contas bancárias usando threads e semáforos para garantir a sincronização.
As contas 'from' e 'to' começam com um saldo de 100 cada. Dez threads são criadas para transferir 10 unidades de 'from' para 'to'.
Semáforos são usados para controlar o acesso concorrente às contas, garantindo a consistência dos saldos. Após as transferências, o código zera o saldo da conta 'from' e finaliza a execução.
