import interfaces.IProduto;
import interfaces.IProdutosFrabricados;

import java.util.ArrayList;

public class GerenteProdutos {
    private static ArrayList<IProdutosFrabricados> produtos;

    public static ArrayList<String> obterIngredientes(String nomeProduto) {
        ArrayList<String> ingredientes = new ArrayList<String>();

        for (IProdutosFrabricados p : produtos) {
            if (p.getNome().equals(nomeProduto)) {
                for (int i = 0; i < p.getNumeroIngredientes(); i++) {
                    ingredientes.add(p.getIngrediente(i).getNome());
                }
            }
        }

        return ingredientes;
    }

    public static Double obterValorCompra(String nomeProduto) {
        Double valorCompra = 0.0;

        for (IProdutosFrabricados p : produtos) {
            if (p.getNome().equals(nomeProduto)) {
                for (int i = 0; i < p.getNumeroIngredientes(); i++) {
                    valorCompra += p.getIngrediente(i).getCusto();
                }
            }
        }

        return valorCompra;
    }
}
