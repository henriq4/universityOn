class Varargs {
  public int resolve(String op, int ...v) {
    int x;

    if (op == "SOM") {
      x = 0;

      for (int i = 0; i < v.length; i++) {
        x += v[i];
      }

      return x;
    }

    if (op == "MULT") {
      x = 1;

      for (int i = 0; i < v.length; i++) {
        x *= v[i];
      }

      return x;
    }

    throw new Error("Use apenas MULT ou SOM para a operação.");
  }
}
