#!/usr/bin/env dart
import 'dart:io';
import 'dart:math';

void main() {
	for(;;){
		String enemy1 = stdin.readLineSync(); // name of enemy 1
		int dist1 = int.parse(stdin.readLineSync()); // distance to enemy 1
		String enemy2 = stdin.readLineSync(); // name of enemy 2
		int dist2 = int.parse(stdin.readLineSync()); // distance to enemy 2

		print(dist1<dist2 ? enemy1 : enemy2);
	}
}