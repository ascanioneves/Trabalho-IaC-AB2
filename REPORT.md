# Identificação

* Página do repositório do trabalho ([link GitHub]https://github.com/ascanioneves/Trabalho-IaC-AB2) 

* Discente 1
	* Nome: Ascânio Sávio de Araujo Neves
	* Matrícula: 19111148 
	* Distribuição da nota (%): IGUAL
* Discente 2
	* Nome: João Victor de Alarcão Ayalla Alcântara
	* Matrícula: 19111155
	* Distribuição da nota (%): IGUAL
* Discente 3
	* Nome: Danilo Vasconcelos Freire
	* Matrícula: 19110977
	* Distribuição da nota (%): IGUAL		
	
# Resultados
![GitHub Logo](https://media.discordapp.net/attachments/613803153128685636/613831287173677057/chart.png)
![GitHub Logo](https://media.discordapp.net/attachments/613803153128685636/613833063046185019/chart_1.png)
![GitHub Logo](https://media.discordapp.net/attachments/613803153128685636/613833076442660887/chart_2.png)


# Discussão

## Utilização intensa da UCP

Quando executado o programa com o parâmetro "cpu" como argumento da função "main", é acionada a condição de repetição durante 10 segundos de monitoramento, após isso o processo filho é eliminado. Assim sendo, o resultado obtido foi o esperado, visto que gerou uma intensa utilização da CPU com uma amplitude que variou de 0.0% a 125% na execução do programa.
  
  
A primeira etapa é a criação de um novo processo("processo filho") por meio da função "fork", a qual retorna um valor negativo caso houve algum erro na criação do processo, um valor positivo caso seja o processo de origem("processo pai") ou o valor 0 caso seja o processo filho e esse retorno é o identificador do processo("pid"). Após isso, são feitas as verificações dos argumentos da função "main", podendo ser "cpu" para utilização intensa da CPU ou "cpu-mem" para utilização intensa da CPU e da Memória, nesse caso iremos falar somente do argumento "cpu".
  
  
Após o argumento ser identificado como "cpu" o programa direciona a uma estrutura de repetição ,a princípio sem condição de parada, mas que futuramente será limitada pelo intervalo de 10 segundos. Vale ressaltar que os dois processos, tanto o "pai" quanto o "filho", estarão em execução e, com isso, o "pai" passa a monitorar o processo "filho" que é o alicerce do experimento. Para realizar esse monitoramento é necessário utilizar o seguinte comando do bash do Linux que é responsável por isso:  
```bash
ps -e -o pid,pcpu | grep "pid"(convertido para string)
```
  
Diante disso, a função responsável por inserir uma string no bash do linux é a "system", que está contida na biblioteca "stdlib.h", a qual recebe o comando como string e o insere no bash do linux a cada 1 segundo, em que o tempo é regulado pela função "sleep" que faz com que o programa aguarde a quantidade de tempo indicada pelo programador, sendo inserida num laço(comando "while") que, com auxílio de uma variável contadora, execute o comando em um total de 10 vezes exibindo o consumo, a cada ciclo, da CPU (em %). Após isso, é necessário que o processo "filho" seja eliminado, e isso feito através, novamente, da função "system" em que é passado o comando(em string) "kill " seguido do "pid" do "filho". Ao final de tudo, é exibida uma mensagem de status de como foi a execução do programa e uma mensagem "Tchau !". 

## Utilização intensa da UCP e memória

Quando executado o programa com o parâmetro "cpu-mem" como argumento da função "main", é acionada a condição de repetição durante 10 segundos de monitoramento, após isso o processo filho é eliminado. Assim sendo, o resultado obtido foi o esperado, visto que gerou uma intensa utilização da CPU com uma amplitude que variou de 0.0% a 107%, assim como, uma intensa utilização da Memória com uma amplitude que variou de 43176 Kilobytes a 4989804 Kilobytes.
  
Caso o argumento recebido na função "main" seja "cpu-mem" o programa direciona a uma estrutura de repetição que vai não somente realizar um laço limitado a 10 segundos como também vai, em outro laço alocar memória através da função "malloc" contida na biblioteca "stdlib.h". Ao decorrer da execução do programa, o processo "pai" vai fazer o monitoramento do processo "filho" que, nesse caso, será tanto utilização intensa da CPU quanto utilização intensa da Memória, e isso é feito através do seguinte comando do bash do Linux:
  
```bash
ps -e -o pid,pcpu | grep "pid"(convertido para string);pmap "pid"(convertido para string) | grep -i total 
```
Em que o primeiro comando(até o ponto e vírgula) é o do monitoramento da CPU e o segundo é o do monitoramento da Memória. Posteriormente, a função "system" fará a inserção dos comandos já armezenados em uma string no bash do Linux em um laço durante 10 segundos e será exibido o consumo da CPU(%) e o consumo da memória(Kilobytes) a cada ciclo de 1 segundo. Ao final dos 10 segundos de monitoramento, é necessária a eliminação do processo "filho" e isso é feito, também, pela função "system" através do comando "kill " seguido do "pid" do processo "filho" e ao final de tudo é exibida uma mensagem de status de como foi a execução do programa e uma mensagem "Tchau !".
