package javaapplication1;

public class Programador {
    double valorHora;
    double horasTrabalhadas;
     
    Programador(double valorHora, double horasTrabalhadas) {
        if (valorHora < 0 || horasTrabalhadas < 0) {
            return;
        }
        
        this.valorHora = valorHora;
        this.horasTrabalhadas = horasTrabalhadas;
    }
    
    void main() {      
        double salario = this.calcularSalario();
        System.out.print("Salário: R$" + salario + "\n");
    }
    
    double calcularSalario() {
        return this.horasTrabalhadas * this.valorHora;
    }
}
