package interfaces;

public interface IProdutosFrabricados extends IProduto {
    int getNumeroIngredientes();
    IProduto getIngrediente(int numero);
}
