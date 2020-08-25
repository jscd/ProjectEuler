#![feature(test)]

use std::collections::HashSet;
use std::convert::TryInto;

extern crate test;

fn main() {
    let mut pandigitals: HashSet<u64> = HashSet::new();
    // let mut blacklist: HashSet<u64> = HashSet::new();

    let mut counter = 0;

    let mut test = 1;
   	for v in 1..9 {
   		let a = test;
   		let a_digits = (a as f64).log10().floor() as u64 + 1;
   		let b_digits = (8.0 - (a as f64).log10().floor()) as u64;
   		println!("{} {}", a_digits, b_digits);
   		test *= 10;
   	}
    
    println!("{}", counter);
}

// returns true if can pass, otherwise false and digits
// can pass is determined if it has a repeat digit,
// a zero, or more than 9 total digits
fn easy_pass(num: u64) -> bool {
	let mut num = num;

	let mut digits = [0; 10];

	while num > 0 {
		let digit: usize = (num % 10).try_into().unwrap();

		if digit == 0 { return (true); }
		if digits[digit] == 1 { return (true); }

		digits[digit] = 1;
		num /= 10;
	}

	false
}

// String ver: 3,159,849 ns/iter (+/- 415,603)
// Math ver: 188,818 ns/iter (+/- 14,602)
fn is_pandigital_9(a: u64, b: u64, prod: u64) -> bool {
	fn get_act(digit: u64) -> u64 {
		match digit {
			1 => 1,
			2 => 20,
			3 => 300,
			4 => 4000,
			5 => 50000,
			6 => 600000,
			7 => 7000000,
			8 => 80000000,
			9 => 900000000,
			_ => 1000000000,
		}
	}

	fn get_n(num: u64) -> u64 {
		let mut sum = 0;
		let mut num = num;

		while num > 0 {
			sum += get_act(num % 10);
			num /= 10;
		}

		sum
	}

	let mut new_num = 0;
	new_num += get_n(a);
	new_num += get_n(b);
	new_num += get_n(prod);
	let new_num = new_num;


	if new_num != 987654321 {
		false
	} else { 
		println!("{} * {} = {}", a, b, prod);
		true 
	}
}


#[cfg(test)]
mod tests {
	use super::*;
	use test::Bencher;

	#[test]
	fn it_works() {
		assert!(is_pandigital_9(12, 34, 56789));
		assert!(is_pandigital_9(13, 24, 98765));

		assert!(!is_pandigital_9(12, 34, 5678));
		assert!(!is_pandigital_9(12, 34, 3009));
		assert!(!is_pandigital_9(12, 34, 56788));
		assert!(is_pandigital_9(39, 186, 39*186));

		let mut counter = 0;
		for a in 1..1000 {
	   		for b in 1..1000 {
	   			if is_pandigital_9(a, b, 123456) { counter += 1; }
	   		}
	   	}
	   	assert_eq!(12, counter);
	}



	#[bench]
	fn bench_is_pandigital_9(b: &mut Bencher) {
		b.iter(|| {
			test::black_box(test_lots())
		});
	}

	fn test_lots() -> u64 {
		let mut counter = 0;
		for a in 1..100 {
	   		for b in 1..100 {
	   			if is_pandigital_9(a, b, 123456) { counter += 1; }
	   		}
	   	}

	   	counter
	}

}
