package class_2;

class Main {
  public static void main(String[] args) {
    Line line1 = new Line();

    Line line2 = new Line(10);
    line2.draw();

    line1.length = 100;

    line1.draw();


    Student student1 = new Student("Henrique", 0001);
    Student student2 = new Student("Eduarda", 0002);

    Pairs pairs = new Pairs(student1, student2);
    pairs.showStudents();

    Programmer programador = new Programmer(50, 38.5);
    programador.main();
  }
}
