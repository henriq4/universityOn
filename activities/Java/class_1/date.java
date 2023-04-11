package class_1;

class Date {
  private int day;
  private int month;
  private int year;

  Date() {
    this.day = 1;
    this.month = 1;
    this.year = 2004;
  }

  Date(int year) {
    this.day = 1;
    this.month = 1;
    this.year = year;
  }

  Date(int day, int month, int year) {
    this.day = day;
    this.month = month;
    this.year = year;
  }

  String formatDate(String separator) {
    if (separator == "/") {
      return this.day + separator + this.month + separator + this.year;
    }

    if (separator == "-") {
      return this.year + separator + this.month + separator + this.day;
    }

    return "Invalid separator";
  }

  void main() {
    System.out.println("Create a Date object:");
    System.out.println("\tDate date = new Date();");
    System.out.println("\tDate date = new Date(2004);");
    System.out.println("\tDate date = new Date(17, 06, 2004);");

    System.out.println("Methods:");
    System.out.println("\tdate.formatDate(\"/\") to return the date with / separator");
    System.out.println("\tdate.formatDate(\"-\") to return the date with - separator");
  }
}
