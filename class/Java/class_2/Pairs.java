package class_2;

class Pairs {
  Student student1;
  Student student2;

  Pairs(Student student1, Student student2) {
    this.student1 = student1;
    this.student2 = student2;
  }

  void showStudents() {
    System.out.print("" + this.student1.nome + "-" + this.student2.nome + "\n");
  }
}
