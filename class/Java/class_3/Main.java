class Main {
  public static void main(String args[]) {
    Varargs v = new Varargs();

    int mult = v.resolve("MULT", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int sum = v.resolve("SOM", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    System.out.println("Multiplicação: " + mult);
    System.out.println("Soma: " + sum);

    InstacedTimes obj1 = new InstacedTimes();
    InstacedTimes obj2 = new InstacedTimes();
    InstacedTimes obj3 = new InstacedTimes();
    InstacedTimes obj4 = new InstacedTimes();

    System.out.println("Números de objetos instânciados: " + obj1.objectQuantity());
  }
}
