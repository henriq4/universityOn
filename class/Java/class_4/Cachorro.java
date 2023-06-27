class Cachorro {
    private String raca;
    private String nome;

    Cachorro() {
        this.nome = "";
        this.raca = "";
    }

    Cachorro(String nome) {
        this.nome = nome;
    }

    Cachorro(String nome, String raca) {
        this.nome = nome;
        this.raca = raca;
    }

    public String getRaca() {
        return this.raca;
    }

    public String getNome() {
        return this.nome;
    }

    public void setRaca(String raca) {
        this.raca = raca;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void latir() {
        System.out.println("auau");
    }

    public void latirRepetido(int n) {
        if (n < 0) {
            System.out.println("bugou");
        }

        if (n > 100) {
            System.out.println("parâmetro inválido");
        }

        for (int i = 0; i < n; i++) {
            System.out.println("auau");
        }
    }
}
