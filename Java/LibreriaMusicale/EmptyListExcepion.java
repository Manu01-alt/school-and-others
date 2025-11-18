public class EmptyListExcepion extends Exception {
    public EmptyListExcepion(String message) {
        super(message);
    }

    public EmptyListExcepion() {
        super("La lista è vuota.");
    }

}

class ElementNotFoundException extends Exception {
    public ElementNotFoundException(String message) {
        super(message);
    }

    public ElementNotFoundException() {
        super("L'elemento non è stato trovato.");
    }

}

