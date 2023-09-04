import java.util.ArrayList;

public class Fila {
    Fila() {
        this.fim = 0;
        this.inicio = 0;
        this.pessoas = new ArrayList<Pessoa>();
    }

    public ArrayList<Pessoa> getPessoas() {
        return pessoas;
    }

    public void setPessoas(ArrayList<Pessoa> pessoas) {
        this.pessoas = pessoas;
    }

    public int getInicio() {
        return inicio;
    }

    public void setInicio(int inicio) {
        this.inicio = inicio;
    }

    public int getFim() {
        return fim;
    }

    public void setFim(int fim) {
        this.fim = fim;
    }

    private ArrayList<Pessoa> pessoas;
    private int inicio;
    private int fim;

    public void adicionar(Pessoa pessoa) {
        this.pessoas.add(pessoa);
        this.fim++;
    }

    public void atender() {
        this.pessoas.remove(inicio);
        this.inicio++;
    }

    public void listar() {
        for (Pessoa p : pessoas) {
            System.out.println(p.getNome());
        }
    }

//    add
//    atender
//            listar
}
