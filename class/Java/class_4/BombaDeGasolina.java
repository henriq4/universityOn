class BombaDeGasolina {
    private double tanque;
    private double precoLitro;
    private double litrosVendidos;
    private double valorVendas;

    BombaDeGasolina() {
        this.tanque = 5000;
        this.precoLitro = 5.20;
        this.litrosVendidos = 0;
        this.valorVendas = 0;
    }

    public void abastecerPorLitro(double litros) {
        if (litros <= 0) {
            return;
        }

        if (litros > this.tanque) {
            System.out.println("Capacidade excedida");
        }

        this.tanque -= litros;
        this.litrosVendidos += litros;
        this.valorVendas += litros * this.precoLitro;
    }

    public void abastecerPorDinheiro(double valor) {
        if (valor <= 0) {
            return;
        }

        this.valorVendas += valor;
        this.litrosVendidos += valor / this.precoLitro;
        this.tanque -= valor / this.precoLitro;
    }

    public double status() {
        return this.tanque;
    }

    public double getPrecoLitro() {
        return this.precoLitro;
    }

    public double getLitrosVendidos() {
        return this.litrosVendidos;
    }

    public double getValorVendas() {
        return this.valorVendas;
    }

    public void setPrecoLitro(double precoLitro) {
        this.precoLitro = precoLitro;
    }
}
