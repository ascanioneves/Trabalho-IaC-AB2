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

![GitHub Logo](https://media.discordapp.net/attachments/613803153128685636/613833063046185019/chart_1.png)
* TODO: Plotar um gráfico com os resultados das medições das seguintes métricas utilizadas para avaliar o comportamento do **processo filho**:
	*  **UCP**: consumo da UCP em porcentagem.
	*  **UCP-MEM**: consumo da memória principal em Kilobytes.
* TODO: Cada métrica deve ser plotada em duas curvas separadas.
* TODO: o eixo das abscissas deve representar o tempo medido a cada segundo e o eixo das coordenadas deve representar a métrica medida.


# Discussão

## Utilização intensa da UCP

Quando executado o programa com o parâmetro "cpu" como argumento da função "main", é acionada a condição de repetição durante 10 segundos de monitoramento, após isso o processo filho é eliminado. Assim sendo, o resultado obtido foi o esperado, visto que gerou uma intensa utilização da CPU com uma amplitude que variou de 0.0% a 125% na execução do programa.
  
  
A primeira etapa é a criação de um novo processo("processo filho") por meio da função "fork", a qual retorna um valor negativo caso houve algum erro na criação do processo, um valor positivo caso seja o processo de origem("processo pai") ou o valor 0 caso seja o processo filho. Após isso, são feitas as verificações dos argumentos da função "main", podendo ser "cpu" para utilização intensa da CPU ou "cpu-mem" para utilização intensa da CPU e da Memória, nesse caso iremos falar somente do argumento "cpu".
  
  
Após o argumento ser identificado como "cpu" o programa direciona a uma estrutura de repetição ,a princípio sem condição de parada, mas que futuramente será limitada pelo intervalo de 10 segundos. Vale ressaltar que os dois processos, tanto o "pai" quanto o "filho", estarão em execução e, com isso, o "pai" passa a monitorar o processo "filho" que é o alicerce do experimento. Para realizar esse monitoramento é necessário utilizar o comando do bash do Linux que é responsável por isso:  
```c
ps -e -o pid,pcpu | grep "pid"(convertido para string)
```

## Utilização intensa da UCP e memória

TODO: explicar se o comportamento da curva **UCP-MEM** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.
