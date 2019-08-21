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

Quando executado o programa com o parâmetro "cpu" como argumento da função main, é acionada a condição de repetição durante 10 segundos de monitoramento, após isso o processo filho é eliminado. Assim sendo, o resultado obtido foi o esperado, visto que gerou uma intensa utilização da CPU com uma amplitude que variou de 0.0% a 125% na execução do programa.

## Utilização intensa da UCP e memória

TODO: explicar se o comportamento da curva **UCP-MEM** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.
