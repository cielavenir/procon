#include <string>
void test(const std::string &input, const std::string &expect);
void testloader(){ //insert test cases here
/*0*/ test("xxoxo,oooxo", "2,2,3,4,5,1,1,3,4,5");
/*1*/ test("ooxxo,ooxxo", "1,1,2,2,5,3,3,4,4,5|3,3,4,4,5,1,1,2,2,5");
/*2*/ test("oxoxo,oxoxo", "1,2,3,4,5,1,2,3,4,5");
/*3*/ test("ooxoxx,oxxoxo", "1,3,4,5,6,6,1,2,2,3,4,5");
/*4*/ test("ooxxxx,ooxxoo", "1,1,2,2,6,6,3,3,4,4,5,5|3,3,4,4,6,6,1,1,2,2,5,5");
/*5*/ test("oxoxox,oxoxox", "1,2,3,4,5,6,1,2,3,4,5,6");
/*6*/ test("oxoxxxo,oxoxooo", "1,2,3,4,6,6,7,1,2,3,4,5,5,7");
/*7*/ test("oxooxxx,oxxoooo", "1,2,3,3,4,6,6,1,2,4,5,5,7,7");
/*8*/ test("oxoxxxo,oxoooxo", "1,2,3,4,4,6,7,1,2,3,5,5,6,7");
/*9*/ test("oxoxooox,oxoxoxxx", "1,2,3,4,5,7,7,8,1,2,3,4,5,6,6,8");
/*10*/ test("ooxoxxox,ooxxxoox", "3,3,4,5,6,6,7,8,1,1,2,2,4,5,7,8");
/*11*/ test("oxoxxxxx,oxoxoooo", "1,2,3,4,6,6,8,8,1,2,3,4,5,5,7,7");
/*12*/ test("oxoxooxxo,oxooxxoxo", "1,2,5,6,7,7,8,8,9,1,2,3,3,4,4,5,6,9");
/*13*/ test("oxoooooxo,oxxxoxxxo", "1,2,3,3,5,7,7,8,9,1,2,4,4,5,6,6,8,9");
/*14*/ test("oxoxoxxox,oxoxooxoo", "1,2,3,4,5,6,6,7,8,1,2,3,4,5,7,8,9,9");
/*15*/ test("oooxxxxoxo,xxooooxoxx", "1,1,3,4,4,6,6,7,8,9,2,2,3,5,5,7,8,9,10,10");
/*16*/ test("ooooxxxoxx,xxooxxxooo", "1,1,5,5,6,8,8,9,10,10,2,2,3,3,4,4,6,7,7,9");
/*17*/ test("xoxxoxxoxo,ooxoooxoxx", "2,3,4,4,5,6,6,7,8,9,1,1,2,3,5,7,8,9,10,10");
/*18*/ test("oxooxxoooxo,oxxxoxooxxo", "1,2,3,3,4,4,5,5,7,8,11,1,2,6,6,7,8,9,9,10,10,11");
/*19*/ test("oooxxxxoxoo,xxooooxooxx", "1,1,3,4,4,6,6,7,8,11,11,2,2,3,5,5,7,8,9,9,10,10");
/*20*/ test("ooooxxoxoxo,oxxxxooxoxo", "1,3,3,5,6,6,7,8,9,10,11,1,2,2,4,4,5,7,8,9,10,11");
/*21*/ test("ooooxoxooxox,xxoxxoxoxxox", "1,1,3,5,6,7,8,9,9,10,11,12,2,2,3,4,4,5,6,7,8,10,11,12");
/*22*/ test("ooxxoooooxox,ooxxoxxxxxox", "1,1,2,2,5,7,7,9,9,10,11,12,3,3,4,4,5,6,6,8,8,10,11,12|3,3,4,4,5,7,7,9,9,10,11,12,1,1,2,2,5,6,6,8,8,10,11,12");
/*23*/ test("xoxoxxooxoxx,ooxoxoxooxxo", "2,3,4,5,6,6,7,7,8,11,12,12,1,1,2,3,4,5,8,9,9,10,10,11|2,3,4,5,6,8,9,9,10,11,12,12,1,1,2,3,4,5,6,7,7,8,10,11");
/*24*/ test("oooooooooooo,xxxxxxxxxxxx", "1,1,3,3,5,5,7,7,9,9,11,11,2,2,4,4,6,6,8,8,10,10,12,12");
}
