1)
void count() {
 printf("Enter lines of text here: ...\n");

 int c, nl = 0, nc = 0, nt = 0, nbackslash = 0;
 while ((c = fgetc(stderr)) != EOF) {
 if (c == '\n') { ++nl;
 } else if (c == '\t') { ++nt;
 } else if (c == '\\') { ++nbackslash;
 } else if (isspace(c)) { ++nc; }
 printf("lines: %d\n", nl);
 printf("tabs: %d\n", nt);
 printf("backslashes: %d\n", nbackslash);
 printf("alphanumeric: %d\n", nc);
}
int main(int argc, const char* argv[]) {
 count();
 return 0;
}
2) char* strchr(const char* s, char c);
3) size_t strpsn(const char* s, const char* t);
4) exit(0);
5) fopen("midterm.txt", "r");
6)
char* strcpy(char* s, const char* t){
  char* p = s;

  while(*t != '0'){
    *s = *t;
    s++;
    t++;
  }

  *p ='\0';
  return p;
}
7)
char* strncat(char* s, const char* t, size_t n){
  char* p = s + strlen(s);

  while(*t != '\0' && n--){ *p++ = *t++}

  *p = '\0'

  return s;
}
8)
int strcmp(const char* s, const char* t){
  const char* p = s;
  const char* v = t;

  while(*p != '\0'){
    if(*v == '\0'){ return 1;}
    else if(*p < *v){ return -1;}
    else if(*p > *v){ return 1};
    p++;
    v++;
  }
  if(*v != '\0'){ return -1;}

  return 0;
}
9)
//------ POINT ----------------------------------------------------------------
typedef struct point point;
struct point { double x, y; };
//------ SQUARE -----------------------------------------------------------------
typedef struct square square;
struct square { point ul; size_t side; };

square* square_init(double ulx, double uly, double side); // TODO
void square_delete(square* sq); // TODO
void square_move(square* sq, double x, double y); // TODO
void square_expandby(square* sq, double expandby); // TODO
double square_area(square* sq); // TODO
double square_perimeter(square* r); // TODO
// print location, side, area and perimeter
void square_print(const char* msg, square* sq); // TODO

square* square_init(double ulx, double uly, double side){
  square* sq = (square*)malloc(sizeof(square));
  sq->ul.x = ulx;
  sq->ul.y = uly;
  sq->side = side;
  return sq;
}
void square_delete(square* sq){
  free(sq);
}
void square_move(square* sq, double x, double y){
  sq->ul.x += x;
  sq->ul.y += y;
}
void square_expandby(square* sq, double expandby){
  sq->side += expandby;
}
double square_area(square* sq){
  return ((double)(sq->side) * (double)(sq->side));
}
double square_perimeter(square* r){
  return (4.0 * (double)(r->side));
}
void square_print(const char* msg, square* sq){
  const char* s = msg;
  sprintf(s, "The square is located at (%f, %f), the side length is %f, the area is %f, and the perimeter is %f\n",sq->ul.x, sq->ul.y, sq->side, square_area(sq), square_perimeter(sq));
  printf("%s",s);
}
void test_square(double ulx, double uly, double side) {
 square* sq = square_init(ulx, uly, side);
 square_print("sq is: ", sq);
 square_move(sq, 2, 2);
 square_print("sq is now: ", sq);
 square_expandby(sq, 10);
 square_print("sq has expanded to: ", sq);
 square_delete(sq);
 printf("\n\n");
}
void tests_square() {
 test_square(0, 0, 10);
 test_square(1, 1, 5);
 // add other tests if you wish // TODO (optional)
}
int main(int argc, const char* argv[]) {
 tests_square();
 return 0;
}
