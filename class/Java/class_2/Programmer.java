package class_2;

class Programmer {
    double valueForHour;
    double workedHours;

    Programmer(double valueForHour, double workedHours) {
        if (valueForHour < 0 || workedHours < 0) {
            return;
        }

        this.valueForHour = valueForHour;
        this.workedHours = workedHours;
    }

    void main() {
        double salary = this.calculateSalary();
        System.out.print("Slary: R$" + salary + "\n");
    }

    double calculateSalary() {
        return this.workedHours * this.valueForHour;
    }
}
