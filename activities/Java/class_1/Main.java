class Main {
  public static void main(String[] args) {
    // 1
    Lamp lamp = new Lamp(false);

    System.out.println(lamp.showState());
    lamp.turnOn();

    System.out.println(lamp.showState());

    System.out.println(lamp.showState());
    lamp.turnOff();

    System.out.println(lamp.showState());

    // 2
    Box box = new Box();

    System.out.println("Volume: " + box.calcVolume() + "cm³");

    // 3
    Date date = new Date(17, 06, 2004);
    date.main();
    System.out.println(date.formatDate("/"));
    System.out.println(date.formatDate("-"));
  }
}
