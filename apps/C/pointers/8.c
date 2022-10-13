// y = p1 == p2       // False
// p1 += p2           // Error
// x = (*p1) - (*p2)  // -5
// p1++               // Memory block address + 4
// x = p1 || p2       // True

void main() {
  int x = 5, y = 10;
  int *p1 = &x;
  int *p2 = &y;
}
