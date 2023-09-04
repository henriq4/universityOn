package javaapplication1;

public class Linha {
    int comprimento;
    
    Linha() {
        this.comprimento = 0;
    }
    
    Linha(int comprimento) {
        this.comprimento = comprimento;
    }
    
    void desenhar() {
        if (this.comprimento == 0) {
            return;
        }
        
        for (int i = 0; i < this.comprimento; i++) {
            System.out.print("_");
        }
        
       System.out.print("\n"); 
    }
}
