1) Em java o Nome do Arquivo deve ser o mesmo nome da Classe Principal
2) A classe principal é definida como "public class Xxxx{}", e o nome das Classes deve sempre começar com letra maiúscula (CamelCase)
3) Java possui uma nomenclatura única que pode ser difícil inicialemente:
   3.1) Classe: uma classe é um modelo ou um "molde" para criar objetos
   - As classes podem conter métodos (funções) e atributos (variáveis), e podem ser usadas para definir comportamentos e características dos objetos
   - A classe encapsula tanto o estado quanto o comportamento de um tipo de objeto (funciona tanto como Função quanto como Struct)
   - Classe em Java é uma entidade que combina tanto o estado quanto o comportamento
     - Estado: Representado pelos atributos (ou variáveis) dentro da classe
     - Comportamento: Representado pelos métodos (ou funções) que definem as ações que os objetos dessa classe podem realizar
   3.2) Método (Função): um método é uma função definida dentro de uma classe
   - Os métodos podem ser usados para realizar ações ou manipular os dados (atributos) de um objeto
   - Diferente de funções em C ou outras linguagens, os métodos em Java sempre pertencem a uma classe ou a um objeto
   3.3) Atributo (Variável): um atributo é uma variável que armazena o estado ou dados de um objeto
   - Ao contrário de C, onde as variáveis são simplesmente armazenadas na memória, em Java as variáveis podem ser características de uma classe ou objeto
   - Atributo(Variável): local de alocação de dados, diferentemente de C, atributos podem ter o tipo (String, int, double, etc.) de uma Classe 
   3.4) Objeto: um objeto é uma instância de uma classe, ou seja, um objeto é uma ocorrência específica de uma classe que tem seus próprios valores para os atributos e pode executar os métodos da classe
   - Em termos simples, um objeto é uma variável de tipo classe

Objeto: O objeto é o que você cria a partir de uma classe. Ele contém os dados e o comportamento definidos na classe.
5) Java é 0-Based, as contagens de arrays sempre tem a posição inicial como a posição 0
6) A função Main sempre é escrita da seguinte forma: public static void main(String[] args) {}
   - essa função DEVE ser public, caso contrário o programa não poderá ser compilado pela Java Virtual Machine
   - static indica ao compilador está atribuindo um valor que pertence à classe e não a uma instância específica. Isso significa que você pode acessar e modificar esse valor diretamente pela classe, sem depender do estado de um objeto específico.
   - void indica que a função main não retorna nada
   - (String[] args) permite que o programa seja alterado dinamicamente pela linha de comando ao enviar strings para o programa, sem precisar iniciá-lo novamente caso novos parâmetros sejam passados
7) A extensão do arquivo em java é ".java"

8) System.out.println("Olá") é a função print
9) Documentação no Java é feita através de um documento com o nome da classe em formato .html
