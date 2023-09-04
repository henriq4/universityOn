import interfaces.IProduto;
import interfaces.IProdutosFrabricados;

import java.util.ArrayList;

public class Fabricados implements IProdutosFrabricados {
    private ArrayList<IProduto> ingredientes;

    public Fabricados() {
        this.custo = 0.0;
        this.nome = new String();
        this.numeroIngredientes = 0;
        this.ingredientes = new ArrayList<IProduto>();
    }

    public void setNumeroIngredientes(int numeroIngredientes) {
        this.numeroIngredientes = numeroIngredientes;
    }

    private int numeroIngredientes;
    private String nome;

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCusto(Double custo) {
        this.custo = custo;
    }

    private Double custo;

    @Override
    public String getNome() {
        return this.nome;
    }

    @Override
    public Double getCusto() {
        return this.custo;
    }

    @Override
    public int getNumeroIngredientes() {
        return this.numeroIngredientes;
    }

    @Override
    public IProduto getIngrediente(int numero) {
        return this.ingredientes.get(numero);
    }
}
