class Main {
  public static void main(String args[]) {
    Cachorro cachorro = new Cachorro();
    cachorro.setNome("lola");
    cachorro.setRaca("vira-lata");
    cachorro.latir();
    System.out.println(cachorro.getNome());
    cachorro.latirRepetido(4);

    Container container = new Container(10, false);
    System.out.println(container.getCapacidade());
    container.ocupar(9.5);
    System.out.println(container.isOcupado());
    container.setOcupado(false);
    System.out.println(container.isOcupado());

    BombaDeGasolina bomba = new BombaDeGasolina();
    bomba.abastecerPorLitro(120.0);
    bomba.abastecerPorDinheiro(500);
    System.out.println("Status da Bomba: " + bomba.status());

    Util util = new Util();
    System.out.println(util.ehPar(4));
    System.out.println(util.ehNegativo(10));
    System.out.println(util.maior(2, 4));

    Varargs varargs = new Varargs();
    int maior = varargs.maior(1,  2, 5, 6, 2, 4, 3, 2, 6, 7, 3 ,1 ,3, 3);
    System.out.println(maior);
  }
}
