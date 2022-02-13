// a file with all the art

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// source: https://textart.io/art/tag/duck/1
// by hjw
// void printDuck(){
	
// 	cout << "    __  \n";
// 	cout << "___( o)>\n";
// 	cout << "\\ <_. ) \n";
// 	cout << " `---'   hjw  \n";
// 	cout << "____________________________________________________________\n";
// }

// // source: http://www.ascii-art.de/ascii/c/chicken.txt
// // by Neil Smith
// // To Do: fix '\'
// void printChicken(){
// 	cout << "                                                  //    \n";
// 	cout << "                                                 <o)    \n";
// 	cout << "                                                 (\\\\_//\n ";
// 	cout << "                                                 (_\\_/  \n";
// 	cout << "                                                  _|_   \n";
// 	cout << "____________________________________________________________\n";
// }

// void printDuckAndChicken(){
// 	cout << "                                                  //        \n";
// 	cout << "    __                                           <o)        \n";
// 	cout << "___( o)>                                         (\\\\_//     \n";
// 	cout << "\\ <_. )                                          (_\\_/      \n";
// 	cout << " `---'   hjw                                      _|_       \n";
// 	cout << "____________________________________________________________\n";
// }

string repeteString(string str, int n){
	string result;
	for (int i=0; i<n; i++){
		result += str;
	}
	return result;
}

// a general function that can print Duckeggs, Ducks, chicken, and chicken eggs.
// In progress
void printFeild(int duckEggs, int ducks, int chickens, int chickenEggs){
	assert((duckEggs + ducks <= 3) && (chickenEggs + chickens <= 3));

	const int n = 6; // Height
	const int WIDTH = 80;
	const string DUCK[n] = {
		"            ",
		"    __      ",
		"___( o)>    ",
		"\\ <_. )    ",
		" `---'   hjw",
		"____________",
	};
	const string CHICKEN[n] = {
		" //     ",
		"<o)     ",
		"(\\\\_//",
		" (_\\_/ ",
		" _|_    ",
		"________",
	};
	const string EGG[n] = {
		"  _--_  ",
		" /    \\",
		"|      |",
		" \\____/",
		"        ",
		"________",
	};

	const string EMPTY[n] = {
		" ",
		" ",
		" ",
		" ",
		" ",
		"_",
	};

	// cout line by line
	for (int i = 0; i < n; i++){
		int width = 0;
		string duckEggsStr = repeteString(EGG[i], duckEggs);
		width += 8 * duckEggs;

		string ducksStr = repeteString(DUCK[i], ducks);
		width += 12 * ducks;

		string chickensStr = repeteString(CHICKEN[i], chickens);
		width += 8 * chickens;
		
		string chickenEggsStr = repeteString(EGG[i], chickenEggs);
		width += 8 * chickenEggs;

		string middle = repeteString(EMPTY[i] , WIDTH - width);

		cout << duckEggsStr << ducksStr << middle << chickensStr << chickenEggsStr << endl;
	}
}

void printDuckQuack(){
	cout << "           ,-.\n";
	cout << "       ,--' ~.).\n";
	cout << "     ,'         `.\n";
	cout << "    ; (((__   __)))        *QUACK*\n";
	cout << "    ;  ( (#) ( (#)             *QUACK*\n";
	cout << "    |   \\\\_/___\\\\_/|           *QUACK*\n";
	cout << "   ,\\\"  ,-'    `__\\\".\n";
	cout << "  (   ( ._   ____`.)--._        _\n";
	cout << "   `._ `-.`-' \\\\(`-'  _  `-. _,-' `-/`.\n";
	cout << "    ,')   `.`._))  ,' `.   `.  ,','  ;\n";
	cout << "  .'  .     `--'  /     ).   `.      ;\n";
	cout << " ;     `-        /     '  )         ;\n";
	cout << " \\                       ')       ,'\n";
	cout << "  \\                     ,'       ;\n";
	cout << "   \\               `~~~'       ,'\n";
	cout << "    `.                      _,'\n";
	cout << "hjw   `.                ,--'\n";
	cout << "        `-._________,--'\n";
}

void printDuckPeck(){
	cout << "";
	cout << "                                   ___\n";
	cout << "                               ,-\"\"   `.\n";
	cout << "          PECK!              ,'  _   e )`-._\n";
	cout << "          PECK!             /  ,' `-._<.===-'\n";
	cout << "          PECK!            /  /\n";
	cout << "                          /  ;\n";
	cout << "              _.--.__    /   ;\n";
	cout << " (`._    _.-\"\"       \"--'    |\n";
	cout << " <_  `-\"\"                     \\\n";
	cout << "  <`-                          :\n";
	cout << "   (__   <__.                  ;\n";
	cout << "     `-.   '-.__.      _.'    /\n";
	cout << "        \\      `-.__,-'    _,'\n";
	cout << "         `._    ,    /__,-'\n";
	cout << "            \"\"._\\__,'< <____\n";
	cout << "                 | |  `----.`.\n";
	cout << "                 | |        \\ `.\n";
	cout << "                 ; |___      \\-``\n";
	cout << "                 \\   --<\n";
	cout << "                  `.`.<\n";
	cout << "             hjw    `-'\n";
}

