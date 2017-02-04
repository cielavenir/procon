#include <string>
void test(const std::string &input, const std::string &expect);
void testloader(){ //insert test cases here
/*0*/ test( "AvEx", "305027");
/*1*/ test( "A", "112344");
/*2*/ test( "C", "241413");
/*3*/ test( "F", "134214");
/*4*/ test( "u", "236067");
/*5*/ test( "w", "732050");
/*6*/ test( "y", "414213");
/*7*/ test( "yx", "732050");
/*8*/ test( "ux", "236067");
/*9*/ test( "EF", "131424");
/*10*/ test( "DF", "134124");
/*11*/ test( "Au", "055165");
/*12*/ test( "uA", "023667");
/*13*/ test( "By", "234114");
/*14*/ test( "yB", "114342");
/*15*/ test( "yBy", "357020");
/*16*/ test( "yByB", "350072");
/*17*/ test( "AuBvCw", "131244");
/*18*/ test( "FAuFBvFCw", "300527");
/*19*/ test( "AuBv", "112344");
/*20*/ test( "CwDx", "515056");
/*21*/ test( "FzyE", "324114");
/*22*/ test( "uAwDyB", "114324");
/*23*/ test( "zExCvF", "073520");
/*24*/ test( "uFxEv", "002357");
/*25*/ test( "DyCwB", "076362");
}
