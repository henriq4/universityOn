class Container {
    private double capacidade;
    private boolean ocupado;

    Container() {
        this.capacidade = 0.0;
        this.ocupado = false;
    }

    Container(double capacidade, boolean ocupado) {
        this.capacidade = capacidade;
        this.ocupado = ocupado;
    }


    public boolean isOcupado() {
        return ocupado;
    }

    public void setOcupado(boolean ocupado) {
        this.ocupado = ocupado;
    }

    public double getCapacidade() {
        return this.capacidade;
    }

    public void setCapacidade(double capacidade) {
        this.capacidade = capacidade;
    }

    public boolean ocupar(double medida) {
        if (this.capacidade >= medida && !this.ocupado) {
            this.ocupado = true;

            return true;
        }

        return false;
    }
}
