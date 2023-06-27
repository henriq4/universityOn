class Lamp {
  private boolean state;

  Lamp() {
    this.state = false;
  }

  Lamp(boolean state) {
    this.state = state;
  }

  void turnOn() {
    this.state = true;
  }

  void turnOff() {
    this.state = false;
  }

  String showState() {
    return this.state ? "Acesa" : "Apagada";
  }
}
