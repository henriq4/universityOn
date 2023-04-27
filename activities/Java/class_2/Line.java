package class_2;

class Line {
    int length;

    Line() {
        this.length = 0;
    }

    Line(int length) {
        this.length = length;
    }

    void draw() {
        if (this.length == 0) {
            return;
        }

        for (int i = 0; i < this.length; i++) {
            System.out.print("_");
        }

       System.out.print("\n");
    }
}
