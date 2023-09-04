package javaapplication1;

public class Dupla {
  Aluno aluno1;
  Aluno aluno2;
        
  Dupla(Aluno aluno1, Aluno aluno2) {
    this.aluno1 = aluno1;
    this.aluno2 = aluno2;
  }
          
  void mostarAlunos() {
    System.out.print("" + this.aluno1.nome + "-" + this.aluno2.nome + "\n");
  }
}
