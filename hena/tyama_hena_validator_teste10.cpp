#include <string>
void test(const std::string &input, const std::string &expect);
void testloader(){ //insert test cases here
/*0*/ test("X", "5");
/*1*/ test("O", "4");
/*2*/ test("XX", "5");
/*3*/ test("OX", "10");
/*4*/ test("XO", "9");
/*5*/ test("XOO", "17");
/*6*/ test("OXX", "21");
/*7*/ test("OXO", "18");
/*8*/ test("OOOX", "130");
/*9*/ test("OXXO", "29");
/*10*/ test("XXOX", "81");
/*11*/ test("XOXXO", "89");
/*12*/ test("OOOOX", "630");
/*13*/ test("OXOOO", "66");
/*14*/ test("OXOXOX", "2001");
/*15*/ test("OXOXXO", "417");
/*16*/ test("OXXOXX", "1601");
/*17*/ test("XXXOXOO", "345");
/*18*/ test("OOOOOXO", "3258");
/*19*/ test("OXXOXXX", "6401");
}
