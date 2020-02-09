# Alunos: Dimitre Ortt & Willian Ferreira


#-----------------------------------------##------------------------------------------#

A1 - Completamos a classe Light com os atributos referentes �s luzes Directional, 
Spot e Point, a edi��o de tais atributos est� dispon�vel na janela inspector, s�o eles: 

 - position, 
 - direction (Spot, Direcional), 
 - falloff (Spot, Point),
 - ghama (�ngulo de abertura da Spot),
 - color,
 - type,
 - fallExponent (expoente de decaimento da Spot).

#-----------------------------------------##------------------------------------------#

A2 - Implementamos o bot�o de adi��o e dele��o de objetos de cena na janela da 
hierarquia. � poss�vel adicionar luzes com seus respectivos tipos. No menu se encontra
3 op��es para criar luzes: Point Light, Directional Light e Spot Light. As op��es, 
como o nome sugere, criam objetos de cena adicionando componentes do tipo luz, o
qual tem o tipo correspondente.

#-----------------------------------------##------------------------------------------#

A3 - Implementamos em P3.cpp o m�todo P3::drawLight(), o qual recebe uma refer�ncia 
para um componente Light e desenha na janela o desenho correspondente. Cada tipo de 
luz possui um desenho. As luzes Directional e Spot tem o desenho apontando para o foco
de sua luz.

#-----------------------------------------##------------------------------------------#

A4 - Implementamos um programa GLSL de tonaliza��o de Gouraud com o modelo de 
ilumina��o de phong nos programas gouraud.vs e gouraud.fs. Este � o programa sendo 
usado para a renderiza��o da cena no modo de edi��o.
O modelo de ilumina��o de phong o qual possui f�rmula descrita e detalhadamente 
explicada no cap�tulo 4 est� programado em OpenGL no arquivo gouraud.vs.

#-----------------------------------------##------------------------------------------#

A5 - Implementamos um programa GLSL de tonaliza��o de Phong com o modelo de 
ilumina��o de phong nos programas phong.vs e phong.fs. Este � o programa sendo 
usado para a renderiza��o da cena na janelinha de preview da camera corrente (caso
haja) e da cena no modo renderiza��o.
O modelo de ilumina��o de phong est� programado em OpenGL no arquivo phong.fs.

#-----------------------------------------##------------------------------------------#

A6 - Criamos uma cena inicial, renderizada assim que o programa entra em execu��o, a 
qual mostra objetos de cena e luzes dispostos em posi��es que mostrem o funcionamento
das luzes e a difus�o das luzes pelos objetos.
- Criamos uma luz spot vermelha, uma luz Point verde e uma luz Directional azul.
- Criamos 3 boxes flats, dispostas como se formando uma sala, para que os raios de luz
se encontrem com as boxes e assim seja poss�vel perceber o seu efeito. 
- Criamos uma camera (Main Camera), e a posicionamos de maneira a possuir a cena
em seu volume de vista. Colocamos esta c�mera como o objeto corrente da cena no in�cio
da execu��o, assim, na primeira renderiza��o a c�mera j� � desenhada na tela assim
como sua janelinha de preview. Como a renderiza��o na janelinha utiliza a tonaliza��o
de Phong, podemos visualizar o seu funcionamento na primeira cena renderizada.

-#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#-


-#- Decis�es de projeto:

 - No bot�o Add Component, na op��o Primitive, � adicionado um primitivo com a malha 
	Box, o qual pode posteriormente ser alterado atrav�s do bot�o meshes.
 - Adi��o das luzes nos shaders: m�todo P3::establishLights(): para cada luz presente 
	na hierarquia de objetos de cena, este m�todo adiciona aos shaders, no vetor 
	lights[], os dados da luz. O vetor tem uma limita��o de at� 10 luzes. 
 - Permitimos a adi��o de luzes ilimitadas na hierarquia de objetos, por�m na 
	renderiza��o s� ser�o utilizadas as 10 primeiras luzes ligadas encontradas na 
	hierarquia de objetos (percorrida de maneira in order).
 
-#- Observa��es:

 - O falloff � um inteiro que varia entre 0 e 2 inicializado com 1.
 - Na janela Inspector, ao inspecionar uma luz, criamos a checkbox "On", a qual
	determina se a luz est� acesa ou n�o. 
 - Quando uma luz nova � criada atrav�z do bot�o create, ela � iniciada com a cor 
	branca.
 - N�o fizemos a entrega da Parte 2 do trabalho, assim, visto que as partes s�o 
	cumulativas, fizemos o P2 e o P3 para esta entrega, todas as funcionalidades 
	do P2 est�o implementadas e funcionando adequadamente.
 - Nossos c�digos das partes p1 e p2 n�o est�o presentes nas pastas p1 e p2, est�o 
	todos integrados diretamente nos c�digos do P3.

-#- Recomenda��o durante os testes:

 - A cena � iniciada com 3 luzes acesas, para testar seu funcionamento, v� � janela
	inspector das luzes e apague uma ou duas, e ent�o v� a janela da hierarquia
	e clique na Main Camera, o que mostrar� a janelinha de preview da camera. 
	Assim, ser� poss�vel visualizar os efeitos das luzes nas duas tonaliza��es 
	implementadas.