void printDuckDefend(){
	cout << "";
	cout << "                                    _\n";
	cout << "                                ,-\"\" \"\".\n";
	cout << "                              ,'  ____  `.\n";
	cout << "                            ,'  ,'    `.  `._\\\n";
	cout << "   (`.         _..--.._   ,'  ,'        \\    \n";
	cout << "  (`-.\\    .-\"\"        \"\"'   /          (  d _b\n";
	cout << " (`._  `-\"\" ,._             (            `-(   \\\n";
	cout << " <_  `     (  <`<            \\              `-._\\\n";
	cout << "  <`-       (__< <           :\n";
	cout << "   (__        (_<_<          ;\n";
	cout << "     `-.   '-.__.      _.'    /          DEFENSE!\n";
	cout << "        \\      `-.__,-'    _,'          DEFENSE!\n";
	cout << "         `._    ,    /__,-'              DEFENSE!\n";
	cout << "            \"\"._\\__,'< <____\n";
	cout << "                 | |  `----.`.\n";
	cout << "                 | |        \\ `.\n";
	cout << "                 ; |___      \\-``\n";
	cout << "                 \\   --<\n";
	cout << "                  `.`.<\n";
	cout << "                    `-''\n";
}

void printDuckLay(){
	cout << "                                   ___\n";
	cout << "                               ,-\"\"   `.\n";
	cout << "                             ,'  _   e )`-._\n";
	cout << "      PLOP!                 /  ,' `-._<.===-'\n";
	cout << "      AN EGG!              /  /\n";
	cout << "                          /  ;\n";
	cout << "              _.--.__    /   ;\n";
	cout << " (`._    _.-\"\"       \"--'    |\n";
	cout << " <_  `-\"\"                     \\n";
	cout << "  <`-                          :\n";
	cout << "   (__   <__.                  ;\n";
	cout << "     `-.   '-.__.      _.'    /\n";
	cout << "        \\      `-.__,-'    _,'\n";
	cout << "         `._    ,    /__,-'\n";
	cout << "            \"\"._\\__,'< <____\n";
	cout << "                 | |  `----.`.\n";
	cout << "     _--_        | |        \\ `.\n";
	cout << "    /    \\       ; |___      \\-``\n";
	cout << "   |      |      \\   --<\n";
	cout << "    \\____/        `.`.<\n";
	cout << "             hjw    `-''\n";
}

void printChickenPeck(){
	cout << "";
	cout << "      ,~.\n";
	cout << "   ,-'__ `-,\n";
	cout << "  {,-'  `. }              ,')\n";
	cout << " ,( a )   `-.__         ,',')~,\n";
	cout << "<=.) (         `-.__,==' ' ' '}\n";
	cout << "  (   )                      /)\n";
	cout << "   `-'\\   ,                    )\n";
	cout << "       |  \\        `~.        /\n";
	cout << "       \\   `._        \\      /\n";
	cout << "        \\     `._____,'    ,'\n";
	cout << "  PECK!  `-.             ,'\n";
	cout << "  PECK!     `-._     _,-'\n";
	cout << "  PECK!         77jj'\n";
	cout << "               //_||\n";
	cout << "            __//--'/`          hjw\n";
}

void printChickenCoot(){
	cout << "         COT   cot COOOT!\n";
	cout << "     cot ,,    ___\n";
	cout << "   COT'.>' \\_/'--.'\n";
	cout << "        \"( (( -'/<\n";
	cout << "          \\  _- /\n";
	cout << "       mrf )/ )/\n";
	cout << "         -((-((---\n";
}

void printChickenDefend(){
	cout << "	                   /    \n";
	cout << " ww_          ___.///      \n";
	cout << "o__ `._.-'''''    //       \n";
	cout << "|/  \\   ,     /   //       \n";
	cout << "     \\  ``,,,' _//         \n";
	cout << "      `-.  \\--'            \n";
	cout << "DEFENSE! \\_/_/            \n";
	cout << "DEFENSE!  \\\\\\\\             \n";
	cout << "DEFENSE! ,,','` AsH        \n";
}

void printChickenLay(){
	cout << "               xx\n";
	cout << "  PLOP!       / .|_\n";
	cout << "  AN EGG!    /(_)_<\n";
	cout << "            /  (\n";
	cout << "   ((____.-'    )\n";
	cout << "    \\\\         /\n";
	cout << "     \\'-.-.-'`/    -Miss.Kitty-\n";
	cout << "   _  \\______/\n";
	cout << "  (_)   _|_\\_\n";
	cout << "  ''''''''''''''''\n";
}

