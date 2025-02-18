1) Em java o Nome do Arquivo deve ser o mesmo nome da Classe Principal
2) A classe principal é definida como "public class Xxxx{}", e o nome das Classes deve sempre começar com letra maiúscula (CamelCase)
3) A função Main sempre é escrita da seguinte forma: public static void main(String[] args) {}
   - essa função DEVE ser public, caso contrário o programa não poderá ser compilado pela Java Virtual Machine
   - static indica ao compilador está atribuindo um valor que pertence à classe e não a uma instância específica. Isso significa que você pode acessar e modificar esse valor diretamente pela classe, sem depender do estado de um objeto específico.
   - void indica que a função main não retorna nada
   - (String[] args) permite que o programa seja alterado dinamicamente pela linha de comando ao enviar strings para o programa, sem precisar iniciá-lo novamente caso novos parâmetros sejam passados
4) A extensão do arquivo em java é ".java"
