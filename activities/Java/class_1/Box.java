import java.util.Random;

class Box {
  private int width;
  private int height;
  private int depth;

  Box() {
    this.width = new Random().nextInt(10) + 1;
    this.height = new Random().nextInt(10) + 1;
    this.depth = new Random().nextInt(10) + 1;
  }

  int calcVolume() {
    return this.width * this.height * this.depth;
  }
}
