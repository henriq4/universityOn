import interfaces.IProduto;

public class Comprados implements IProduto {
    private String nome;

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCusto(Double custo) {
        this.custo = custo;
    }

    private Double custo;

    public Comprados() {
        this.nome = new String();
        this.custo = 0.0;
    }

    @Override
    public String getNome() {
        return this.nome;
    }

    @Override
    public Double getCusto() {
        return this.custo;
    }
}
