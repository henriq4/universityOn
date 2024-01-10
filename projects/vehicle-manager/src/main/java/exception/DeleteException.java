package exception;

public class DeleteException extends Exception {

    public DeleteException(){
        super("Objeto não pode ser excluído");
    }

}
