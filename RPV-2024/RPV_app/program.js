import { lex_compare, power } from './standartLib.js';


function sum(one, two) {
	return one + two;
}

(function () {
	let a = 0;
	for (a; a <= 4; a = a + 1) {
		console.log(a);
	}

	let b;
	b = 11;
	if (b >= 3) {
		console.log("number b >= 3");
	}

	if (b <= 4) {
		console.log("number b <= 4");
	}

	if (b == 11) {
		console.log("number b == 11");
	}

	console.log(a);
	console.log(b);
	console.log(sum(a, b));
	let b3;
	b3 = power(b, 3);
	console.log(b3);
	let no = -18;
	let nd = -1849;
	let c = 18;
	let d = 1849;
	let s1;
	s1 = "ffss";
	let s2;
	s2 = "ffssss";
	let for_s;
	for_s = lex_compare(s1, s2);
	console.log(for_s);
	let g = 4 + sum(a, b);
	console.log(g);
	let symb;
	symb = 'd';
	console.log(symb);
})();
